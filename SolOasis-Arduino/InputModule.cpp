/*
 * InputModule.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Allen, Chris
 */

#include "InputModule.h"

InputModule::InputModule() {
}

InputModule::~InputModule() {
}

double InputModule::GetPanelVoltage() {
	double voltageAnalogRead =  analogRead(A5) * VOLTAGE_RATIO / 1024 * 5;
	if (abs(voltageAnalogRead) < VOLTAGE_DETECT_TH) {
		voltageAnalogRead = 0;
	}

	return voltageAnalogRead;
}

double InputModule::GetPanelCurrent() {
	double currentAnalogRead =  (analogRead(A4) - CURRENT_BIAS) * CURRENT_RATIO;
	if (abs(currentAnalogRead) < CURRENT_DETECT_TH)
		currentAnalogRead = 0;
	return currentAnalogRead;
}

double InputModule::GetBattVoltage() {

	return 0;
}

double InputModule::GetBattCurrent() {

	return 0;
}

double InputModule::GetConvVoltage() {

	return 0;
}

double InputModule::GetConvCurrent() {

	return 0;
}
