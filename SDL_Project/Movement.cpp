#include "Movement.h"


Movement::Movement()
{
	col = new Collision();
} //constructor

Movement::~Movement()
{
} //deconstructor



#pragma region Moving Functions

void Movement::moveUp()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pY > 0) {
		if (FIELD->getObjectAtCoord(pX, pY - 1) != WALL) {
			
			if (lastDirection == 1) {
				col->detectBombCollision(0, -1);
				FIELD->enterObjectInField(pX, pY, tempTileBox);
				if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
				if (FIELD->getObjectAtCoord(pX, pY - 1) == BOMB) {
					tempTileBox = BOMB;
				}
				pY--;
				FIELD->enterObjectInField(pX, pY, PLAYER);
			}
			FIELD->calculatePlayerPos();
			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
			if (pY > 0) {
				FIELD->tileField[_lastCrosshairYPos][_lastCrosshairXPos].crosshair = false;
				FIELD->tileField[FIELD->getPlayerYPos() - 1][FIELD->getPlayerXPos()].crosshair = true;
				_lastCrosshairXPos = FIELD->getPlayerXPos();
				_lastCrosshairYPos = FIELD->getPlayerYPos()-1;
			}
		}
		lastDirection = 1;
	}
		
}



void Movement::moveDown()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pY <  static_cast<int>(FIELD->tileField.size()) - 1) {
		if (FIELD->getObjectAtCoord(pX, pY + 1) != WALL) {
			
			if (lastDirection == 3) {
				col->detectBombCollision(0, 1);
				FIELD->enterObjectInField(pX, pY, tempTileBox);
				if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
				if (FIELD->getObjectAtCoord(pX, pY + 1) == BOMB) {
					tempTileBox = BOMB;
				}
				pY++;
				FIELD->enterObjectInField(pX, pY, PLAYER);
			}
			FIELD->calculatePlayerPos();
			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
			if (pY <  static_cast<int>(FIELD->tileField.size() - 1)) {
				FIELD->tileField[_lastCrosshairYPos][_lastCrosshairXPos].crosshair = false;
				FIELD->tileField[FIELD->getPlayerYPos()+1][FIELD->getPlayerXPos()].crosshair = true;
				_lastCrosshairXPos = FIELD->getPlayerXPos();
				_lastCrosshairYPos = FIELD->getPlayerYPos()+1;
			}
		}
	}
	lastDirection = 3;
	
}

void Movement::moveRight()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if(pX < static_cast<int>(FIELD->tileField[pY].size() - 1)){
		if (FIELD->getObjectAtCoord(pX + 1, pY) != WALL) {
			
			if (lastDirection == 2) {
				col->detectBombCollision(1, 0);
				FIELD->enterObjectInField(pX, pY, tempTileBox);
				if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
				if (FIELD->getObjectAtCoord(pX + 1, pY) == BOMB) {
					tempTileBox = BOMB;
				}
				pX++;
				FIELD->enterObjectInField(pX, pY, PLAYER);
			}
			FIELD->calculatePlayerPos();
			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());

			if (pX < static_cast<int>(FIELD->tileField[pY].size() - 1)) {
				FIELD->tileField[_lastCrosshairYPos][_lastCrosshairXPos].crosshair = false;
				FIELD->tileField[FIELD->getPlayerYPos()][FIELD->getPlayerXPos() + 1].crosshair = true;
				_lastCrosshairXPos = FIELD->getPlayerXPos()+1;
				_lastCrosshairYPos = FIELD->getPlayerYPos();
			}
		}	}
	lastDirection = 2;
	
}
void Movement::moveLeft()
{
	
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if(pX > 0){
		if (FIELD->getObjectAtCoord(pX - 1, pY) != WALL) {
			
			if (lastDirection == 4) {
				col->detectBombCollision(-1, 0);
				FIELD->enterObjectInField(pX, pY, tempTileBox);
				if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
				if (FIELD->getObjectAtCoord(pX - 1, pY) == BOMB) {
					tempTileBox = BOMB;
				}
				pX--;
				FIELD->enterObjectInField(pX, pY, PLAYER);
			}
			FIELD->calculatePlayerPos();
			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
			if (pX > 0) {
				FIELD->tileField[_lastCrosshairYPos][_lastCrosshairXPos].crosshair = false;
				FIELD->tileField[FIELD->getPlayerYPos()][FIELD->getPlayerXPos()-1].crosshair = true;

				_lastCrosshairXPos = FIELD->getPlayerXPos()-1;
				_lastCrosshairYPos = FIELD->getPlayerYPos();
			}
		}
	}
	lastDirection = 4;
	
}

bool Movement::getBombCollisionStatus()
{
	return col->getBombCollisionStatus();
}

#pragma endregion

void Movement::moveAfterClick(int x, int y) {
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();


	if (((x >= (335 + (pX - 1) * 50)) && (x <= (335 + (pX) * 50))) && ((y >= (165 + (pY + 0) * 50)) && (y < (165 + (pY + 1) * 50)))) {
		moveLeft();
		//std::cout << "Left Mouse Move was triggered" << std::endl;
	}

	if (((x >= (335 + (pX + 1) * 50)) && (x <= (335 + (pX + 2) * 50))) && ((y >= (165 + (pY + 0) * 50)) && (y < (165 + (pY + 1) * 50)))) {
		moveRight();
		//std::cout << "Right Mouse Move was triggered" << std::endl;
	}

	if (((x >= (335 + (pX) * 50)) && (x <= (335 + (pX + 1) * 50))) && ((y >= (165 + (pY + 1) * 50)) && (y < (165 + (pY + 2) * 50)))) {
		moveDown();
		//std::cout << "Right Mouse Move was triggered" << std::endl;
	}

	if (((x >= (335 + (pX) * 50)) && (x <= (335 + (pX + 1) * 50))) && ((y >= (165 + (pY - 1) * 50)) && (y < (165 + pY * 50)))) {
		moveUp();
		//std::cout << "Right Mouse Move was triggered" << std::endl;
	}
	//std::cout << "Movement demand was triggered" << std::endl;
}