# plot.py - plots the step response from sim.csv
# usage: python plot.py

import matplotlib.pyplot as plt

TARGET = 1.0  # same target as main.c

t, angle, torque = [], [], []

with open("sim.csv") as f:
    for line in f:
        parts = [p.strip() for p in line.split(",")]
        if not parts[0].isdigit():   # skip header / blank lines
            continue
        t.append(int(parts[0]))           # tick = ms
        angle.append(float(parts[1]))     # rad
        torque.append(float(parts[3]))    # N*m

fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True, figsize=(8, 6))

# top: where the motor is vs where we want it
ax1.plot(t, angle, label="angle")
ax1.axhline(TARGET, linestyle="--", color="gray", label="target")
ax1.set_ylabel("angle (rad)")
ax1.legend()

# bottom: what the controller asked for
ax2.plot(t, torque, color="tab:orange")
ax2.set_ylabel("torque (N*m)")
ax2.set_xlabel("time (ms)")

fig.suptitle("motor-pd step response")
fig.tight_layout()
fig.savefig("step_response.png", dpi=120)
print("saved step_response.png")
