#include "Enemy.h"



Enemy::Enemy(int pX, int pY)
{
	x = pX;
	y = pY;

	FIELD->enterObjectInField(pX, pY, ENEMY);
}


Enemy::~Enemy()
{
}

void Enemy::spawnMissile(int steps)
{
	int tempSteps = steps;
	while (tempSteps >= 0) {
		if (tempSteps == 0) {

		}
	}
}

void Enemy::manageMissiles()
{
}


