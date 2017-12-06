/*
 * InputModule.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Allen, Chris
 */

#include "InputModule.h"
#include "Ports.h"

InputModule::InputModule() {
}

InputModule::~InputModule() {
}

double InputModule::GetPanelVoltage() {
	double voltageAnalogRead =  analogRead(PANEL_VOLT_PIN) * VOLTAGE_RATIO / 1024 * 5;
	if (abs(voltageAnalogRead) < VOLTAGE_DETECT_TH) {
		voltageAnalogRead = 0;
	}
	return voltageAnalogRead;
}

double InputModule::GetPanelCurrent() {
	double currentAnalogRead =  (analogRead(PANEL_CURR_PIN) - CURRENT_BIAS) * CURRENT_RATIO;
	if (abs(currentAnalogRead) < CURRENT_DETECT_TH)
		currentAnalogRead = 0;
	return currentAnalogRead;
}

double InputModule::GetBattVoltage() {
	double voltageAnalogRead =  analogRead(BATT_VOLT_PIN) * VOLTAGE_RATIO / 1024 * 5;
	if (abs(voltageAnalogRead) < VOLTAGE_DETECT_TH) {
		voltageAnalogRead = 0;
	}
	return voltageAnalogRead;
}

double InputModule::GetBattCurrent() {
	double currentAnalogRead =  (analogRead(BATT_CURR_PIN) - CURRENT_BIAS) * CURRENT_RATIO;
	if (abs(currentAnalogRead) < CURRENT_DETECT_TH)
		currentAnalogRead = 0;
	return currentAnalogRead;

}

double InputModule::GetConvVoltage() {
	double voltageAnalogRead =  analogRead(CONV_VOLT_PIN) * VOLTAGE_RATIO / 1024 * 5;
	if (abs(voltageAnalogRead) < VOLTAGE_DETECT_TH) {
		voltageAnalogRead = 0;
	}
	return voltageAnalogRead;
}

double InputModule::GetConvCurrent() {
	double currentAnalogRead =  (analogRead(CONV_CURR_PIN) - CURRENT_BIAS) * CURRENT_RATIO;
	if (abs(currentAnalogRead) < CURRENT_DETECT_TH)
		currentAnalogRead = 0;
	return currentAnalogRead;

}
