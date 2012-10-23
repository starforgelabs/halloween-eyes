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

#include "Arduino.h"
#include "tape_player.h"

class TapePlayer;

class Process
{
  private:
  enum State {psSleeping, psRunning, psSuspended};
  typedef unsigned long Time;

  public:
  Process(); 
  
  // Run once in the setup() section. 
  void configure(byte aPin, Tape* aCatalogue, byte aCount);
  void execute();
  void hibernate(unsigned long aMilliseconds);
  
  private:
  State state;
  Time wakeTime;
  TapePlayer player;
  
  private:
  bool tryWaking();
};

#endif//PROCESS_H
