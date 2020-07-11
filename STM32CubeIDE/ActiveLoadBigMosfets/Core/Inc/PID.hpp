/*
 * PID.hpp
 *
 *  Created on: Jun 3, 2020
 *      Author: Chipotle
 */

#ifndef INC_PID_HPP_
#define INC_PID_HPP_

class PID {

private:
	float kP;
	float kI;

	float T;

	float limitMin;
	float limitMax;

	float previousError;
	float integrator;

public:
	PID(float kP, float kI, float T, float limitMin, float limitMax) : kP (kP), kI (kI), T(T), limitMin(limitMin), limitMax(limitMax) {}

	float update(float setpoint, float measurement);
	void reset();
};

#endif /* INC_PID_HPP_ */
