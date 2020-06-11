/*
 * MessageQueue.hpp
 *
 *  Created on: Jun 11, 2020
 *      Author: Chipotle
 */

#ifndef INC_MESSAGEQUEUE_HPP_
#define INC_MESSAGEQUEUE_HPP_

#include <queue>

#include "stm32l1xx_hal.h"

#define SELECT_VOLTAGE_LIMIT_FOR_EDIT 1
#define SELECT_CURRENT_LIMIT_FOR_EDIT 2
#define RESET_COUNTERS 3
#define START_LOAD_SINK 4
#define STOP_LOAD_SINK 5
#define ENABLE_VOLTAGE_LIMIT 6
#define DISABLE_VOLTAGE_LIMIT 7

using namespace std;

class MessageQueue {

public:
	static MessageQueue& getInstance() {
		static MessageQueue instance;
		return instance;
	}

private:
	queue <uint8_t> messages;

public:
	void submit(uint8_t message);

	bool messageWaiting();
	uint8_t getMessage();
};



#endif /* INC_MESSAGEQUEUE_HPP_ */
