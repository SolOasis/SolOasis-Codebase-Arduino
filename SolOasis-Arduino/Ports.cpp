/*
 * Ports.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: Chris, Allen
 */

#include "Ports.h"

void SetupPorts(){
	CVSerial.begin(CV_BAUD);
	pinMode(BACK_LIGHT, OUTPUT); //set pin 9 as output
	analogWrite(BACK_LIGHT, 150); //controls the backlight intensity 0-254
}
