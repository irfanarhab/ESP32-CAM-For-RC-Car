Create your own surveillance bot controlled by an esp32-cam module
![WhatsApp Image 2024-02-15 at 14 10 37](https://github.com/irfanarhab/ESP32-CAM-For-RC-Car/assets/39016873/9e550d7c-8ae1-4ed3-90f1-ecd4693154f9)
![Skema](https://github.com/irfanarhab/ESP32-CAM-For-RC-Car/assets/39016873/2dcbcd52-d70c-40a4-866e-45343bb922cf)
this code is based on a default demo for the esp32-cam module, I extended the web interface with buttons to controll the rc-surveillance-car and the led, I also added modifications the C code.

Parts that I've used:

4 x motors (6V, 300rpm) with wheels

1 x esp32-cam module

1 x IC-motor driver L293d

1 x Ultrasonic Sensor HC-sr04

1 x Arduino Nano 

4 x Transistor BC547

2 x Led

some wires and usb to uart programmer 

this is a first working code (alpha version) i plan to improve and extend it soon, there is a fail safe stop, inplemented into the code, in case some connection issues, the car will stob after 500ms, you can change the value in the .ino file.

i have noticed that esp32-module doenst start sometimes properly when i connect power to it, so i have to disconnect the motor driver before i connect the power, without the motor driver the esp32 starts properly, after that i connect the power wire back to motor driver and everything works well, i think this depends on your power source (you could use two separate power sources for motor driver and esp32-cam module to fix this also adding some caps may fix this issue).

another issue that I have noticed is that I can't let the motors on left side rotate forward with the right side motors rotate backward and vice versa, it doesnt seem to work with esp32 cam module, but it works without it wery well, so any ideas are welcome.
