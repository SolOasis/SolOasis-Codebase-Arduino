/*
 * SolOasis-Arduino.cpp
 *
 *  	Version: 1.1 (Nov 14, 2017)
 *      Author: Allen, Chris
 */
#include <Arduino.h>
//#include "Globals.h"
//#include "SystemStructs.h"
#include "Schedule.h"
//#include "LCDDisplay.h"
//#include "Ports.h"
//#include "MCUCommModule.h"
//#include "InputModule.h"
//#include "DataProcessorModule.h"

#ifdef DEBUG
#include "Debug.h"
Debug debug;
#endif

//LCDDisplay* lcdDisplayPtr;
//DataProcessorModule* dataProcessPtr;
Schedule s;
void setup() {
//	SetupPorts();
//	SystemSetup();
//	lcdDisplayPtr = new LCDDisplay();
//	dataProcessPtr = new DataProcessorModule();
	s.SetupSchedule();
}

void loop() {
//
//	dataProcessPtr->Update();
//
//	lcdDisplayPtr->Display(dataProcessPtr->GetAvgCurrent(),
//			dataProcessPtr->GetAvgVoltage(),
//			dataProcessPtr->GetCurrentPower(),
//			dataProcessPtr->GetEnergy());

	s.RunSchedule();
}
