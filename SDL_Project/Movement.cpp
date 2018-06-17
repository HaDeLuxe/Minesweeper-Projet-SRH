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

void Movement::shieldCollision()
{
	if(col->detectShieldCollision(0,-1))
	lifePoints++;
}

void Movement::pillCollision()
{
	if (currentMapInstance == 1) {
		currentMapInstance = 2;
	}
	else currentMapInstance = 1;
	
	gameManager->changeMapInstance();
}

void Movement::goalCollision()
{
	goalCollisionFlag = true;
}

bool Movement::returnGoalCollision()
{
	return goalCollisionFlag;
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
					if(col->detectGoalCollision(0, -1)) goalCollision();
					if (col->detectShieldCollision(0, -1)) {
						lifePoints++;
					}
					if (col->detectPillCollision(0, -1)) {
						pillCollision();
					}
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
					if (col->detectGoalCollision(0, 1)) goalCollision();
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					if (col->detectShieldCollision(0, 1)) {
						lifePoints++;
					}
					if (col->detectPillCollision(0, 1)) {
						pillCollision();
					}
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
					if (col->detectGoalCollision(1, 0)) goalCollision();
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					if (col->detectShieldCollision(1, 0)) {
						lifePoints++;
					}
					if (col->detectPillCollision(1, 0)) {
						pillCollision();
					}
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
					if (col->detectGoalCollision(-1, 0)) {
						goalCollision();
					}
					alreadyCheckedIfCol = true;
					bombCollision();
					ammuCollision();
					if (col->detectShieldCollision(-1, 0)) {
						lifePoints++;
					}
					if (col->detectPillCollision(-1,0)) pillCollision();
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

void Movement::resetGoalFlag()
{
	goalCollisionFlag = false;
}

#pragma endregion


int Movement::getCrosshairXPos()
{
	return _lastCrosshairXPos;
}

int Movement::getCrosshairYPos()
{
	return _lastCrosshairYPos;
}

void Movement::initController()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
}


