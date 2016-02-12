--- Contains ---

  mic.ino - Searches for peaks and subsequent valleys relative to an averaged baseline

  mic_v2.ino - Searches only for peaks relative to an averaged baseline


--- Versions ---

  mic_v2 works better than the original mic.ino, perhaps because I didn't calibrate the parameters enough in mic.ino or simply because of Occam's Razor. Also note that mic.ino only outputs the reading to the serial monitor and a dummy LED, while mic_v2.ino is setup to control a reel of RGB LEDs as shown at http://teacakeady.blogspot.com/2016/02/party-lights.html


--- Notes ---

  Both employ extremely rudimentary signal processing (if you can even call it that); as I am currently enrolled in JHU ECE Signals & Systems I hope there will soon be some more legit code in there.

