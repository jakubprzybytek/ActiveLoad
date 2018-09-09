/*
 * Encoder.h
 *
 * Created: 2015-09-15 22:36:31
 *  Author: Rodos
 */ 

#ifndef ENCODER_H_
#define ENCODER_H_

class Encoder {

private: 
	TC4_t * tc;

public:
	Encoder(TC4_t * tc) : tc(tc) {};

	void Init();

private:
	void InitTimer();
};


#endif /* ENCODER_H_ */