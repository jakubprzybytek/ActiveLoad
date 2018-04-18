#include <avr/io.h>

#include "TC74.h"

uint8_t TC74::ReadTemperature() {
	uint8_t read;
	TWI_write_reg(TC74A0_ADDRESS, TC74A0_READ_TEMPERATURE, 0, 0);
	TWI_read(TC74A0_ADDRESS, &read, 1);
	return read;
}

void TC74::SendCommand(uint8_t command) {
	TWI_write_reg(TC74A0_ADDRESS, command, 0, 0);
}
