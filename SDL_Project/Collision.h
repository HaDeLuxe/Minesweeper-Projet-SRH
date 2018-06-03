#pragma once
#include "Field.h"

#define FIELD Field::Instance()

class Collision
{
private:
	bool bombCollision = false;
	bool ammuCollision = false;
public:
	Collision();
	~Collision();

	void detectBombCollision(int adX, int adY);
	bool getBombCollisionStatus();
	void resetCollisionBool();

	void detectAmmuCollision(int adX, int adY);
	bool getAmmuCollisionStatus();
	void resetAmmuCollisionBool();
};

