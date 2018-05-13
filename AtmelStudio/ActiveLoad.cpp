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

#include "Devices/TC74.h"

#include "Screen.h"
#include "Events.hpp"

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
 	metter.readVoltage();
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

	oscillationCancellingTimer.Init();
	heartbeat.Init();

	encoder.Init();
	encoderSwitch.Init();

	metter.init();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	heartbeat.Enable();
	metter.start();

	PORTA.DIRSET = PIN2_bm | PIN3_bm;

	DACA.CTRLB = DAC_CHSEL_DUAL_gc;
	DACA.CTRLC = DAC_REFSEL_INT1V_gc;
	DACA.CTRLA = DAC_CH0EN_bm | DAC_CH1EN_bm | DAC_ENABLE_bm;

	while ( (DACA.STATUS & DAC_CH0DRE_bm) == false );
	DACA.CH0DATA = 2000;

	while ( (DACA.STATUS & DAC_CH1DRE_bm) == false );
	DACA.CH1DATA = 0;

	uint16_t drain = 0;
	uint16_t fan = 200;
	uint8_t eventsStatus;
	while(1)
	{
		eventsStatus = events.getStatus();

		if (eventsStatus == Events::ENCODER_LEFT) {
			drain = drain < 10 ? 0 : drain - 10;
			fan = fan < 50 ? 0 : fan - 50;
			screen.drawDrainSetting(drain);
			screen.drawFanSetting(fan);

while ( (DACA.STATUS & DAC_CH0DRE_bm) == false );
DACA.CH0DATA = fan;

			while ( (DACA.STATUS & DAC_CH1DRE_bm) == false );
			DACA.CH1DATA = drain;
		}

		if (eventsStatus == Events::ENCODER_RIGHT) {
			drain = drain > 990 ? 1000 : drain + 10;
			fan = fan > 3950 ? 4000 : fan + 50;
			screen.drawDrainSetting(drain);
			screen.drawFanSetting(fan);

while ( (DACA.STATUS & DAC_CH0DRE_bm) == false );
DACA.CH0DATA = fan;

			while ( (DACA.STATUS & DAC_CH1DRE_bm) == false );
			DACA.CH1DATA = drain;
		}

		if (eventsStatus == Events::ENCODER_PRESSED) {
			screen.drawTemperature(termometer.ReadTemperature());
		}

		if (eventsStatus == Events::TIMER_DOWN) {
			screen.drawTemperature(termometer.ReadTemperature());
			screen.drawVoltage(metter.voltageValue);

			metter.start();
		}
	}

	return 0;
}
