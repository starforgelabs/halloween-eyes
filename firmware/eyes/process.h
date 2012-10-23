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

#ifndef PROCESS_H
#define PROCESS_H

#include <SCMProcess.h>

#include "Arduino.h"
#include "tape_player.h"

class Process : public SCMProcess
{
  public:
  Process(byte aPin, Tape* aCatalogue, byte aCount);
  virtual bool execute();
  
  private:
  TapePlayer player;
};

#endif//PROCESS_H
