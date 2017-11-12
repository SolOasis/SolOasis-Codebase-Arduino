#ifndef _SYSTEM_STRUCTS_H_
#define _SYSTEM_STRUCTS_H_

#include<inttypes.h>

typedef struct SCurrVoltData {
	double panelVoltage;
	double panelCurrent;
	double panelPower;
	double battVoltage;
	double battCurrent;
	double battPower;
	double convVoltage;
	double convCurrent;
	double convPower;
} CurrVoltData;


typedef enum EStatus {
	OK
} Status;

#endif /* _SYSTEM_STRUCTS_H_ */
