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

#define  AUTO_FAN_MIN_TEMP 30
#define  AUTO_FAN_MAX_TEMP 60

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

	bool inDrainEditMode = true;
	bool autoFan = true;

	uint8_t drainPercentage = 0;
	uint8_t fanPercentage = 0;

	analogDrivers.setFan(fanPercentage);
	analogDrivers.setDrain(drainPercentage);

	screen.drawDrainSetting(drainPercentage, inDrainEditMode, true);
	screen.drawFanSetting(fanPercentage, autoFan, !inDrainEditMode, true);

	uint8_t eventsStatus;
	while(1)
	{
		eventsStatus = events.getStatus();

		if (eventsStatus == Events::ENCODER_LEFT) {
			if (inDrainEditMode) { // Drain Edit Mode
				drainPercentage = drainPercentage < 1 ? 0 : drainPercentage - 1;
				analogDrivers.setDrain(drainPercentage);
				screen.drawDrainSetting(drainPercentage, inDrainEditMode, false);
			} else { // Fan Edit Mode (0=off, Auto, 10-100)
				if (autoFan) {
					autoFan = false;
					fanPercentage = 0;
				} else if (fanPercentage == 10) {
					autoFan = true;
				} else {				
					fanPercentage = fanPercentage < 10 ? 0 : fanPercentage - 10;
				}
				analogDrivers.setFan(fanPercentage);
				screen.drawFanSetting(fanPercentage, autoFan, !inDrainEditMode, false);
			}
		}

		if (eventsStatus == Events::ENCODER_RIGHT) {
			if (inDrainEditMode) { // Drain Edit Mode
				drainPercentage = drainPercentage > 99 ? 100 : drainPercentage + 1;
				analogDrivers.setDrain(drainPercentage);
				screen.drawDrainSetting(drainPercentage, inDrainEditMode, false);
			} else { // Fan Edit Mode (0=off, Auto, 10-100)
				if (autoFan) {
					autoFan = false;
					fanPercentage = 10;
				} else if (fanPercentage == 0) {
					autoFan = true;
				} else {
					fanPercentage = fanPercentage > 90 ? 100 : fanPercentage + 10;
				}
				analogDrivers.setFan(fanPercentage);
				screen.drawFanSetting(fanPercentage, autoFan, !inDrainEditMode, false);
			}
		}

		if (eventsStatus == Events::ENCODER_PRESSED) {
			inDrainEditMode = !inDrainEditMode;

			screen.drawDrainSetting(drainPercentage, inDrainEditMode, true);
			screen.drawFanSetting(fanPercentage, autoFan, !inDrainEditMode, true);
		}

		if (eventsStatus == Events::TIMER_DOWN) {
			LED_TOGGLE;

			uint8_t temperature = termometer.ReadTemperature();
			screen.drawTemperature(temperature);
			screen.drawVoltage(metter.voltageValue);
			screen.drawCurrent(metter.currentValue);

			if (autoFan) {
				fanPercentage = temperature < AUTO_FAN_MIN_TEMP ? 0 : temperature > AUTO_FAN_MAX_TEMP ? 100 : (uint16_t)(temperature - AUTO_FAN_MIN_TEMP) * 100 / (AUTO_FAN_MAX_TEMP - AUTO_FAN_MIN_TEMP);
				analogDrivers.setFan(fanPercentage);
				screen.drawFanSetting(fanPercentage, autoFan, !inDrainEditMode, false);
			}

			metter.toggleInput();
			metter.start();
		}
	}

	return 0;
}
