# Leg design

## Define limbs proportions
Express the limb dimensions as a fraction of the body height for easier scaling and reasonable dimensions.

$$
L_{\text{segment}} = k \cdot H_{\text{body}}
$$

Where:
- L_segment = length of the limb segment (or L_limb for the entire limb)
- H_body = reference body height
- k = proportional constant (dimensionless)

Once the proportions are known, the physical constraints can be determined.

## Lower leg segment

$$
L_{\text{lower}} = k_{\text{lower}} \cdot H_{\text{body}}
$$

Where:
- H_body = 280 mm
- k_lower = 0.5

$$
L_{\text{lower}} = 140 \text{ mm}
$$

## Upper leg segment

$$
L_{\text{upper}} = k_{\text{upper}} \cdot H_{\text{body}}
$$

Where:
- H_body = 280 mm
- k_upper = 0.5

$$
L_{\text{upper}} = 140 \text{ mm}
$$

*Check: L_lower + L_upper = 140 + 140 = 280 mm = H_body — consistent
with the approximation that total leg length ≈ H_body.*

## Segment proportion — design rationale

Initial visual estimation from the Jack Russell Terrier reference
suggested upper:lower ≈ 2:1 (biologically-inspired asymmetry, common
in real canine anatomy). However, equal segment lengths (k = 0.5 for
both) were chosen instead, prioritizing engineering practicality over
strict biological fidelity:

- Simplifies leg kinematics — symmetric segments produce a more
  predictable, easier-to-derive foot workspace than asymmetric ones.
- Reduces risk of kinematic singularities or awkward folding
  configurations that can arise from uneven segment ratios.
- Matches common practice in real quadruped robots (e.g. MIT Mini
  Cheetah and several open-source designs use near-equal segment
  lengths for these same reasons).
- Biological proportions optimize for muscle/tendon anatomy, which
  doesn't directly translate to a servo-driven mechanical leg — the
  reference dog informed target *scale*, not necessarily segment
  *ratio*.

*Superseded: earlier version used k_lower = 0.33, k_upper = 0.67
(93 mm / 187 mm), based on the visual 2:1 biological ratio.*

## Actuator placement and power transmission
### Direct drive (Actuator per joint)
The actuator is placed directly in the joint it controls.

Advantages:
- Easy design
- Easier programming
- Minimal transmission loss

Disadvantages:
- Bulky design
- Motors exposed to impact
- High leg mass and inertia

### Remote actuation
The actuator is placed away from the joint, usually closer to the robot's body. Motion is transmitted using mechanical elements.

Advantages:
- Reduced leg mass
- Lower rotational inertia
- Allows larger actuators without increasing distal weight

Disadvantages:
- Increased mechanical complexity
- Transmission losses

## Mechanical linkage
In order to transmit power, a four-bar linkage was selected to actuate the leg.

## Selection of Actuation Architecture

Remote actuation was selected for the leg mechanism to reduce the mass located on the moving segments of the limb. By positioning the actuators closer to the main body structure, the distal mass and rotational inertia of the leg are reduced, allowing faster movement and lower torque requirements during acceleration and deceleration.

The main disadvantages of remote actuation are the increased mechanical complexity and additional transmission losses introduced by the power transmission system. However, for this project, the reduction in limb inertia and improved dynamic performance were considered more important design factors.

## Define actuators
Estimate the worst-case loading condition of the system. In this project, worst-case scenario would be complete extension of the limbs, since the force is applied at the end of the limb.

## Reference breed
A Jack Russell Terrier was used as the geometric reference for the robot's leg design. The breed's limb proportions and kinematic structure were adopted to determine the segment lengths, joint placement, and degrees of freedom of the robot.
| Parameter | Value |
|-----------|------:|
| Shoulder height | 254–300 mm |
| Body length | 460–550 mm |
| Standing height | 360–430 mm |


# References

[1] Asimov. *How We Built Humanoid Robot Legs*. YouTube. https://www.youtube.com/watch?v=wFUksEBPIA8

[2] UKC Dogs. *Jack Russell Terrier*. https://www.ukcdogs.com/jack-russell-terrier

[3] Dimensions.com. *Jack Russell Terrier Dimensions*. https://www.dimensions.com/element/jack-russell-terrier

