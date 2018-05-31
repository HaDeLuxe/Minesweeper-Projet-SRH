#include "Collision.h"



Collision::Collision()
{
}


Collision::~Collision()
{
}


void Collision::detectBombCollision(int adX, int adY)
{
	FIELD->calculatePlayerPos();
	if (FIELD->getObjectAtCoord(FIELD->getPlayerXPos() + adX, FIELD->getPlayerYPos() + adY) == BOMB) {
		std::cout << "Bomb Collision" << std::endl;
		bombCollision = true;
	}

}

bool Collision::getBombCollisionStatus()
{
	return bombCollision;
}

void Collision::resetCollisionBool()
{
	bombCollision = false;
}




