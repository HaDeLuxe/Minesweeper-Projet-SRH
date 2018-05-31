#pragma once
#include "Header.h"
#include "Field.h"
#include "Collision.h"



#define BACKGROUND 1
#define WALL 2
#define PLAYER 3
#define FIELD  Field::Instance()

class Movement
{
private:
	Collision * col;
	int pX, pY;
	int tempTileBox = BACKGROUND;
	int _lastCrosshairXPos = 0;
	int _lastCrosshairYPos = 0;
	int lastDirection = 1;
public:
	Movement();
	~Movement();


	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	bool getBombCollisionStatus();
	void moveAfterClick(int x, int y);


};
