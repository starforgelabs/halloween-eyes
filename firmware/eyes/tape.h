/*
* Copyright 2012 James Knowles. 
*
* This work is licensed under a Creative Commons
* Attribution-ShareAlike 3.0 Unported License.
*
* https://creativecommons.org/licenses/by-sa/3.0/
*
* This code is strictly "as is". Use at your own risk.
*
*/

#ifndef TAPE_H
#define TAPE_H

#include "Arduino.h" 

struct TapeStep
{
  bool lightOn;
  long minDelay;
  long maxDelay;
};

class Tape
{
  public:
  Tape(TapeStep* aTapeStrip, byte aLength)
  {
    strip = aTapeStrip;
    count = aLength;
  }
  
  public:
  TapeStep* strip;
  byte count;
};

#endif//TAPE_H

