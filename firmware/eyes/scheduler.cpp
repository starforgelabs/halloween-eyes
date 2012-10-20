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
  

