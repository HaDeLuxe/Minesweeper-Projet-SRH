#include "GameManager.h"

short ammuCount = 0;
int currentLevel = (int)(Levels::Tutorial);

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

 



void GameManager::readWallData(std::string filePath)
{
	FILE* file;
	fopen_s(&file, filePath.c_str(),"r");
	int x = 0;
	int x1 = 0;
	for (int y = 0; y < 15; y++) {
		char text[150];
		fgets(text, 150, file);
		while (x <= 100) {
			if (text[x] == 50) {
				FIELD->enterObjectInField(x1, y, WALL);
				x1++;				
			}
			if (text[x] == 48) {
				x1++;
			}
			if (text[x] == '6') {
				FIELD->enterObjectInField(x1, y, DOOR);
				x1++;
			}
			if (text[x] == '7') {
				FIELD->enterObjectInField(x1, y, AMMU);
				x1++;
			}
			x++;
		}
		x = 0;
		x1 = 0;
	}
	}

void GameManager::manageLevels()
{
	switch (currentLevel) {
	case static_cast<int>(Levels::Tutorial) :
		Tutorial();
		break;
	}
}

void GameManager::manageLevels(int level)
{
}

void GameManager::Tutorial()
{
	FIELD->createPlayField(50, 15);
	readWallData("Levels\\Tutorial.txt");
	FIELD->enterObjectInField(5, 5, PLAYER);
	FIELD->setRandomMines(50);
	FIELD->placeMask();
	prepareTutorial();
	enemy1 = new Enemy(15,2,4);
	enemy1->changeEnemyPos(15, 2);
	FIELD->bombsProx();
	FIELD->enterObjectInField(5, 10, SHIELD);
	
}



void GameManager::prepareTutorial()
{
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			FIELD->tileField[y][x].isShown = true;
			if (FIELD->tileField[y][x].tileType == BOMB) FIELD->tileField[y][x].tileType = BACKGROUND;
		}
	}

}

void GameManager::Level1()
{
	readWallData("Levels\\Level1.txt");
}

void GameManager::manageMissiles()
{
	if (enemy1 != NULL) {
		enemy1->spawnMissile();
		enemy1->manageMissiles();
	}
}

void GameManager::changeFlag(int crosshairX, int crosshairY)
{
	if (FIELD->tileField[crosshairY][crosshairX].isShown == false && !FIELD->tileField[crosshairY][crosshairX].flag) {
		FIELD->tileField[crosshairY][crosshairX].flag = true;
	}
	else FIELD->tileField[crosshairY][crosshairX].flag = false;
}



void GameManager::addAmmuCount()
{
	if (ammuCount <= 3) {
		ammuCount++;
	}
}

int GameManager::getAmmuCount()
{
	return ammuCount;
}


