#include "Movement.h"



Movement::Movement()
{

} //constructor

Movement::~Movement()
{
} //deconstructor

void Movement::setTale()
{
	FIELD->enterObjectInField(10, 10, PLAYER);
}

#pragma region Moving Functions

void Movement::moveUp()
{
	
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pY > 0) {
		if (FIELD->getObjectAtCoord(pX, pY - 1) != WALL) {
			
			
			FIELD->enterObjectInField(pX, pY, tempTileBox);
			if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
			if (FIELD->getObjectAtCoord(pX, pY-1) == BOMB) {
				tempTileBox = BOMB;
			}
			
			pY--;
			FIELD->enterObjectInField(pX, pY, PLAYER);
			
			FIELD->calculatePlayerPos();

			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
		}
	}
	
}



void Movement::moveDown()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pY <  FIELD->tileField.size() - 1) {
		if (FIELD->getObjectAtCoord(pX, pY + 1) != WALL) {

			FIELD->enterObjectInField(pX, pY, tempTileBox);
			if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
			if (FIELD->getObjectAtCoord(pX, pY + 1) == BOMB) {
				tempTileBox = BOMB;
			}

			pY++;
			FIELD->enterObjectInField(pX, pY, PLAYER);
			
			FIELD->calculatePlayerPos();
			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
		
		}
	}
	
}

void Movement::moveRight()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if(pX < FIELD->tileField[pY].size() - 1){
		if (FIELD->getObjectAtCoord(pX + 1, pY) != WALL) {
			FIELD->enterObjectInField(pX, pY, tempTileBox);
			if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
			if (FIELD->getObjectAtCoord(pX + 1, pY) == BOMB) {
				tempTileBox = BOMB;
			}
			pX++;
			FIELD->enterObjectInField(pX, pY, PLAYER);
			FIELD->calculatePlayerPos();
			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
		}
	}
	
}
void Movement::moveLeft()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if(pX > 0){
		if (FIELD->getObjectAtCoord(pX - 1, pY) != WALL) {
			FIELD->enterObjectInField(pX, pY, tempTileBox);
			if (tempTileBox == BOMB) tempTileBox = BACKGROUND;
			if (FIELD->getObjectAtCoord(pX - 1, pY) == BOMB) {
				tempTileBox = BOMB;
			}
			pX--;
			FIELD->enterObjectInField(pX, pY, PLAYER);
			
			FIELD->calculatePlayerPos();

			FIELD->floodFillOpenFieldsUR(FIELD->getPlayerXPos(), FIELD->getPlayerYPos());
			
		}
	}
	
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