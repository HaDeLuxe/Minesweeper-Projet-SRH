#include "Movement.h"


Movement::Movement()
{
	col = new Collision();
	player = new Player();
	gameManager = new GameManager();
} //constructor

Movement::~Movement()
{
} //deconstructor

void Movement::bombCollision() //do this when collision with bomb detected
{
	if (col->getBombCollisionStatus()) {
		player->reduceLife();
	}
}

void Movement::ammuCollision() //do this when collision with ammu detected
{
	if (col->getAmmuCollisionStatus()) {
		gameManager->addAmmuCount();
	}
}



#pragma region Moving Functions

void Movement::moveUp()
{
	FIELD->calculatePlayerPos();
	pX = FIELD->getPlayerXPos();
	pY = FIELD->getPlayerYPos();
	alreadyCheckedIfCol = false;
	if (pY > 0) {
		if (FIELD->getObjectAtCoord(pX, pY - 1) != WALL && !FIELD->getFlagStatus(pX,pY-1) && FIELD->getObjectAtCoord(pX, pY - 1) != DOOR) {
			
			if (lastDirection == 1) {
				if (!alreadyCheckedIfCol) {
					col->detectBombCollision(0, -1);
					col->detectAmmuCollision(0, -1);
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					col->resetCollisionBool();
					col->resetAmmuCollisionBool();
				}
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
	alreadyCheckedIfCol = false;
	if (pY <  static_cast<int>(FIELD->tileField.size()) - 1) {
		if (FIELD->getObjectAtCoord(pX, pY + 1) != WALL && !FIELD->getFlagStatus(pX, pY+1) && FIELD->getObjectAtCoord(pX, pY + 1) != DOOR) {
			
			if (lastDirection == 3) {
				if (!alreadyCheckedIfCol) {
					col->detectBombCollision(0, 1);
					col->detectAmmuCollision(0, 1);
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					col->resetCollisionBool();
					col->resetAmmuCollisionBool();
				}
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
	alreadyCheckedIfCol = false;
	if(pX < static_cast<int>(FIELD->tileField[pY].size() - 1)){
		if (FIELD->getObjectAtCoord(pX + 1, pY) != WALL && !FIELD->getFlagStatus(pX+1, pY) && FIELD->getObjectAtCoord(pX+1, pY) != DOOR) {
			
			if (lastDirection == 2) {
				if (!alreadyCheckedIfCol) {
					col->detectBombCollision(1, 0);
					col->detectAmmuCollision(1, 0);
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					col->resetCollisionBool();
					col->resetAmmuCollisionBool();
				}
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
	alreadyCheckedIfCol = false;
	if(pX > 0){
		if (FIELD->getObjectAtCoord(pX - 1, pY) != WALL && !FIELD->getFlagStatus(pX-1,pY) && FIELD->getObjectAtCoord(pX-1, pY) != DOOR) {
			
			if (lastDirection == 4) {
				if (!alreadyCheckedIfCol) {
					col->detectBombCollision(-1, 0);
					col->detectAmmuCollision(-1, 0);
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					col->resetCollisionBool();
					col->resetAmmuCollisionBool();
				}
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

void Movement::resetBombBool()
{
	col->resetCollisionBool();
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

int Movement::getCrosshairXPos()
{
	return _lastCrosshairXPos;
}

int Movement::getCrosshairYPos()
{
	return _lastCrosshairYPos;
}
