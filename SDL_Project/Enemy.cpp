#include "Enemy.h"

int direction = 4;

Enemy::Enemy(int pX, int pY, int dir)
{
	x = pX;
	y = pY;
	direction = dir;
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
	

	while (tempSteps >= 0) {
		if (tempSteps == 0) {
			missile mis;
			
			switch (direction) {
			default:
				mis.mX = x;
				mis.mY = y;
				break;
			case 1:
				mis.mX = x;
				mis.mY = y;
				break;
			case 2:
				mis.mX = x;
				mis.mY = y;
				break;
			case 3:
				mis.mX = x;
				mis.mY = y;
				break;
			case 4:
				mis.mX = x ;
				mis.mY = y;
			}
			
			missiles.push_back(mis);
			tempSteps = 5;
			return;

		}
		tempSteps--;
		std::cout << "Current Steps: " << tempSteps << std::endl;
		return;
	}
}

void Enemy::manageMissiles()
{
	std::cout << "Missiles: " << missiles.size() << std::endl;
	resetMissilesOnField();
	for (int i = 0; i < static_cast<int>(missiles.size()); i++) {
		switch (direction) {
		default:
			if (missiles[i].mX == 0) missiles.erase((missiles.begin()));
			if (missiles[i].mX > 0) {
				missiles[i].mX = missiles[i].mX - 1;
				missiles[i].mY = y;
			}			break;
		case 1:
			if (missiles[i].mY == 0) missiles.erase((missiles.begin()));
			if (missiles[i].mY > 0) {
				missiles[i].mX = x;
				missiles[i].mY = missiles[i].mY - 1;
				FIELD->tileField[missiles[i].mY][missiles[i].mX].missile = true;
			}
			break;
		case 2:
			if (missiles[i].mY == FIELD->getPlayfieldXSize()) missiles.erase((missiles.begin()));
			if (missiles[i].mY < FIELD->getPlayfieldXSize()) {
				missiles[i].mX = missiles[i].mX + 1;
				missiles[i].mY = y;
			}
			break;
		case 3:
			if (missiles[i].mY == FIELD->getPlayfieldYSize()-1) missiles.erase((missiles.begin()));
			if (missiles[i].mY < FIELD->getPlayfieldYSize()) {
				missiles[i].mX = x;
				missiles[i].mY = missiles[i].mY + 1;
				
			}
			break;
		case 4:
			if (missiles[i].mX == 0) missiles.erase((missiles.begin()));
			if (missiles[i].mX > 0) {
				missiles[i].mX = missiles[i].mX - 1;
				missiles[i].mY = y;
			}			break;
		}
	}
	drawAllMissiles();
}

void Enemy::drawAllMissiles()
{
	for (int i = 0; i < static_cast<int>(missiles.size()); i++) {
		FIELD->tileField[missiles[i].mY][missiles[i].mX].missile = true;
	}
}

void Enemy::resetMissilesOnField()
{
	for (int y = 0; y < static_cast<int>(FIELD->tileField.size()); y++) {
		for (int x = 0; x < static_cast<int>(FIELD->tileField[y].size()); x++) {
			FIELD->tileField[y][x].missile = false;
		}
	}
}

void Enemy::destroyMissile(int x, int y)
{
	for(int i = 0; i < static_cast<int>(missiles.size()); i++) {
		if (missiles[i].mX == x && missiles[i].mY == y) {
			missiles.erase(missiles.begin()+i);
		}
	}
}
