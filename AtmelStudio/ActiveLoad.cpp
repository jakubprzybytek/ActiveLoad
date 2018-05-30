/*
 * DisplaySSD1306.cpp
 *
 * Created: 2018-02-03 21:47:39
 * Author : Rodos
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "ActiveLoad.h"

#include "Tools/Switch.hpp"
#include "Tools/Timer.hpp"

#include "IO/Encoder.hpp"
#include "IO/Metter.h"
#include "IO/AnalogDrivers.h"

#include "Devices/TC74.h"

#include "Screen.h"
#include "Events.hpp"

#define LED_INIT	PORTD.DIRSET = PIN3_bm
#define LED_TOGGLE	PORTD.OUTTGL = PIN3_bm

// Timers
Timer oscillationCancellingTimer(&TCC5, 600);
Timer heartbeat(&TCD5, 500);

// IO
Encoder encoder(&TCC4);
InterruptSwitch encoderSwitch(&PORTC, PIN7_bm, &(PORTC.PIN7CTRL));
Metter metter;

Events events;

/* *****************
 * Main encoder interrupt: left
 ***************** */
ISR (TCC4_CCA_vect) {
	TCC4.CNT = 8;
	events.setStatus(Events::ENCODER_LEFT);
}

/* *****************
 * Main encoder interrupt: right
 ***************** */
ISR (TCC4_CCB_vect) {
	TCC4.CNT = 8;
	events.setStatus(Events::ENCODER_RIGHT);
}

/* *****************
 * Port C: Encoder Switch 0 int
 ***************** */
ISR (PORTC_INT_vect) {
	processSwitchInterrupt();
	PORTC.INTFLAGS = PORT_INT7IF_bm;
	events.setStatus(Events::ENCODER_PRESSED);
}

/* *****************
 * TCC5: All Switch timer interrupt
 ***************** */
ISR (TCC5_OVF_vect) {
	processTimerInterrupt();
}

/* *****************
 * TCD5: Heartbeat timer interrupt
 ***************** */
ISR (TCD5_OVF_vect) {
	TCD5.INTFLAGS = TC5_OVFIF_bm;
	events.setStatus(Events::TIMER_DOWN);
}

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH0_vect) {
 	metter.storeReadout();
}

void processSwitchInterrupt() {
	encoderSwitch.DisableInterrupt();

	oscillationCancellingTimer.Enable();
}

void processTimerInterrupt() {
	if (encoderSwitch.IsUp()) {
		oscillationCancellingTimer.Disable();

		encoderSwitch.EnableInterrupt();
	}
}

int main(void) {
	Screen screen;
	TC74 termometer;
	AnalogDrivers analogDrivers;

	LED_INIT;

	oscillationCancellingTimer.Init();
	heartbeat.Init();

	encoder.Init();
	encoderSwitch.Init();

	metter.init();
	analogDrivers.init();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	heartbeat.Enable();
	metter.start();

	uint16_t drain = 0;
	uint16_t fan = 200;

	analogDrivers.setFan(fan);
	analogDrivers.setDrain(drain);

	uint8_t eventsStatus;
	while(1)
	{
		eventsStatus = events.getStatus();

		if (eventsStatus == Events::ENCODER_LEFT) {
			drain = drain < 50 ? 0 : drain - 50;
			fan = fan < 50 ? 0 : fan - 50;
			screen.drawDrainSetting(drain);
			screen.drawFanSetting(fan);

			analogDrivers.setFan(fan);
			analogDrivers.setDrain(drain);
		}

		if (eventsStatus == Events::ENCODER_RIGHT) {
			drain = drain > 2990 ? 3000 : drain + 50;
			fan = fan > 3950 ? 4000 : fan + 50;
			screen.drawDrainSetting(drain);
			screen.drawFanSetting(fan);

			analogDrivers.setFan(fan);
			analogDrivers.setDrain(drain);
		}

		if (eventsStatus == Events::ENCODER_PRESSED) {
			screen.drawTemperature(termometer.ReadTemperature());
		}

		if (eventsStatus == Events::TIMER_DOWN) {
			LED_TOGGLE;

			screen.drawTemperature(termometer.ReadTemperature());
			screen.drawVoltage(metter.voltageValue);
			screen.drawCurrent(metter.currentValue);

			metter.toggleInput();
			metter.start();
		}
	}

	return 0;
}
