#pragma once
#include "Header.h"

#include "Windows.h"
#include "Enums.h"
#include "text.h"


#define FIELD Field::Instance()

class GameManager
{
private:
	bool isSolvable = false;

public:
	GameManager();
	~GameManager();

	void renewField();
	void readWallData(std::string filePath);

};
