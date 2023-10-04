/*
 * Timer.cpp
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */
#include"Timer.h"
// start or restart a timer with a specific lifetime
void Timer::StartTimer( float lifetime)
{
    if (this != nullptr)
    	this->Lifetime = lifetime;
}

// update a timer with the current frame time
void Timer::UpdateTimer()
{
    // subtract this frame from the timer if it's not allready expired
    if (this != nullptr && this->Lifetime > 0)
        this->Lifetime -= GetFrameTime();
}

// check if a timer is done.
bool Timer::TimerDone()
{
    if (this != nullptr)
        return this->Lifetime <= 0;

	return false;
}



