#pragma once
#include "Header.h"
#include "Windows.h"
#include "Field.h"
#include "Enums.h"
#include "text.h"


#define FIELD Field::Instance()
extern short ammuCount;

class GameManager
{
private:
	bool isSolvable = false;
public:
	GameManager();
	~GameManager();

	void renewField();
	void readWallData(std::string filePath);

	void changeFlag(int crosshairX, int crosshairY);
	void addAmmuCount();
	int getAmmuCount();
};
