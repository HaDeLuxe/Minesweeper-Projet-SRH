#include "Enemy.h"



Enemy::Enemy(int pX, int pY, int dir)
{
	x = pX;
	y = pY;
	this->direction = dir;
	FIELD->enterObjectInField(pX, pY, ENEMY);
}


Enemy::~Enemy()
{
}

void Enemy::changeEnemyPos(int pX, int pY)
{
	x = pX;
	y = pY;
}

void Enemy::spawnMissile()
{
	tempSteps = steps;

	while (tempSteps >= 0) {
		if (tempSteps == 0) {
			missile mis;
			
			switch (direction) {
			default:
				mis.mX = x - 1;
				mis.mY = y;
				break;
			case 1:
				mis.mX = x;
				mis.mY = y - 1;
				break;
			case 2:
				mis.mX = x + 1;
				mis.mY = y;
				break;
			case 3:
				mis.mX = x;
				mis.mY = y + 1;
				break;
			case 4:
				mis.mX = x - 1;
				mis.mY = y;
			}
			
			missiles.push_back(mis);
			tempSteps = steps;

		}
		tempSteps--;
	}
}

void Enemy::manageMissiles()
{
	resetMissilesOnField();
	for (int i = 0; i < missiles.size(); i++) {
		switch (direction) {
		default:
			missiles[i].mX = x - 1;
			missiles[i].mY = y;
			FIELD->tileField[missiles[i].mY - 1][missiles[i].mX].missile = true;
			break;
		case 1:
			missiles[i].mX = x;
			missiles[i].mY = y - 1;
			FIELD->tileField[missiles[i].mY - 1][missiles[i].mX].missile = true;
			break;
		case 2:
			missiles[i].mX = x + 1;
			missiles[i].mY = y;
			FIELD->tileField[missiles[i].mY][missiles[i].mX+1].missile = true;
			break;
		case 3:
			missiles[i].mX = x;
			missiles[i].mY = y + 1;
			FIELD->tileField[missiles[i].mY + 1][missiles[i].mX].missile = true;
			break;
		case 4:
			missiles[i].mX = x - 1;
			missiles[i].mY = y;
			FIELD->tileField[missiles[i].mY][missiles[i].mX-1].missile = true;
			break;
		}
	}
}

void Enemy::resetMissilesOnField()
{
	for (int y = 0; y < FIELD->tileField.size(); y++) {
		for (int x = 0; x < FIELD->tileField[y].size(); x++) {
			FIELD->tileField[y][x].missile = false;
		}
	}
}

void Enemy::destroyMissile(int x, int y)
{
	for(int i = 0; i < missiles.size(); i++) {
		if (missiles[i].mX == x && missiles[i].mY == y) {
			missiles.erase(missiles.begin()+i);
		}
	}
}





