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

	void detectBombCollision(int adX, int adY); //detects a Bomb Collision  and changes bombCollision = true
	bool getBombCollisionStatus();	//return bombCollision
	void resetCollisionBool();	// bombCollision = false

	void detectAmmuCollision(int adX, int adY); //detects a Ammunition Collison and changes ammuCollision = true
	bool getAmmuCollisionStatus();	//return AmmuCollision
	void resetAmmuCollisionBool();	

	bool detectGoalCollision(int adX, int adY);	// return true when Goal Collision
	bool detectShieldCollision(int adX, int adY);	// retrun true when Shield Collison
	bool detectPillCollision(int adX, int adY); // returns true when Pill Collision

	
};

