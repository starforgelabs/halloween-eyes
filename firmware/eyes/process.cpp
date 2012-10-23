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

Process::Process(byte aPin, Tape* aCatalogue, byte aCount)
{
  player.configure(this, aPin, aCatalogue, aCount); 
  resume();
}

bool Process::execute()
{
  if(!SCMProcess::execute()) return false;
  
  player.play();
  return true;
}

