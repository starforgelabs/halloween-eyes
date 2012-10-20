#include "scheduler.h"

Scheduler::Scheduler(Process* aProcessList, byte aProcessCount)
{
  processes = aProcessList;
  count = aProcessCount;
  current = -1;
}

void Scheduler::initialize()
{
  for(int i=0; i<count; i++)
    processes[i].initialize();
}

void Scheduler::run()
{
  selectNextProcess();
//  Serial.print("Current Process ");
//  Serial.println(current);
  processes[current].execute();
}

ProcessIndex Scheduler::selectNextProcess()
{
  if(current < 0 || count == 1)
    return current = 0; 
    
  return current = (current+1) % count;
}
  

