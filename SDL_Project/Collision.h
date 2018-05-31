#pragma once
#include "Field.h"

#define FIELD Field::Instance()

class Collision
{
private:
	bool bombCollision = false;
public:
	Collision();
	~Collision();

	void detectBombCollision(int adX, int adY);
	bool getBombCollisionStatus();
	void resetCollisionBool();
};

