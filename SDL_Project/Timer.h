#pragma once

#include "Header.h"

class Timer
{
private:
	int startTick = 0;
	bool startTimer;
public:
	Timer();
	~Timer();
	int getTicks(int speed);
};

