#pragma once
#include "Header.h"
#include "Field.h"




#define BACKGROUND 1
#define WALL 2
#define PLAYER 3
#define FIELD  Field::Instance()

class Movement
{
private:
	int pX, pY;
	int tempTileBox = BACKGROUND;
public:
	Movement();
	~Movement();

	void setTale();

	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();

	void moveAfterClick(int x, int y);


};
