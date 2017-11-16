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
#ifdef DEBUG
	debug.print("Panel Current:     "); debug.println(cvData->panelCurrent);
	debug.print("Panel Voltage:     "); debug.println(cvData->panelVoltage);
	debug.print("Panel Power:       "); debug.println(cvData->panelPower);
	debug.print("Battery Current:   "); debug.println(cvData->battCurrent);
	debug.print("Battery Voltage:   "); debug.println(cvData->battVoltage);
	debug.print("Battery Power:     "); debug.println(cvData->battPower);
	debug.print("Converter Current: "); debug.println(cvData->convCurrent);
	debug.print("Converter Voltage: "); debug.println(cvData->convVoltage);
	debug.print("Converter Power:   "); debug.println(cvData->convPower);
#endif
	CVSerial.write((byte*)cvData,sizeof(CurrVoltData));
	return OK;
}

