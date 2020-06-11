/*
 * EEPROM.hpp
 *
 *  Created on: Jun 6, 2020
 *      Author: Chipotle
 */

#ifndef INC_EEPROM_HPP_
#define INC_EEPROM_HPP_

#include "ApplicationState.hpp"

#define EEPROM_DATA_VERSION 5

class EEPROM {

private:
	uint16_t writes;

public:
	void write(ApplicationState& applicationState);
	void read(ApplicationState& applicationState);

};

#endif /* INC_EEPROM_HPP_ */
