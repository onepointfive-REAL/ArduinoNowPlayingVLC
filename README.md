# ArduinoNowPlayingVLC
Shows currently playing songs/video names from VLC

⚠️ **Note.1:** This project requires Python to be installed and added to your system's PATH.
⚠️ **Note.2:** This project requires Arduino IDE to be installed
⚠️ **Note.3:** This project requires VLC to be installed (duh)

How to run:
1. Go to [Projects](https://github.com/onepointfive-REAL/ArduinoNowPlayingVLC/releases) page and download `main.py`, `ArduinoNowPlayingVLC.ino` and `installlib.bat`
2. Open the Arduino IDE and open `ArduinoNowPlayingVLC.ino`. If it asks to make a directory, click OK
3. Upload the sketch to your Arduino of choice
4. If you haven't already connected a display to your Arduino, do so now.
5. Run `installlib.bat`
6. Run `main.py`

https://github.com/user-attachments/assets/914c872c-e947-4ceb-8a8c-40619fda4ab5

https://github.com/user-attachments/assets/f05ed431-ec28-46c1-8680-e16b788341ad

# Q&A

1:

**Q:** The Arduino showed me a link. What do I do here?  

**A:** Go to the [Projects](https://github.com/onepointfive-REAL/ArduinoNowPlayingVLC/releases) page and download the latest version. Then run `installlib.bat`, followed by `main.py` (requires Python)

2:

**Q:** The program starts then immediately exits. What do I do?

**A:** Check if you set the COM port correctly and nothing is using the COM port.

3:

**Q:** The program just says `VLC Offline` and does nothing else

**A:** Check if you configured the password properly on both VLC and the Python script.
e
