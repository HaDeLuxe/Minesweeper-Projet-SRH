#pragma once

#include "Textures.h"

extern int lifePoints;

class Player
{
private:
	
public:
	Player();
	~Player();


	bool reduceLife();
	int returnLifePoints();
};

