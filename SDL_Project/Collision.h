#pragma once
#include "Field.h"
#include "GameManager.h"

#define FIELD Field::Instance()

class Collision
{
private:
	bool bombCollision = false;
	bool ammuCollision = false;
	GameManager* gameManager = new GameManager();
public:
	Collision();
	~Collision();

	void detectBombCollision(int adX, int adY);
	bool getBombCollisionStatus();
	void resetCollisionBool();

	void detectAmmuCollision(int adX, int adY);
	bool getAmmuCollisionStatus();
	void resetAmmuCollisionBool();

	bool detectGoalCollision(int adX, int adY);
	bool detectShieldCollision(int adX, int adY);
	bool detectPillCollision(int adX, int adY);

	
};

