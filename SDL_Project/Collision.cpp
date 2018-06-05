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
	if (FIELD->getObjectAtCoord(FIELD->getPlayerXPos() + adX, FIELD->getPlayerYPos() + adY) == BOMB ||
		FIELD->tileField[FIELD->getPlayerYPos() + adY][FIELD->getPlayerXPos() + adX].missile == true) {
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

void Collision::detectAmmuCollision(int adX, int adY)
{
	FIELD->calculatePlayerPos();
	if (FIELD->getObjectAtCoord(FIELD->getPlayerXPos() + adX, FIELD->getPlayerYPos() + adY) == AMMU) {
		std::cout << "Ammu Collision" << std::endl;
		ammuCollision = true;
	}

}

bool Collision::getAmmuCollisionStatus()
{
	return ammuCollision;
}

void Collision::resetAmmuCollisionBool()
{
	ammuCollision = false;
}




