#include "Timer.h"



Timer::Timer()
{
	startTimer = true;
}


Timer::~Timer()
{
}

int Timer::getTicks(int speed)
{
	if (startTimer == true) {
		startTick = SDL_GetTicks();
		startTimer = false;
	}
	return (int)(SDL_GetTicks() - startTick) / speed;
}
