
# Gaming Room IoT Projects

A collection of projects to add functionality to my PC and RGB to my Gaming/ Study Room.

Items:

1. DIY Nano Leaf Panels

2. Electronics Control Panel

3. Stream Deck

Here is a picture of the final control and power board an the room with the items. 


![App Screenshot](https://i.ibb.co/nQVKzvr/Whats-App-Image-2022-04-07-at-12-25-22-AM.jpg)

![App Screenshot](https://i.ibb.co/5MNwDWk/Whats-App-Image-2022-04-07-at-12-25-22-AM-1.jpg)



## DIY Nano Leaf Panels

Made modular light panels using WS2812B addressable RGB led strips. Each triangle can be 
detached and connected in any order. 

The panels are controlled by a NodeMCU which has the ESP8266 WiFi controller.
The MCU is flashed to run WLED firmware, which through the WLED App, allows for 
wireless control of the leds (colors, patterns, etc).

The Leds are powered by a 5V 10A SMPS. 



![App Screenshot](https://i.ibb.co/CtB0b0K/Whats-App-Image-2022-04-07-at-12-29-28-AM.jpg)


## Electronics Control Module

Items Used:

1. Push Button Switches

2. 0.96'' Led Screen

3. Arduino Uno

4. Relay Module

The panel was made to have control of the lighting in a centralised location. 
The push buttons control various lights including the room lights, the Nano Leaf 
panels and also the PC.

An ardunio Uno contols the panel. A screen on the panels displays the status of 
the lights.

A relay module was used to be able to cut power the the room lights which use 240V AC.


![App Screenshot](https://i.ibb.co/r7BvCjD/Whats-App-Image-2022-04-07-at-12-28-33-AM.jpg)


## Stream Deck
The final project was a DIY stream deck sort of control panel that allowed for 
convinent function like muting the mic, deafening on discord, acting as a soundboard etc.

Items used:

1. Gateron Brown Mechanical Switches

2. Ardunio Pro Micro

3. Leds

An arduino pro micro was used as it can emulate a keyboard when connected to a computer.
The keys on the deck were programmed to function as function keys (F13 to F20), which
are normally not present on a standard keyboard. Thus, these keys can be used as hotkeys
to perform desired operation.

The housing for the switches and controller were 3D printed as the switches needed 
precision in placement and had to be tight so as to handle being pressed.

![App Screenshot](https://i.ibb.co/ZJV1DQR/b01d7643-1317-46eb-a2bf-e771ca11edc7-1.jpg)

