/*
 * MCUCommModule.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#ifndef _MCU_COMM_MODULE_H_
#define _MCU_COMM_MODULE_H_

#include "Globals.h"
#include "SystemStructs.h"

#ifdef DEBUG
#include "Debug.h"
#endif

class MCUCommModule {
private:
#ifdef DEBUG
	Debug debug;
#endif
public:
	MCUCommModule();
	~MCUCommModule();
	Status SendCurrVoltData(CurrVoltData * cvData);
};



#endif /* _MCU_COMM_MODULE_H_ */
