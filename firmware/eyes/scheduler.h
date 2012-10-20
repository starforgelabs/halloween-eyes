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
