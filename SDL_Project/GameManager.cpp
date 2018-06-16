#include "GameManager.h"

short ammuCount = 0;
int currentLevel = (int)(Levels::Tutorial);
short currentMapInstance = 1;

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
	FIELD->enterObjectInField(1, 1, PLAYER);
	FIELD->setRandomMines(100);
	//FIELD->placeMask();
	prepareTutorial();
	//enemy1 = new Enemy(5, 14, 1);
	enemy1 = new Enemy(31,12,3);
	enemy2 = new Enemy(25, 13, 1); //25
	enemy3 = new Enemy(39, 1, 4);
	enemy4 = new Enemy(28, 14, 1);
	
	FIELD->enterObjectInField(5, 10, SHIELD);

	// Level is solvable:
	int x = 1;
	int y = 1;
	while (x < 6) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y < 7) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y++;
	}
	while (x > 2) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x--;
	}
	while (y < 13) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y++;
	}
	while (x < 10) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y > 12) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y--;
	}
	while (x < 15) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y > 1) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y--;
	}
	while (x < 27) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y < 9) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y++;
	}
	while (x < 40) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y < 12) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y++;
	}
	while (x < 48) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}

	FIELD->bombsProx();
	
}



void GameManager::prepareTutorial()
{
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 9; x++) {
			FIELD->tileField[y][x].isShown = true;
			if (FIELD->tileField[y][x].tileType == BOMB) FIELD->tileField[y][x].tileType = BACKGROUND;
		}
	}
	FIELD->enterObjectInField(2, 6, BOMB);
	FIELD->enterObjectInField(4, 8, BOMB);
	FIELD->enterObjectInField(9, 7, PILL);

}

void GameManager::Level1()
{
	readWallData("Levels\\Level1.txt");
}

void GameManager::changeMapInstance()
{
	
		FIELD->removeAllWalls();
		switch (currentLevel) {
		case (int)Levels::Tutorial:
			if (currentMapInstance == 1)	readWallData("Levels/Tutorial.txt");
			else if (currentMapInstance == 2) readWallData("Levels/Tutorial 2.txt");
			break;
		case (int)Levels::Level1:
			if (currentMapInstance == 1) readWallData("Levels/Level1.txt");
			else readWallData("Levels/Level1(2)");
			break;
		case (int)Levels::Level2:
			if (currentMapInstance == 1) readWallData("Levels/Level2.txt");
			else readWallData("Levels/Level2(2).txt");
			break;
		case (int)Levels::Level3:
			if (currentMapInstance == 1) readWallData("Levels/Level3.txt");
			else readWallData("Levels/Level3(2).txt");
			break;
		case (int)Levels::Level4:
			if (currentMapInstance == 1) readWallData("Levels/Level4.txt");
			else readWallData("Levels/Level4(2)");
			break;
		}
}

void GameManager::manageMissiles()
{
	
	if (enemy1 != NULL) {
		enemy1->spawnMissile();
		enemy1->manageMissiles();
	}
	if (enemy2 != NULL) {
		enemy2->spawnMissile();
		enemy2->manageMissiles();
	}
	if (enemy3 != NULL) {
		enemy3->spawnMissile();
		enemy3->manageMissiles();
	}
	if (enemy4 != NULL) {
		enemy4->spawnMissile();
		enemy4->manageMissiles();
	}
	if (enemy5 != NULL) {
		enemy5->spawnMissile();
		enemy5->manageMissiles();
	}
	if (enemy6 != NULL) {
		enemy6->spawnMissile();
		enemy6->manageMissiles();
	}
	if (enemy7 != NULL) {
		enemy7->spawnMissile();
		enemy7->manageMissiles();
	}
	if (enemy8 != NULL) {
		enemy8->spawnMissile();
		enemy8->manageMissiles();
	}
	if (enemy9 != NULL) {
		enemy9->spawnMissile();
		enemy9->manageMissiles();
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


