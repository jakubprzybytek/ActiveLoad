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

#include "Devices/TC74.h"

#include "Screen.h"
#include "Events.hpp"

// Timers
Timer oscillationCancellingTimer(&TCC4, 600);

// IO
Encoder encoder(&TCC5);
InterruptSwitch encoderSwitch(&PORTC, PIN7_bm, &(PORTC.PIN7CTRL));

Events events;

/* *****************
 * Main encoder interrupt: left
 ***************** */
ISR (TCC5_CCA_vect) {
	TCC5.CNT = 8;
	events.setStatus(Events::ENCODER_LEFT);
}

/* *****************
 * Main encoder interrupt: right
 ***************** */
ISR (TCC5_CCB_vect) {
	TCC5.CNT = 8;
	events.setStatus(Events::ENCODER_RIGHT);
}

/* *****************
 * Port C: Power Switch 0 int
 ***************** */
ISR (PORTC_INT_vect) {
	processSwitchInterrupt();
	PORTC.INTFLAGS = PORT_INT7IF_bm;
	events.setStatus(Events::ENCODER_PRESSED);
}

/* *****************
 * TCC4: All Switch timer interrupt
 ***************** */
ISR (TCC4_OVF_vect) {
	processTimerInterrupt();
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
//	char buffer[20];

	Screen screen;
	TC74 termometer;
/*
	screen.appendTextLine("Hello World!");

	for (uint16_t i = 0; i < 20; i++) {
		sprintf(buffer, "i=%d", i);
		screen.appendTextLine(buffer);

		_delay_ms(10);
	}
	screen.appendTextLine("I am done.");
*/
	oscillationCancellingTimer.Init();

	encoder.Init();
	encoderSwitch.Init();

	// enable interrupts
	PMIC.CTRL = PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	uint8_t eventsStatus;
	while(1)
	{
		eventsStatus = events.getStatus();

		if (eventsStatus == Events::ENCODER_LEFT) {
			screen.setTemperature(termometer.ReadTemperature());
		}

		if (eventsStatus == Events::ENCODER_RIGHT) {
			//screen.appendTextLine("Go right.");
		}

		if (eventsStatus == Events::ENCODER_PRESSED) {
			//screen.appendTextLine("Pressed.");
		}
	}

	return 0;
}
