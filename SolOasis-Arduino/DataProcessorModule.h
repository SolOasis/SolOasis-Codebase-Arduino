/*
 * DataProcessorModule.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#ifndef _DATA_PROCESSOR_MODULE_H_
#define _DATA_PROCESSOR_MODULE_H_

#include "Globals.h"
#include "SystemStructs.h"

#ifdef DEBUG
#include "Debug.h"
#endif

class DataProcessorModule {
private:
#ifdef DEBUG
	Debug debug;
#endif

public:
	DataProcessorModule();
	~DataProcessorModule();
	double GetPower(double curr, double volt);
};


#endif /* _DATA_PROCESSOR_MODULE_H_ */
