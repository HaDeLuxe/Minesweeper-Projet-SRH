#pragma once
#include "Field.h"
#include "Header.h"

#define FIELD Field::Instance()

class Enemy
{
private:

	
	int x;				//x position enemy
	int y;				//y position enemy
	int direction = 4;	//Move directions for missiles up = 1, right = 2, down = 3, left = 4

	typedef struct missile { //creating a struct for missiles with the own posiitons
		int mX = 0;
		int mY = 0;
	}missile;

	std::vector<missile> missiles;	//vector with all the active missiles for this enemy
public:
	Enemy(int pX, int pY, int dir);			//constructor for class enemy who draws it immediately on the field.
	~Enemy();

	void spawnMissile(int steps);	//spawn a new missiles on the adjacent position to the enemy
	void manageMissiles();			//manages the position of all the missiles in the vector missiles and moves them
	void resetMissilesOnField();	//cleans the field of missiles
	void destroyMissile(int x, int y); // destroy a specific missile
};

