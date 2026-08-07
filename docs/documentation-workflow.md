# Documentation Workflow — Quadruped Robot

A quick-reference for where things get written down. Keep this file open (or pinned) until the habit sticks.

## The three systems, at a glance

| System | What goes here | When you write it | How long it lives |
|---|---|---|---|
| **`BUILD_LOG.md`** | What you did today, what you expected, what actually happened | End of every session, even a short one | Never edited after the fact — append only |
| **`docs/*.md`** | Why you made a call — a decision that affects more than one session | Once, when you make a real design decision | Living — revise if your thinking changes |
| **ClickUp task** | Current status + a link to whichever of the above explains it | When you open/close/update a task | Reflects "now" — points at current docs, doesn't duplicate them |

**One-line rule:** *when* → BUILD_LOG. *why* → docs/. *status right now* → ClickUp.

---

## 1. `BUILD_LOG.md` — the session log

Add a new entry every time you sit down and do something, even if it's a five-minute test. Bottom of the file, chronological order.

```markdown
## YYYY-MM-DD
**Did:** <what you actually did — one line>
**Expected:** <what you thought would happen>
**Actual:** <what actually happened — especially if it didn't match>
**Next:** <what this points you to do next session>
```

If nothing surprising happened, still write it — a log that only records surprises is missing the baseline you'd need to notice when something *does* go wrong later.

To quickly start today's entry (PowerShell), from the repo root:
```powershell
Add-Content BUILD_LOG.md -Value @"

## $(Get-Date -Format "yyyy-MM-dd")
**Did:**
**Expected:**
**Actual:**
**Next:**
"@
```
(`Add-Content` appends to the end of the file, unlike `Set-Content` which overwrites — safe to run every session.)

---

## 2. `docs/*.md` — the decision record

Make a new file only when you make a decision you might question later — not for routine work. Ask: *"Would I want to re-read my reasoning on this in a month?"* If yes, it's a doc.

Name it after the decision: `docs/why-2dof-first.md`, `docs/why-steppers-before-dc.md`, `docs/why-raw-avr-registers.md`.

```markdown
# <Decision title>

<1–2 sentences: what was decided>

## Reasoning
<why — the actual argument, trade-offs considered>

## Revisit if
<the condition that would make you reconsider this>
```

Unlike the build log, you're allowed — expected — to come back and edit this if your thinking changes. It should always reflect your *current* best reasoning, not a frozen snapshot.

---

## 3. ClickUp task — status + pointer

Keep task descriptions short. Don't re-explain reasoning that already lives in `docs/` — link to it instead, so there's one source of truth.

```
<Task title>

Status: <backlog / designing / building / testing / done>
See docs/<relevant-file>.md for reasoning.
Related: BUILD_LOG.md, <date> entry
```

---

## Quick decision check

Ask yourself, right when you're about to write something down:

- **"I just did/tested something"** → `BUILD_LOG.md`
- **"I'm choosing between two approaches and want to remember why"** → new file in `docs/`
- **"I'm updating a task's status, or want to note where the reasoning lives"** → ClickUp

## Worked example

All three, for the same underlying decision (2-DOF vs 3-DOF leg):

**BUILD_LOG.md**
```markdown
## 2026-08-05
**Did:** Sketched first leg concept in FreeCAD, compared 2-DOF vs 3-DOF joint layout
**Expected:** 3-DOF would be more complex to draw but not by much
**Actual:** 3-DOF's hip-abduction joint made the FK math nonobvious
**Next:** Commit to 2-DOF for leg_test, revisit 3-DOF once FK is solid
```

**docs/why-2dof-first.md**
```markdown
# Why 2-DOF before 3-DOF

The real quadruped needs 3-DOF legs, but the first leg testbed uses only 2-DOF.

## Reasoning
2-DOF forward kinematics is two lines of trigonometry, derivable by hand.
Adding hip abduction turns it into a 3D problem — easy to get subtly
wrong. The testbed phase is about understanding the math, not a demo.

## Revisit if
2-DOF doesn't exercise the stepper limits I need to observe.
```

**ClickUp task**
```
Sketch 2-DOF leg concept in FreeCAD

Status: Done
See docs/why-2dof-first.md for reasoning.
Related: BUILD_LOG.md, 2026-08-05 entry
```
