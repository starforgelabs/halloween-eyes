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

#include "Arduino.h"
#include "process.h"

Process::Process()
{ 
  state = psSuspended;
}

void Process::configure(byte aPin, Tape* aCatalogue, byte aCount)
{
  player.configure(this, aPin, aCatalogue, aCount); 
  state = psRunning;
}

void Process::execute()
{
  if(!tryWaking()) return;
  
  player.play();
}

void Process::hibernate(unsigned long aMilliseconds)
{
  wakeTime = millis() + aMilliseconds;
  state = psSleeping;
}

  
bool Process::tryWaking()
{
  if(state == psSuspended) return false;
  
  if(state == psSleeping && millis() >= wakeTime)
    state = psRunning;
        
  return state == psRunning;
}

