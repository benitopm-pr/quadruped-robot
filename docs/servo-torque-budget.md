# Servo Torque Budget

## Servo specs (from manufacturer listing — no formal datasheet, China-sourced)
- Model: 25kg digital servo (no model number given by seller)
- Stall torque: ~25 kg·cm @ 6.0V, ~20–22 kg·cm @ 4.8V
- Rated voltage: 4.8V – 6.6V
- Speed: ~0.16–0.18 sec/60° @ 6.0V
- Rotation range: ~180° (not continuous)
- Weight: ~60–65 g
- Gear material: metal
- Control: standard PWM, driven via PCA9685

## Leg torque estimate
- Hip joint: <your call — see earlier question on which is more load-critical>
- Knee joint: <your call — see earlier question on which is more load-critical>
- Lever arm length:

## Lower leg segment

$$
L_{\text{lower}} = k_{\text{lower}} \cdot H_{\text{body}}
$$

Where:
- H_body = 280 mm
- k_lower = 0.33

*Note: k_lower was estimated by comparing segment lengths directly —
the lower segment (elbow → paw) was judged to be about half the length
of the upper segment (shoulder → elbow) in the reference proportions.
With lower:upper ≈ 1:2, lower segment ≈ 1/3 of total leg length.*

$$
L_{\text{lower}} = 92.4 \text{ mm}
$$

## Upper leg segment

$$
L_{\text{upper}} = k_{\text{upper}} \cdot H_{\text{body}}
$$

Where:
- H_body = 280 mm
- k_upper = 0.67

*Note: derived from the same lower:upper ≈ 1:2 ratio — upper segment
≈ 2/3 of total leg length.*

$$
L_{\text{upper}} = 187.6 \text{ mm}
$$

- Estimated load (segment + foot + margin): <depends on materials/scale you haven't picked yet>
- Safety margin applied to stall torque: 60%. Since teh servos are for hobbies but barely used with metal gear, i can use more tahn average servo hobbyist project.
- Torque required = force × lever arm = <blocked on Phase 2 load estimate>

## Verdict
<Compare your required torque against stall torque × your safety
margin — not the raw 25 kg·cm. Note there's no torque-speed curve
available for this servo since there's no real datasheet — the
20-22 vs 25 kg·cm spread at 4.8V vs 6.0V is the only speed/torque
tradeoff data the manufacturer gives you.>

## Revisit if
<e.g. actual leg mass or dimensions change once mechanical design
is finalized, or you find the safety margin was too optimistic
after testing>