/*
 * DataProcessorModule.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Allen, Chris
 */

#include "DataProcessorModule.h"

DataProcessorModule::DataProcessorModule() {
	inputModulePtr = new InputModule();
	lastUpdateTime = 0;
	energy = 0;
	avgCurr = 0;
	avgVolt = 0;
}

DataProcessorModule::~DataProcessorModule() {
}

double DataProcessorModule::GetAvgPower() {
	return energy / (lastUpdateTime / 1000);
}

double DataProcessorModule::GetCurrentPower() {
	return avgCurr * avgVolt;
}

double DataProcessorModule::GetEnergy() {
	return energy;
}

double DataProcessorModule::GetAvgVoltage() {
	return avgVolt;
}

double DataProcessorModule::GetAvgCurrent() {
	return avgCurr;
}

void DataProcessorModule::Update() {
	// Compensate energy for time not in this function
	long long currentTime = millis();
	energy += avgVolt * avgCurr * (currentTime - lastUpdateTime) / 1000;


	// Calculate AVG_CYCLE ms average current and voltage,
	// and approximate energy = sum of {(I * V) * POWER_METER_MEASURE_PERIOD ms}
	double currentSensorValue = 0;
	double voltageSensorValue = 0;

	for (int i=0; i<AVG_CYCLE; i++){
		double currentInThisLoop = inputModulePtr->GetPanelCurrent();
		double voltageInThisLoop = inputModulePtr->GetPanelVoltage();

		currentSensorValue += currentInThisLoop;
		voltageSensorValue += voltageInThisLoop;
		energy += currentInThisLoop * voltageInThisLoop * POWER_METER_MEASURE_PERIOD / 1000;
		delay(POWER_METER_MEASURE_PERIOD);
	}
	avgCurr = currentSensorValue / AVG_CYCLE;
	avgVolt = voltageSensorValue / AVG_CYCLE;

	// Update
	lastUpdateTime = millis();

}
