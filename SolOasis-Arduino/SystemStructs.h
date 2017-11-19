#ifndef _SYSTEM_STRUCTS_H_
#define _SYSTEM_STRUCTS_H_

#include<inttypes.h>

typedef struct SCurrVoltData {
//	float panelVoltage;
//	float panelCurrent;
//	float panelPower;
//	float battVoltage;
//	float battCurrent;
//	float battPower;
//	float convVoltage;
//	float convCurrent;
//	float convPower;
	float avgCurrent;
	float avgVoltage;
	float currPower;
	float energy;
} CurrVoltData;


typedef enum EStatus {
	OK
} Status;

#endif /* _SYSTEM_STRUCTS_H_ */
