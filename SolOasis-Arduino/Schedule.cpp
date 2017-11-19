/*
 * Schedule.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Chris
 */

#include <Arduino.h>
#include "Schedule.h"

//timer setup for timer0, timer1, and timer2.
//For arduino uno or any board with ATMEL 328/168.. diecimila, duemilanove, lilypad, nano, mini...

//this code will enable all three arduino timer interrupts.
//timer0 will interrupt at 2kHz
//timer1 will interrupt at 1Hz
//timer2 will interrupt at 8kHz

//storage variables (needed external to schedule
//data structure due to timer interrupts)
static bool timer0En = false;
static bool timer1En = false;
static bool timer2En = false;
static CurrVoltData cvData;
static DataProcessorModule datProc;
static MCUCommModule comm;

void Schedule::TimerSetup() {
	cli();//stop interrupts

#ifdef EN_TIMER0
	//set timer0 interrupt at 2kHz
	TCCR0A = 0;// set entire TCCR0A register to 0
	TCCR0B = 0;// same for TCCR0B
	TCNT0  = 0;//initialize counter value to 0
	// set compare match register for 2khz increments
	OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
	// turn on CTC mode
	TCCR0A |= (1 << WGM01);
	// Set CS01 and CS00 bits for 64 prescaler
	TCCR0B |= (1 << CS01) | (1 << CS00);
	// enable timer compare interrupt
	TIMSK0 |= (1 << OCIE0A);
#endif

#ifdef EN_TIMER1
	//set timer1 interrupt at 1Hz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set compare match register for 1hz increments
	OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS10 and CS12 bits for 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
#endif

#ifdef EN_TIMER2
	//set timer2 interrupt at 8kHz
	TCCR2A = 0;// set entire TCCR2A register to 0
	TCCR2B = 0;// same for TCCR2B
	TCNT2  = 0;//initialize counter value to 0
	// set compare match register for 8khz increments
	OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
	// turn on CTC mode
	TCCR2A |= (1 << WGM21);
	// Set CS21 bit for 8 prescaler
	TCCR2B |= (1 << CS21);
	// enable timer compare interrupt
	TIMSK2 |= (1 << OCIE2A);
#endif

	sei();//allow interrupts
}

Schedule::Schedule() {

}

Schedule::~Schedule() {
}

void Schedule::SetupSchedule() {
	timer0En = false;
	timer1En = false;
	timer2En = false;

	memset(&cvData,0,sizeof(CurrVoltData));

	SystemSetup();
	SetupPorts();
	TimerSetup();
}

void Schedule::RunSchedule() {
	timer1En = true;

	// scheduling loop
	int counter = 0;
	while(true){
		//Serial.print("Loop "); Serial.println(counter);
		datProc.Update();
		display.Display(datProc.GetAvgCurrent(),
				datProc.GetAvgVoltage(),
				datProc.GetCurrentPower(),
				datProc.GetEnergy());

	}
}

#ifdef EN_TIMER0
ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz (Unused)
	//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
	if (timer0En){

	}
	else{

	}
}
#endif

#ifdef EN_TIMER1
//ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz sends data to MCU
//	//generates pulse wave of frequency 1Hz/2 = 0.5kHz
//	if (timer1En){
//		comm.SendCurrVoltData(&cvData);
//	}
//	else{
//
//	}
//}

SIGNAL(TIMER1_COMPA_vect){
	if (timer1En){
		cvData.avgCurrent = datProc.GetAvgCurrent();
		cvData.avgVoltage = datProc.GetAvgVoltage();
		cvData.currPower = datProc.GetCurrentPower();
		cvData.energy = datProc.GetEnergy();
		comm.SendCurrVoltData(&cvData);
	}
	else{

	}
}
#endif

#ifdef EN_TIMER2
ISR(TIMER2_COMPA_vect){//timer1 interrupt 8kHz (Unused)
	//generates pulse wave of frequency 8kHz/2 = 4kHz (takes two cycles for full wave- toggle high then toggle low)
	if (timer2En){

	}
	else{

	}
}
#endif
