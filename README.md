halloween-eyes
==============

I saw an idea of cutting eyes in toilet paper rolls, putting a glow stick in them, and setting them in the bushes.
This is intended to look like eyes of unknown creatures. 

I thought, why not go one better and give some life to the eyes using LEDs and an Arduino.

This is a glorified version of the basic "blink" program for the Arduino. 
It drives multiple LEDs independently using a simple multi-tasking core. 

Instructions
------------

* Connect LEDs to the digital outputs. 
* Update the firmware to include the correct number of LEDs and their pin numbers. 
* Compile and upload to the Arduino. 

Overview
------------

* The firmware uses simple a cooperative multitasking core to drive each LED independently. 
* Each process chooses a "tape" that it "plays" from a catalogue of tapes.
* The tapes contain instructions for turning the LEDs on/off with the ability to set random delays (in mS). 
* Set the min/max times to be the same for fixed delays. 

