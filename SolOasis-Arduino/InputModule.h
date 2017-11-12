/*
 * InputModule.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#ifndef _INPUT_MODULE_H_
#define _INPUT_MODULE_H_

#include "Globals.h"
#include "SystemStructs.h"

#ifdef DEBUG
#include "Debug.h"
#endif

class InputModule{
private:
#ifdef DEBUG
	Debug debug;
#endif

public:
	InputModule();
	~InputModule();
	double GetPanelVoltage();
	double GetPanelCurrent();
	double GetBattVoltage();
	double GetBattCurrent();
	double GetConvVoltage();
	double GetConvCurrent();
};

#endif /* _INPUT_MODULE_H_ */
