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

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Arduino.h"
#include "process.h"

typedef int8_t ProcessIndex;

class Scheduler
{
  public:
  Scheduler(Process* aProcessList, byte aProcessCount);
  
  void run();
  
  private:
  ProcessIndex selectNextProcess();
  
  // Currently-running process
  ProcessIndex  current;
  // Array of processes available to run 
  Process* processes;
  // Number of processes in the array
  byte count;
  
};

#endif//SCHEDULER_H
