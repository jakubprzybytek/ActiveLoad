#include "Timer.hpp"

void Timer::reset() {
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;
}

/**
 * Perform once a second.
 */
void Timer::tick() {
	this->seconds++;

	if (this->seconds >= 60) {
		this->seconds = 0;
		this->minutes++;

		if (this->minutes >= 60) {
			this->minutes = 0;
			this->hours++;
		}
	}
}
