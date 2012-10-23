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

#include "scheduler.h"

Scheduler::Scheduler(Process* aProcessList, byte aProcessCount)
{
  processes = aProcessList;
  count = aProcessCount;
  current = -1;
}

void Scheduler::run()
{
  selectNextProcess();
  processes[current].execute();
}

// This is a very simple round robin scheduler
ProcessIndex Scheduler::selectNextProcess()
{
  if(current < 0 || count == 1)
    return current = 0; 
    
  return current = (current+1) % count;
}
  

