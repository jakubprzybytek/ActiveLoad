/*
 * Switch.hpp
 *
 * Created: 2017-06-28 22:01:06
 *  Author: Rodos
 */ 


#ifndef TIMER_H_
#define TIMER_H_

class Timer {

private:
	TC5_t* timer;
	uint16_t per;

public:
	Timer (TC5_t* timer, uint16_t per) : timer(timer), per(per) {}

	void Init();

	void Enable();
	void Disable();

};

#endif /* TIMER_H_ */