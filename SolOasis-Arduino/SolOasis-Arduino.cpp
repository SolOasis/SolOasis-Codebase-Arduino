#include <Arduino.h>
#include "Globals.h"
#include "SystemStructs.h"
#include "Schedule.h"

extern LiquidCrystal lcd(8, 7, 6, 5, 4, 3, 2); //LCD setup pindefinition
extern double energy = 0; //definition
void setup() {
	SystemSetup();
}

void loop() {
	double currentSensorValue = 0;
	double voltageSensorValue = 0;
	double actualCurrent = 0;
	double actualVoltage = 0;
	// Calculate AVG_CYCLE ms average current and voltage,
	// and approximate energy = sum of {(I * V) * POWER_METER_MEASURE_PERIOD ms}
	for (int i=0; i<AVG_CYCLE; i++){
		double currentInThisLoop = (analogRead(A4) - CURRENT_BIAS) * CURRENT_RATIO;
		double voltageInThisLoop = analogRead(A5) * VOLTAGE_RATIO / 1024 * 5;
		if (abs(currentInThisLoop) < CURRENT_DETECT_TH) {
			currentInThisLoop = 0;
		}
		if (abs(voltageInThisLoop) < VOLTAGE_DETECT_TH) {
			voltageInThisLoop = 0;
		}
		currentSensorValue += currentInThisLoop;
		voltageSensorValue += voltageInThisLoop;
		energy += currentInThisLoop * voltageInThisLoop * POWER_METER_MEASURE_PERIOD / 1000;
		delay(POWER_METER_MEASURE_PERIOD);
	}
	long int tmp_time = millis();
	actualCurrent = currentSensorValue / AVG_CYCLE;
	actualVoltage = voltageSensorValue / AVG_CYCLE;

	Serial.print("V: ");
	Serial.print(actualVoltage);
	Serial.print(" / I: ");
	Serial.print(actualCurrent);
	Serial.print(" / P:");
	Serial.print(actualVoltage * actualCurrent);
	Serial.print(" / E:");
	Serial.println(energy);

	//////////////////////////////////////////print power and energy to a LCD////////////////////////////////////////////////
	lcd.setCursor(16,1); // set the cursor outside the display count
	lcd.print(" "); // print empty character
	lcd.setCursor(1,0); // set the cursor at 1st col and 1st row
	lcd.print(actualVoltage * actualCurrent);
	lcd.print("W ");
	lcd.print(actualVoltage);
	lcd.print("V  ");
	lcd.setCursor(1,1); // set the cursor at 1st col and 2nd row
	lcd.print(energy);
	lcd.print("Ws ");
	lcd.print(actualCurrent);
	lcd.print("A  ");
	//Compensate time taken my these calculations (about 1~10 millisecond)
	Serial.println(millis() - tmp_time);
	energy += actualVoltage * actualCurrent * (millis() - tmp_time) / 1000;

}
