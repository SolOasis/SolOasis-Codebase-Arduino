/*
 * DataProcessorModule.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#include "DataProcessorModule.h"

DataProcessorModule::DataProcessorModule() {
}

DataProcessorModule::~DataProcessorModule() {
}

double DataProcessorModule::GetPower(double curr, double volt) {

	return curr * volt;
}

