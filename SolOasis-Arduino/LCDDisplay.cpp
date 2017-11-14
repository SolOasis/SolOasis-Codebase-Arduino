/*
 * LCDDisplay.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: allen
 */

#include "LCDDisplay.h"


LCDDisplay::LCDDisplay() : lcd(8, 7, 6, 5, 4, 3, 2) {
	//LiquidCrystal lcd(8, 7, 6, 5, 4, 3, 2);
	lcd.begin(16,2); // columns, rows. size of display
	lcd.clear(); // clear the screen
}

LCDDisplay::~LCDDisplay() {

}

void LCDDisplay::Display(double curr, double volt, double power, double energy) {
	//////////////////////////////////////////print power and energy to a LCD////////////////////////////////////////////////
	lcd.setCursor(16,1); // set the cursor outside the display count
	lcd.print(" "); // print empty character

	lcd.setCursor(1,0); // set the cursor at 1st col and 1st row

	if (volt > 0)
		lcd.print(" ");
	lcd.print(volt);
	lcd.print("V  ");
	if (power > 0)
		lcd.print(" ");
	lcd.print(power);
	lcd.print("W ");

	lcd.setCursor(1,1); // set the cursor at 1st col and 2nd row

	if (curr > 0)
		lcd.print(" ");
	lcd.print(curr);
	lcd.print("A  ");

	if (energy > 0)
		lcd.print(" ");
	lcd.print(energy);
	lcd.print("Ws ");
}
