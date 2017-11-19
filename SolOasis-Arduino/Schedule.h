/*
 * Schedule.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_

#include "Globals.h"
#include "SystemStructs.h"
#include "Ports.h"
#include "MCUCommModule.h"
#include "InputModule.h"
#include "DataProcessorModule.h"
#include "LCDDisplay.h"

#define EN_TIMER1

class Schedule{
private:
	InputModule in;
	LCDDisplay display;
	void TimerSetup();
public:
	Schedule();
	~Schedule();
	void SetupSchedule();
	void RunSchedule();
};

#endif /* _SCHEDULE_H_ */
