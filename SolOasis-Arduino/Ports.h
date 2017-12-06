#ifndef _PORTS_H_
#define _PORTS_H_

#include <Arduino.h>
#include <HardwareSerial.h>

// Must define Serial2 in Ports.cpp to avoid
// redefinition every time Ports.h is included

#define PANEL_VOLT_PIN A0
#define PANEL_CURR_PIN A3
#define BATT_VOLT_PIN
#define BATT_CURR_PIN
#define CONV_VOLT_PIN
#define CONV_CURR_PIN

#define CVSerial Serial
#define CV_BAUD 9600
#define BACK_LIGHT 9 //Brightness of LCD

// Define SetupPorts() as extern to avoid compiling
// problems
extern void SetupPorts();

#endif /* _PORTS_H_ */
