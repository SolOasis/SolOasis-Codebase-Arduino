#include <Arduino.h>
#include "Globals.h"
#include "SystemStructs.h"
#include "Schedule.h"
#include "LCDDisplay.h"
#include "Ports.h"
#include "InputModule.h"
#include "DataProcessorModule.h"

#ifdef DEBUG
#include "Debug.h"
Debug debug;
#endif

LCDDisplay* lcdDisplayPtr;
InputModule* inputModulePtr;
DataProcessorModule* dataProcessorModulePtr;
extern double energy = 0; //definition

void setup() {
	SetupPorts();
	SystemSetup();
	lcdDisplayPtr = new LCDDisplay();
	inputModulePtr = new InputModule();
	dataProcessorModulePtr = new DataProcessorModule();
}

void loop() {
	double currentSensorValue = 0;
	double voltageSensorValue = 0;
	double actualCurrent = 0;
	double actualVoltage = 0;
	// Calculate AVG_CYCLE ms average current and voltage,
	// and approximate energy = sum of {(I * V) * POWER_METER_MEASURE_PERIOD ms}
	for (int i=0; i<AVG_CYCLE; i++){
		double currentInThisLoop = inputModulePtr->GetPanelCurrent();
		double voltageInThisLoop = inputModulePtr->GetPanelVoltage();

		currentSensorValue += currentInThisLoop;
		voltageSensorValue += voltageInThisLoop;
		energy += currentInThisLoop * voltageInThisLoop * POWER_METER_MEASURE_PERIOD / 1000;
		delay(POWER_METER_MEASURE_PERIOD);
	}
	long int tmp_time = millis();
	actualCurrent = currentSensorValue / AVG_CYCLE;
	actualVoltage = voltageSensorValue / AVG_CYCLE;


	lcdDisplayPtr->Display(actualCurrent, actualVoltage, actualVoltage * actualCurrent, energy);

#ifdef DEBUG
	debug.print("V: ");
	debug.print(actualVoltage);
	debug.print(" / I: ");
	debug.print(actualCurrent);
	debug.print(" / P:");
	debug.print(actualVoltage * actualCurrent);
	debug.print(" / E:");
	debug.println(energy);

	//debug.println(millis() - tmp_time);
#endif


	//Compensate time taken my these calculations (about 1~10 millisecond)
	energy += actualVoltage * actualCurrent * (millis() - tmp_time) / 1000;

}
