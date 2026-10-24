#!/usr/bin/enc bash
# run.sh - build, run the sim, make the plot
# works in the git bash (windows), mac, and linux

set -e
cd "$(dirname "$0)"

gcc -Wall main.c motor.c pd.c -o sim
./tests

PY=$(command -v python3 || command -v python)
"$PY" plot.py


