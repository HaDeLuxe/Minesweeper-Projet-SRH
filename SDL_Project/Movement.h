#pragma once
#include "Header.h"
#include "Field.h"
#include "Collision.h"
#include "Player.h"
#include "GameManager.h"
#include "Enemy.h"



#define BACKGROUND 1
#define WALL 2
#define PLAYER 3
#define FIELD  Field::Instance()




class Movement
{
private:
	Collision * col;
	Player * player;
	GameManager * gameManager;

	int pX, pY;
	int tempTileBox = BACKGROUND;
	int _lastCrosshairXPos = 0;
	int _lastCrosshairYPos = 0;
	int lastDirection = 1;
	bool alreadyCheckedIfCol = false;
	bool goalCollisionFlag = false;
	
public:
	Movement();
	~Movement();
	void bombCollision(); // reduces life after collision
	void ammuCollision(); // adds ammu after ammu collision
	void shieldCollision();	//add shield after shield collison
	void pillCollision();	//manages mapinstance change
	void goalCollision(); // return true if goalCollision
	bool returnGoalCollision();
	

	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	bool getBombCollisionStatus();	
	void resetBombBool();
	void resetGoalFlag();

	int getCrosshairXPos();
	int getCrosshairYPos();
	void initController();
};
