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
- Joint being budgeted (hip or knee): <your call — see earlier question on which is more load-critical>
- Lever arm length: <you need a rough leg sketch/dimension first — not yet available>
- Estimated load (segment + foot + margin): <depends on materials/scale you haven't picked yet>
- Safety margin applied to stall torque: <your reasoned fraction, not a lookup — think about duty cycle for a plastic-case hobby servo>
- Torque required = force × lever arm = <your calculation>

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