#include <stdio.h>
#include <stdint.h> // Gives integer types with sizes like uint8_t
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>   // FIX: needed for _delay_us / _delay_ms
#include "usart.h"

#define PCA_addr 0x40   //Default address

//Servo calibration:
#define MIN_COUNT     73
#define CENTER_COUNT  310
#define MAX_COUNT     548
/*
1 ms  ≈ 205 counts
1.5 ms ≈ 307 counts
2 ms  ≈ 410 counts
*/

void twi_init(void){
    //TWI initialization
    TWSR=0X00; //Preescaler to 1
    TWBR=72;   //100KhZ @16MHz
}

uint8_t twi_start(void){
    //Start condition
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); //Send start condition. TWEN enables communication, TWSTA is for START, TWINT to clear the flag
    while (!(TWCR & (1<<TWINT)));           //Wait for TWINT flag set. This indicates that the START condition has been transmitted
    
    //Check if started
    uint8_t status_start = TWSR & 0xF8;      //0xF8 is a mask to keep status bits (7..3), remove prescaler bits
    return status_start;
}

uint8_t twi_write(uint8_t data){
    //Data phase
    TWDR = data;     //SLA+W
    TWCR = (1<<TWINT)|(1<<TWEN); 
    while (!(TWCR & (1<<TWINT)));   //Wait till' the flag indicates data was received   

    //Check return of the flag
    uint8_t status_wr = TWSR & 0xF8;       //Writes byte
    return status_wr;
}

void twi_Stop(void){
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN); //Send STOP condition.
    while (TWCR &(1<<TWSTO));               //Wait till stops
}

void set_sleep(void){
    printf("SLEEP\n");
    uint8_t status = twi_start();
    printf("TWSR = 0x%02X START\n", status);      

    status = twi_write((PCA_addr << 1) | 0); // Send address
    printf("ADDR = 0x%02X Write\n", status);      

    status = twi_write(0x00);               // Mode 1            
    printf("DATA = 0x%02X Write\n", status);

    status = twi_write(0x10);               // Sleeping (SLEEP = 1)           
    printf("DATA = 0x%02X Write\n", status);

    twi_Stop();
    printf("DONE\n");
}

void set_preescaler(void){
    set_sleep();
    printf("PREESCALER\n");
    uint8_t  status = twi_start();
    printf("TWSR = 0x%02X START\n", status);      

    status = twi_write((PCA_addr << 1) | 0);// Send address
    printf("ADDR = 0x%02X Write\n", status);      

    status = twi_write(0xFE);               // Preescaler        
    printf("DATA = 0x%02X Write.\n", status);

    status = twi_write(0x79);               // Preescaler set to 121 (50Hz)           
    printf("DATA = 0x%02X Write. Preescaler set\n", status);

    twi_Stop();
    printf("DONE\n");
}

void wake_up_conf(void){
    printf("WAKING UP...\n");
    uint8_t  status = twi_start();
    printf("TWSR = 0x%02X START\n", status);      

    status = twi_write((PCA_addr << 1) | 0); // Send address
    printf("ADDR = 0x%02X Write\n", status);      

    status = twi_write(0x00);               // Mode 1            
    printf("DATA = 0x%02X Write\n", status);

    status = twi_write(0xA1);               // FIX: RESTART=1, AI=1, SLEEP=0, ALLCALL=1
    printf("DATA = 0x%02X Write. Woke up and A.I. active\n", status);

    twi_Stop();
    printf("DONE\n");
    _delay_us(500); // Oscillator stabilization
}

void mode_2(void){
    uint8_t  status = twi_start();
    printf("TWSR = 0x%02X START\n", status);      

    status = twi_write((PCA_addr << 1) | 0); // Send address
    printf("ADDR = 0x%02X Write\n", status);      

    status = twi_write(0x01);               // Mode 2       
    printf("DATA = 0x%02X Write\n", status);

    status = twi_write(0x04);               // outdrv to 1 (totem-pole)       
    printf("DATA = 0x%02X Write. outdrv to 1\n", status);

    twi_Stop();
    printf("Stop\n");
}

void PCA_conf(void){
    printf("CONFIGURING PCA...\n");
    set_preescaler();
    wake_up_conf();
    mode_2();
    printf("PCA CONFIG DONE\n");
}

void motor_mov(uint16_t off_value){
    uint8_t status;
    // Servo motion
    status = twi_start();
    status = twi_write((PCA_addr << 1) | 0);   // SLA+W
    status = twi_write(0x06);                  // LED0_ON_L

    status = twi_write(0x00);                  // ON_L
    status = twi_write(0x00);                  // ON_H
    status = twi_write(off_value & 0xFF);      // OFF_L
    status = twi_write(off_value >> 8);        // OFF_H
    printf("Move done at %u. status:%02X\n",off_value ,status);      
    twi_Stop();
}

int main(void){
    uart_init();    //Initialize UART hardware
    io_redirect();  //Redirect stdin/stdout to UART
    twi_init();  
    PCA_conf();     // Preescaler selec, auto increment activ.

    uint16_t count=545;
    motor_mov(count); //Start in a safe direction

    while(1){
        //Getting the off count for servo
        printf("Choose off count: ");
        scanf("%u", &count);
        motor_mov(count);
        _delay_ms(20);
    }
} 


