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
			
			
			mis.mX = x;
			mis.mY = y;

			missiles.push_back(mis);
			tempSteps = 5;
			return;

		}
		tempSteps--;
		std::cout << "Current Steps: " << tempSteps << std::endl;
		return;
	}
}

void Enemy::manageMissiles(int enemyNumber)
{
	std::cout << "Missiles: " << missiles.size() << std::endl;
	resetMissilesOnField(enemyNumber);
	for (int i = 0; i < static_cast<int>(missiles.size()); i++) {
		switch (direction) {
		default:
			/*if (missiles[i].mX == 0) missiles.erase((missiles.begin()));
			if (missiles[i].mX > 0) {
				missiles[i].mX = missiles[i].mX - 1;
				missiles[i].mY = y;
			}			*/
			break;
		case 1:
			if (missiles[i].mY == 0) {
				missiles.erase((missiles.begin()));
			}
			else if (missiles[i].mY > 0) {
				missiles[i].mX = x;
				missiles[i].mY = missiles[i].mY - 1;
				//FIELD->tileField[missiles[i].mY][missiles[i].mX].missile = true;
			}
			break;
		case 2:
			if (missiles[i].mY == FIELD->getPlayfieldXSize()) missiles.erase((missiles.begin()));
			else if (missiles[i].mY < FIELD->getPlayfieldXSize()) {
				missiles[i].mX = missiles[i].mX + 1;
				missiles[i].mY = y;
			}
			break;
		case 3:
			if (missiles[i].mY == FIELD->getPlayfieldYSize()-1) missiles.erase((missiles.begin()));
			else if (missiles[i].mY < FIELD->getPlayfieldYSize()) {
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
	drawAllMissiles(enemyNumber);
}

void Enemy::drawAllMissiles(int enemyNumber)
{
	for (int i = 0; i < static_cast<int>(missiles.size()); i++) {
		switch (enemyNumber) {
		case 1:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile1 = true;
			break;
		case 2:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile2 = true;
			break;
		case 3:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile3 = true;
			break;
		case 4:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile4 = true;
			break;
		case 5:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile5 = true;
			break;
		case 6:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile6 = true;
			break;
		case 7:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile7 = true;
			break;
		case 8:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile8 = true;
			break;
		case 9:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile9 = true;
			break;
		case 10:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile10 = true;
			break;
		}
	}
}

void Enemy::resetMissilesOnField(int enemyNumber)
{
	for (int i = 0; i < static_cast<int>(missiles.size()); i++) {
		switch (enemyNumber) {
		case 1:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile1 = false;
			break;
		case 2:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile2 = false;
			break;
		case 3:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile3 = false;
			break;
		case 4:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile4 = false;
			break;
		case 5:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile5 = false;
			break;
		case 6:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile6 = false;
			break;
		case 7:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile7 = false;
			break;
		case 8:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile8 = false;
			break;
		case 9:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile9 = false;
			break;
		case 10:
			FIELD->tileField[missiles[i].mY][missiles[i].mX].missile10 = false;
			break;
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
