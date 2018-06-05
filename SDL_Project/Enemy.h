#pragma once
#include "Field.h"
#include "Header.h"

#define FIELD Field::Instance()

class Enemy
{
private:
	int x;
	int y;
	std::vector<int> missiles;
public:
	Enemy(int pX, int pY);
	~Enemy();

	void spawnMissile(int steps);
	void manageMissiles();
};

