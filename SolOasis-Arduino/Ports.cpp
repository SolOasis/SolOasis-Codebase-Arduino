/*
 * Ports.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: Chris
 */

#include "Ports.h"

void SetupPorts(){
	CVSerial.begin(CV_BAUD);
}
