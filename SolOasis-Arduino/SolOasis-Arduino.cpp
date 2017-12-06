/*
 * SolOasis-Arduino.cpp
 *
 *  	Version: 1.1 (Nov 14, 2017)
 *      Author: Allen, Chris
 */
#include <Arduino.h>
#include "Schedule.h"

#ifdef DEBUG
#include "Debug.h"
Debug debug;
#endif

Schedule s;
void setup() {
	s.SetupSchedule();
}

void loop() {
	s.RunSchedule();
}
