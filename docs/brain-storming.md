# Brainstorming

Unfiltered idea capture — things worth remembering but not yet
decided on. When something here becomes a real decision, move the
reasoning into the relevant design doc (leg_design.md, etc.) and
either delete the entry here or leave it as "considered, not used."

---

## Power transmission

### Capstan drive (considered alternative for remote actuation)
Instead of a rigid mechanical linkage, power is transmitted from a
motor mounted near the body to the joint using a cable wrapped around
a drum (capstan), rather than gears or a four-bar linkage.

Advantages:
- Near-zero backlash compared to gear trains
- High transmission efficiency, low friction
- Some inherent compliance — can absorb shock from foot impact
- Lightweight at the joint (no gearbox needed distally)
- Fits the remote actuation goal already selected for this project

Disadvantages:
- Requires careful cable tensioning (too loose = slop, too tight =
  added friction/wear)
- Cable stretch/creep over time can introduce position drift
- Cable is a wear item, will need periodic replacement
- Routing constraints — cable bend radius limits mechanical layout
- Meaningfully more complex to prototype than direct-drive or a
  simple four-bar linkage

**Status:** not used for v1 (direct-drive selected for the first
testbed). Worth reconsidering for Phase 2+ once remote actuation is
implemented, as an alternative to the four-bar linkage originally
proposed.


### Differential capstan drive
Stepped dual-diameter drum on one shaft, single cable wound so it
pays out from one diameter while winding onto the other — net cable
displacement per rotation is the *difference* between the two
circumferences, giving high torque multiplication in a compact
package.

- Very high reduction ratio possible in small footprint
- Retains capstan advantages: low backlash, low friction, compliance
- Sensitive to manufacturing precision (advantage comes from a small
  diameter difference)
- Seen in research-grade prosthetic/robotic hand actuators
- Status: interesting, not needed for current leg design scope —
  revisit if a joint ever needs high torque in very limited space
  (e.g. ankle/foot mechanism)

---

## Ideas to revisit later
- <space for future entries>

## Discarded / not pursuing
- <space for things you looked into and ruled out, with a one-line why>


# References
[1] Aaed Musa, *High Precision Speed Reducer Using Rope*. https://www.youtube.com/watch?v=MwIBTbumd1Q