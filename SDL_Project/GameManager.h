#pragma once
#include "Header.h"
#include "Windows.h"
#include "Field.h"
#include "Enums.h"
#include "text.h"
#include "Enemy.h"



#define FIELD Field::Instance()
extern short ammuCount;
extern int currentLevel;

class GameManager
{
private:
	bool isSolvable = false;
	Levels * levels = new Levels();
	Enemy* enemy1 = NULL;
	Enemy* enemy2 = NULL;
	Enemy* enemy3 = NULL;
	Enemy* enemy4 = NULL;
	Enemy* enemy5 = NULL;
	Enemy* enemy6 = NULL;
	Enemy* enemy7 = NULL;
	Enemy* enemy8 = NULL;
	Enemy* enemy9 = NULL;
	Enemy* enemy10 = NULL;

public:
	GameManager();
	~GameManager();

	void renewField();
	void readWallData(std::string filePath);
	void Tutorial();
	void TutorialRemoveMask();
	void Level1();

	void manageMissiles(/*std::vector<Enemy>*/);
	
	void changeFlag(int crosshairX, int crosshairY);
	void addAmmuCount();
	int getAmmuCount();
};
