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

#include <SCMProcess.h>
#include <SCMScheduler.h>

#include "process.h"
#include "tape.h"

////////////////////////////////////////////////////////////////////////////////
//
// Tapes with different eye behaviours
//
// Each step consists of LED on (true/false) and min/max random time.
//
////////////////////////////////////////////////////////////////////////////////
#define SILENCE_COUNT 1
TapeStep Silence[SILENCE_COUNT] = {false, 5000, 20000};

#define SIMPLE_OPEN_COUNT 2
TapeStep SimpleOpen[SIMPLE_OPEN_COUNT] = {{true, 500, 2000},{false, 2000, 10000}};

#define BLINK_OPEN_COUNT 6
TapeStep BlinkOpen[BLINK_OPEN_COUNT] = 
  {
    {true, 100, 100},
    {false, 100, 100},
    {true, 100, 100},
    {false, 100, 100},
    {true, 500, 2000},
    {false, 2000, 10000}
  };

#define BLINK_OPEN_BLINK_COUNT 10
TapeStep BlinkOpenBlink[BLINK_OPEN_BLINK_COUNT] = 
  {
    {true, 100, 100},
    {false, 100, 100},
    {true, 100, 100},
    {false, 100, 100},
    {true, 500, 2000},
    {false, 100, 100},
    {true, 100, 100},
    {false, 100, 100},
    {true, 100, 100},
    {false, 2000, 10000}
  };

// Catalogue of eye behaviours
// The first tape is the one that runs first.
#define CATALOGUE_COUNT 4
Tape Catalogue[CATALOGUE_COUNT] = 
  {
    Tape(Silence, SILENCE_COUNT),
    Tape(SimpleOpen, SIMPLE_OPEN_COUNT),
    Tape(BlinkOpen, BLINK_OPEN_COUNT),
    Tape(BlinkOpenBlink, BLINK_OPEN_BLINK_COUNT)
  };

////////////////////////////////////////////////////////////////////////////////
//
// Cooperative multitasking system
//
////////////////////////////////////////////////////////////////////////////////
#define PROCESS_COUNT 12
SCMProcess* processList[PROCESS_COUNT] = 
{
  new Process(2, Catalogue, CATALOGUE_COUNT), 
  new Process(3, Catalogue, CATALOGUE_COUNT), 
  new Process(4, Catalogue, CATALOGUE_COUNT), 
  new Process(5, Catalogue, CATALOGUE_COUNT), 
  new Process(6, Catalogue, CATALOGUE_COUNT), 
  new Process(7, Catalogue, CATALOGUE_COUNT), 
  new Process(8, Catalogue, CATALOGUE_COUNT), 
  new Process(9, Catalogue, CATALOGUE_COUNT), 
  new Process(10, Catalogue, CATALOGUE_COUNT), 
  new Process(11, Catalogue, CATALOGUE_COUNT), 
  new Process(12, Catalogue, CATALOGUE_COUNT)
  new Process(13, Catalogue, CATALOGUE_COUNT), 
};

SCMScheduler scheduler(processList, PROCESS_COUNT);

void setup()
{
  randomSeed(analogRead(0));
}

void loop()
{
  scheduler.run();
}

