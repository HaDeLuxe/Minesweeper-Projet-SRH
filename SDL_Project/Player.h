#pragma once

#include "Textures.h"
class Player
{
private:
	 int lifePoints = 3;
public:
	Player();
	~Player();

	bool reduceLife();
	int returnLifePoints();
};

