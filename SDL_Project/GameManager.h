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

class GameManager
{
private:
	bool isSolvable = false;
	Levels * levels = new Levels();
	Textures * tex = new Textures();
	class Enemy* enemy1 = NULL;
	class Enemy* enemy2 = NULL;
	class Enemy* enemy3 = NULL;
	class Enemy* enemy4 = NULL;
	class Enemy* enemy5 = NULL;
	class Enemy* enemy6 = NULL;
	class Enemy* enemy7 = NULL;
	class Enemy* enemy8 = NULL;
	class Enemy* enemy9 = NULL;
	class Enemy* enemy10 = NULL;

public:
	GameManager();
	~GameManager();

	void readWallData(std::string filePath);
	void manageLevels();
	void manageLevels(int level);
	void Tutorial();
	void prepareTutorial();
	void Level1();

	void manageMissiles(/*std::vector<Enemy>*/);
	
	void changeFlag(int crosshairX, int crosshairY);
	void addAmmuCount();
	int getAmmuCount();
};
