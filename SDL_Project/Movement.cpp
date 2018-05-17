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

			//std::cout << pY;
			FIELD->enterObjectInField(pX, pY, BACKGROUND);
			pY--;
			FIELD->enterObjectInField(pX, pY, PLAYER);
			//std::cout << pY << std::endl;

		}
	}
	/*if (FIELD->getObjectAtCoord(pX, pY - 1) == BOMB) {
		FIELD->setBombsBoolToFalse();
	}*/
}



void Movement::moveDown()
{

	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pY < /*FIELD->field.size()*/ FIELD->getPlayfieldYSize() - 1) {
		if (FIELD->getObjectAtCoord(pX, pY + 1) != WALL) {
			//std::cout << pY;
			FIELD->enterObjectInField(pX, pY, BACKGROUND);
			pY++;
			FIELD->enterObjectInField(pX, pY, PLAYER);
			//std::cout << pY << std::endl;
		}
	}
	/*if (FIELD->getObjectAtCoord(pX, pY + 1) == BOMB) {
		FIELD->setBombsBoolToFalse();
	}*/
}

void Movement::moveRight()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if(pX < /*FIELD->field[pY].size()*/FIELD->getPlayfieldYSize() - 1){
		if (FIELD->getObjectAtCoord(pX + 1, pY) != WALL) {
			FIELD->enterObjectInField(pX, pY, BACKGROUND);
			pX++;
			FIELD->enterObjectInField(pX, pY, PLAYER);
		}
	}
	FIELD->calculatePlayerPos();
	std::cout << "Move to the RIGHT" << std::endl;
	std::cout << "Windowwidth: " << FIELD->getWindowWidth() << std::endl;
	std::cout << "getPlayerXPos(): " << FIELD->getPlayerXPos() << std::endl;
	std::cout << "getPlayerXPos * 50: " << FIELD->getPlayerXPos() * 50 << std::endl;
	std::cout << "xOrigin:" << FIELD->xOrigin << std::endl;
	std::cout << "__________________________________________" << std::endl;
	
}
void Movement::moveLeft()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if(pX > 0){
		if (FIELD->getObjectAtCoord(pX - 1, pY) != WALL) {
			FIELD->enterObjectInField(pX, pY, BACKGROUND);
			pX--;
			FIELD->enterObjectInField(pX, pY, PLAYER);
		}
	}
	FIELD->calculatePlayerPos();
	std::cout << "Move to the LEFT" << std::endl;
	std::cout << "Windowwidth: " << FIELD->getWindowWidth() << std::endl;
	std::cout << "getPlayerXPos(): " << FIELD->getPlayerXPos() << std::endl;
	std::cout << "getPlayerXPos * 50: " << FIELD->getPlayerXPos() * 50 << std::endl;
	std::cout << "xOrigin:" << FIELD->xOrigin << std::endl;
	std::cout << "__________________________-" << std::endl;
	
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