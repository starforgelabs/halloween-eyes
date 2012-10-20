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

