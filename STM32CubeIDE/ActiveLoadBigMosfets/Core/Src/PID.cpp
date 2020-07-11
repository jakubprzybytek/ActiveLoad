#include "PID.hpp"

float PID::update(float setpoint, float measurement) {

	float error = setpoint - measurement;

	float proportional = this->kP * error;

	this->integrator += 0.5f * this->kI * this->T * (error + this->previousError);

	// Anti-wind-up via dynamic integrator clamping
	float integratorLimitMin = proportional > this->limitMin ? this->limitMin - proportional : 0.0f;
	float integratorLimitMax = proportional < this->limitMax ? this->limitMax - proportional : 0.0f;

	this->integrator = this->integrator > integratorLimitMin ? (this->integrator < integratorLimitMax ? this->integrator : integratorLimitMax) : integratorLimitMin;

	float out = proportional + this->integrator;
	this->previousError = error;

	return out > this->limitMin ? (out < this->limitMax ? out : this->limitMax) : this->limitMin;
}

void PID::reset() {
	this->integrator = 0.0f;
	this->previousError = 0.0f;
}
