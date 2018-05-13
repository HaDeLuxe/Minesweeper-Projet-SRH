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
		std::cout << pY;
		FIELD->enterObjectInField(pX, pY, BACKGROUND);
		pY--;
		FIELD->enterObjectInField(pX, pY, PLAYER);
		std::cout << pY << std::endl;
	}

}

void Movement::moveRight()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pX < FIELD->field[1].size() - 1) {
		std::cout << FIELD->field[1].size();
		FIELD->enterObjectInField(pX, pY, BACKGROUND);
		pX++;
		FIELD->enterObjectInField(pX, pY, PLAYER);
	}
}

void Movement::moveDown()
{

	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	if (pY < FIELD->field.size() - 1) {
		std::cout << pY;
		FIELD->enterObjectInField(pX, pY, BACKGROUND);
		pY++;
		FIELD->enterObjectInField(pX, pY, PLAYER);
		std::cout << pY << std::endl;
	}
}

void Movement::moveLeft()
{
	if (pX > 0) {
		FIELD->calculatePlayerPos();
		pX = FIELD->getPlayerXPos();
		pY = FIELD->getPlayerYPos();
		FIELD->enterObjectInField(pX, pY, BACKGROUND);
		pX--;
		FIELD->enterObjectInField(pX, pY, PLAYER);
	}
}

#pragma endregion

void Movement::moveAfterClick(int x, int y) {
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();


	if (((x >= (335 + (pX - 1) * 50)) && (x <= (335 + (pX) * 50))) && ((y >= (165 + (pY + 0) * 50)) && (y < (165 + (pY + 1) * 50)))) {
		moveLeft();
		std::cout << "Left Mouse Move was triggered" << std::endl;
	}

	if (((x >= (335 + (pX + 1) * 50)) && (x <= (335 + (pX + 2) * 50))) && ((y >= (165 + (pY + 0) * 50)) && (y < (165 + (pY + 1) * 50)))) {
		moveRight();
		std::cout << "Right Mouse Move was triggered" << std::endl;
	}

	if (((x >= (335 + (pX) * 50)) && (x <= (335 + (pX + 1) * 50))) && ((y >= (165 + (pY + 1) * 50)) && (y < (165 + (pY + 2) * 50)))) {
		moveDown();
		std::cout << "Right Mouse Move was triggered" << std::endl;
	}

	if (((x >= (335 + (pX) * 50)) && (x <= (335 + (pX + 1) * 50))) && ((y >= (165 + (pY - 1) * 50)) && (y < (165 + pY * 50)))) {
		moveUp();
		std::cout << "Right Mouse Move was triggered" << std::endl;
	}
	std::cout << "Movement demand was triggered" << std::endl;
}