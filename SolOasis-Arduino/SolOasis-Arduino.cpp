/*
 * SolOasis-Arduino.cpp
 *
 *  	Version: 1.1 (Nov 14, 2017)
 *      Author: Allen, Chris
 */
#include <Arduino.h>
#include "Globals.h"
#include "SystemStructs.h"
#include "Schedule.h"
#include "LCDDisplay.h"
#include "Ports.h"

#include "DataProcessorModule.h"

#ifdef DEBUG
#include "Debug.h"
Debug debug;
#endif

LCDDisplay* lcdDisplayPtr;

DataProcessorModule* dataProcessPtr;
extern double energy = 0; //definition

void setup() {
	SetupPorts();
	SystemSetup();
	lcdDisplayPtr = new LCDDisplay();
	dataProcessPtr = new DataProcessorModule();
}

void loop() {

	dataProcessPtr->Update();

	lcdDisplayPtr->Display(dataProcessPtr->GetAvgCurrent(),
			dataProcessPtr->GetAvgVoltage(),
			dataProcessPtr->GetCurrentPower(),
			dataProcessPtr->GetEnergy());

#ifdef DEBUG
	debug.print("V: ");
	debug.print(dataProcessPtr->GetAvgVoltage());
	debug.print(" / I: ");
	debug.print(dataProcessPtr->GetAvgCurrent());
	debug.print(" / P:");
	debug.print(dataProcessPtr->GetAvgPower());
	debug.print(" / E:");
	debug.println(dataProcessPtr->GetEnergy());

	//debug.println(millis() - tmp_time);
#endif


}
