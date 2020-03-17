/*
 * Screen.h
 *
 * Created: 2018-10-04 11:50:22
 *  Author: Rodos
 */ 


#ifndef SCREEN_H_
#define SCREEN_H_

#include "IO/Display.h"

class Screen {

private:
	Display display;

public:
	void init();
};

#endif /* SCREEN_H_ */