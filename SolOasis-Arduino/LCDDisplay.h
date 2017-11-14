/*
 * LCDDisplay.h
 *
 *  Created on: Nov 14, 2017
 *      Author: Allen
 */

#ifndef LCDDISPLAY_H_
#define LCDDISPLAY_H_

#include "Globals.h"
#include "SystemStructs.h"
#include <LiquidCrystal.h>

#ifdef DEBUG
#include "Debug.h"
#endif

class LCDDisplay {
	private:
		LiquidCrystal lcd;
	#ifdef DEBUG
		Debug debug;
	#endif


	public:
		LCDDisplay();
		~LCDDisplay();
		void Display(double curr, double volt, double power, double energy);
};

#endif /* LCDDISPLAY_H_ */
