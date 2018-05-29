#pragma once
#include "Header.h"

#include "Windows.h"
#include "Enums.h"
#include "text.h"
#include <queue>

#define FIELD Field::Instance()

class GameManager
{
private:
	bool isSolvable = false;

public:
	GameManager();
	~GameManager();

	void checkForSolvability(int nextPositionX, int nextPositionY);
	void renewField();
	void readWallData(std::string filePath);

};
