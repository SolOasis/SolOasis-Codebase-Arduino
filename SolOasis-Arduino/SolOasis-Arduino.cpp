#include <Arduino.h>
#include "Globals.h"
#include "SystemStructs.h"
#include "Schedule.h"

#define START_ID_VAL_1 0xA5u
#define START_ID_VAL_2 0xB7u

Schedule schedule;
CurrVoltData cvData;
float data[9];


void setup() {
	//schedule.SetupSchedule();
	Serial.begin(9600);
//	cvData.startId1 = START_ID_VAL_1;
//	cvData.startId2 = START_ID_VAL_2;
	cvData.panelCurrent = 1.1;
	cvData.panelVoltage = 1.2;
	cvData.panelPower = 1.3;
	cvData.battCurrent = 2.4;
	cvData.battVoltage = 2.5;
	cvData.battPower = 2.6;
	cvData.convCurrent = 3.7;
	cvData.convVoltage = 3.8;
	cvData.convPower = 3.9;

	data[0] = 1.1;
	data[1] = 2.2;
	data[2] = 3.3;
	data[3] = 4.4;
	data[4] = 5.5;
	data[5] = 6.6;
	data[6] = 7.7;
	data[7] = 8.8;
	data[8] = 9.9;

//	int i = 0;
//	for(i = 0; i < sizeof(CurrVoltData); i++){
//		data[i]=((byte*)&cvData)[sizeof(CurrVoltData)-1-i];
//	}
}

void loop() {


//		CVSerial.write(out);
	//schedule.RunSchedule();
	Serial.write((byte*)&cvData, sizeof(CurrVoltData));
//	Serial.write((byte*)data, sizeof(float)*9);
	//Serial.write(data, sizeof(CurrVoltData));
	delay(1000);
}
