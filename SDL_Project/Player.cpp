#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

bool Player::reduceLife()
{
	while (lifePoints > 0) {
		lifePoints--;
		return true;
	}
	
	if (lifePoints <= 0) {
		return false;
	}
}

int Player::returnLifePoints()
{
	return lifePoints;
}


