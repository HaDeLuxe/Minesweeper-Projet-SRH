#pragma once
#include "Header.h"
#include "Windows.h"
#include "Field.h"
#include "Enums.h"
#include "text.h"
#include "Enemy.h"
#include "Textures.h"



#define FIELD Field::Instance()
extern short ammuCount;
extern int currentLevel;
extern short currentMapInstance;
extern short dirEnemy1;			//extern variable for shooting direction for all enemies (needed in Field.cpp)
extern short dirEnemy2;
extern short dirEnemy3;
extern short dirEnemy4;
extern short dirEnemy5;
extern short dirEnemy6;
extern short dirEnemy7;
extern short dirEnemy8;
extern short dirEnemy9;
extern short dirEnemy10;



class GameManager
{
private:
	Levels * levels = new Levels();
	Textures * tex = new Textures();
	class Enemy* enemy1;
	class Enemy* enemy2;
	class Enemy* enemy3;
	class Enemy* enemy4;
	class Enemy* enemy5;
	class Enemy* enemy6;
	class Enemy* enemy7;
	class Enemy* enemy8;
	class Enemy* enemy9;
	class Enemy* enemy10;

public:
	GameManager();
	~GameManager();

	void readWallData(std::string filePath);		//interprets wall placings out of Levelx.txt
	void manageLevels();			//level manager
	void changeLevel();
	void manageLevels(int level);	//choose a specific level
	void Tutorial();	//prepare the field for tutorial
	void prepareTutorial(); // helps preparing the tutorial
	void Level1();	//prepare the tutorial
	void changeMapInstance(); //changes the current mapInstance ( for wall change)
	void manageMissiles();	//manages movement for all missiles on the field
	
	void changeFlag(int crosshairX, int crosshairY);	//change flag state 
	void addAmmuCount();
	int getAmmuCount();
};
