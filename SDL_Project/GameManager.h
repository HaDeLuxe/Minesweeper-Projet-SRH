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
public:
	GameManager();
	~GameManager();

	void renewField();
	void readWallData(std::string filePath);
	void Tutorial();
	void Level1();
	void changeFlag(int crosshairX, int crosshairY);
	void addAmmuCount();
	int getAmmuCount();
};
