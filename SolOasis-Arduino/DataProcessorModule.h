/*
 * DataProcessorModule.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Allen, Chris
 */

#ifndef _DATA_PROCESSOR_MODULE_H_
#define _DATA_PROCESSOR_MODULE_H_

#include "Globals.h"
#include "SystemStructs.h"
#include "InputModule.h"

#ifdef DEBUG
#include "Debug.h"
#endif

class DataProcessorModule {
private:
	InputModule* inputModulePtr;
	long long lastUpdateTime;
	double energy;
	double avgCurr;
	double avgVolt;
#ifdef DEBUG
	Debug debug;
#endif

public:
	DataProcessorModule();
	~DataProcessorModule();
	double GetAvgPower();
	double GetCurrentPower();
	double GetEnergy();
	double GetAvgVoltage();
	double GetAvgCurrent();
	void Update();
};


#endif /* _DATA_PROCESSOR_MODULE_H_ */
