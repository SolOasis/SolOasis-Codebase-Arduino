/*
 * MCUCommModule.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#include "MCUCommModule.h"


MCUCommModule::MCUCommModule() {
}

MCUCommModule::~MCUCommModule() {
}

Status MCUCommModule::SendCurrVoltData(CurrVoltData* cvData) {
	CVSerial.write((byte*)cvData,sizeof(CurrVoltData));
	return OK;
}

