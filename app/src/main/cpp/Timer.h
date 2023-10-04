/*
 * Timer.cpp
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */

#ifndef TIMER_H
#define TIMER_H

#include "raylib.h"
//#include "raymath.h"
class Timer{
public:
	float Lifetime;

	void StartTimer( float lifetime)
	;
	// update a timer with the current frame time
	void UpdateTimer()
	;

	// check if a timer is done.
	bool TimerDone()
	;
};

// start or restart a timer with a specific lifetime




#endif



