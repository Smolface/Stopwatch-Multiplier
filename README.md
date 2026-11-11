# How to use Stopwatch Multiplier
Stopwatch Multiplier allows you to speed up and slow down time in your stopwatch, and it supports up to 10^100 seconds of storage!

Controls:
[e] Increases Speed
[c] Decreases Speed
[r] Resets Timer and speed
[SPACE] Pauses / Resumes Stopwatch.

If the controls are not working, make sure that your caps lock is off and that you are not holding shift, since the program only takes lowercase input.

# How to install (Windows)
Download Stopwatch_Multiplier.exe and it should launch a terminal window. All External libraries used are already bundled into the exe.

# How to install (Linux)
First, you need to install the <ncurses.h> external library for c++. This is required for the program since it uses this library to display elements in your terminal window. The following are install commands for different linux distros.

Ubuntu / Debian / Linux Mint / Pop!_OS
'''bash
sudo apt update
sudo apt install libncurses5-dev libncursesw5-dev
'''
