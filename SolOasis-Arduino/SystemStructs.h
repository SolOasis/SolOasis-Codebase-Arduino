#ifndef _SYSTEM_STRUCTS_H_
#define _SYSTEM_STRUCTS_H_

#include<inttypes.h>

typedef struct SCurrVoltData {
//	float panelAvgVoltage;
//	float panelAvgCurrent;
//	float panelCurrPower;
//	float panelEnergy;
//	float battAvgVoltage;
//	float battAvgCurrent;
//	float battCurrPower;
//	float battEnergy;
//	float convAvgVoltage;
//	float convAvgCurrent;
//	float convCurrPower;
//	float convEnergy;
	float avgCurrent;
	float avgVoltage;
	float currPower;
	float energy;
} CurrVoltData;


typedef enum EStatus {
	OK
} Status;

#endif /* _SYSTEM_STRUCTS_H_ */
