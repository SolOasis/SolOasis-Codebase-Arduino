#ifndef _PORTS_H_
#define _PORTS_H_

#include <Arduino.h>
#include <HardwareSerial.h>

// Must define Serial2 in Ports.cpp to avoid
// redefinition every time Ports.h is included

#define CVSerial Serial
#define CV_BAUD 9600
#define BACK_LIGHT 9 //Brightness of LCD

// Define SetupPorts() as extern to avoid compiling
// problems
extern void SetupPorts();

#endif /* _PORTS_H_ */
