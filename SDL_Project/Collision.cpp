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
		FIELD->damgageTriggered = true;
	}
	if (FIELD->tileField[FIELD->getPlayerYPos() + adY][FIELD->getPlayerXPos() + adX].missile1 == true ||
		FIELD->tileField[FIELD->getPlayerYPos() + adY][FIELD->getPlayerXPos() + adX].missile2 == true ||
		FIELD->tileField[FIELD->getPlayerYPos() + adY][FIELD->getPlayerXPos() + adX].missile3 == true ||
		FIELD->tileField[FIELD->getPlayerYPos() + adY][FIELD->getPlayerXPos() + adX].missile4 == true ||
		FIELD->tileField[FIELD->getPlayerYPos() + adY][FIELD->getPlayerXPos() + adX].missile5 == true) {
		std::cout << "Laser Collision" << std::endl;
		bombCollision = true;
		FIELD->damgageTriggered = true;
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

bool Collision::detectGoalCollision(int adX, int adY)
{
	FIELD->calculatePlayerPos();
	if (FIELD->getObjectAtCoord(FIELD->getPlayerXPos() + adX, FIELD->getPlayerYPos() + adY) == GOAL) {
		return true;
	}
	return false;
}

bool Collision::detectShieldCollision(int adX, int adY)
{
	FIELD->calculatePlayerPos();
	if (FIELD->getObjectAtCoord(FIELD->getPlayerXPos() + adX, FIELD->getPlayerYPos() + adY) == SHIELD) {
		return true;
	}
	return false;
}

bool Collision::detectPillCollision(int adX, int adY)
{

	FIELD->calculatePlayerPos();
	if (FIELD->getObjectAtCoord(FIELD->getPlayerXPos() + adX, FIELD->getPlayerYPos() + adY) == PILL) {
		std::cout << "Pill Collision detected!" << std::endl;
		return true;
	}
	return false;
}




