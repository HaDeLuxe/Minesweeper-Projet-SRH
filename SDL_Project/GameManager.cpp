#include "GameManager.h"

short ammuCount = 0;
int currentLevel = (int)(Levels::Tutorial);
short currentMapInstance = 1;
short dirEnemy1 = 0;
short dirEnemy2 = 0;
short dirEnemy3 = 0;
short dirEnemy4 = 0;
short dirEnemy5 = 0;
short dirEnemy6 = 0;
short dirEnemy7 = 0;
short dirEnemy8 = 0;
short dirEnemy9 = 0;
short dirEnemy10 = 0;

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
		case static_cast<int>(Levels::Level1) :
			Level1();
			break;
}
}

void GameManager::changeLevel()
{
if (currentLevel == static_cast<int>(Levels::Level1)) {
		currentLevel = static_cast<int>(Levels::Tutorial);
	}
	currentLevel = static_cast<int>(Levels::Level1);

	
}

void GameManager::manageLevels(int level)
{
}

void GameManager::Tutorial()
{
	FIELD->clearPlayField();
	readWallData("Levels\\Tutorial.txt");
	FIELD->enterObjectInField(1, 1, PLAYER);
	FIELD->enterObjectInField(48, 12, GOAL);
	FIELD->setRandomMines(75);
	FIELD->placeMask();
	prepareTutorial();
	
	enemy1 = new Enemy(31,12,1);
	dirEnemy1 = 1;
	enemy2 = new Enemy(25, 13, 1); 
	dirEnemy2 = 1;
	enemy3 = new Enemy(39, 1, 3);
	dirEnemy3 = 3;
	enemy4 = new Enemy(28, 14, 1);
	dirEnemy4 = 1;
	
	FIELD->enterObjectInField(0, 13, SHIELD);

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
	
	FIELD->clearPlayField();
	readWallData("Levels\\Level1.txt");
	FIELD->enterObjectInField(1, 1, PLAYER);
	FIELD->enterObjectInField(47, 13, GOAL);
	FIELD->enterObjectInField(17, 0, PILL);
	FIELD->enterObjectInField(43, 6, DOOR);
	FIELD->setRandomMines(100);
	FIELD->placeMask();
	
	enemy1 = new Enemy(21, 12, 1);
	dirEnemy1 = 1;
	enemy2 = new Enemy(33, 2, 4); 
	dirEnemy2 = 4;
	enemy3 = new Enemy(45, 2, 3);
	dirEnemy3 = 3;
	FIELD->enterObjectInField(18, 12, SHIELD);

	//Level is solvable
	int x = 1;
	int y = 1;

	while (y < 13) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y++;
	}
	while (x < 11) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y > 2) {
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
	while (y < 13) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y++;
	}
	while (x < 36) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		x++;
	}
	while (y > 6) {
		if (FIELD->getObjectAtCoord(x, y) == BOMB) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
		y--;
	}
	while (x < 47) {
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
	FIELD->bombsProx();
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
			else if(currentMapInstance == 2) readWallData("Levels/Level1(2).txt");
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
		enemy1->manageMissiles(1);
	}
	if (enemy2 != NULL) {
		enemy2->spawnMissile();
		enemy2->manageMissiles(2);
	}
	if (enemy3 != NULL) {
		enemy3->spawnMissile();
		enemy3->manageMissiles(3);
	}
	if (enemy4 != NULL) {
		enemy4->spawnMissile();
		enemy4->manageMissiles(4);
	}
	if (enemy5 != NULL) {
		enemy5->spawnMissile();
		enemy5->manageMissiles(5);
	}
	if (enemy6 != NULL) {
		enemy6->spawnMissile();
		enemy6->manageMissiles(6);
	}
	if (enemy7 != NULL) {
		enemy7->spawnMissile();
		enemy7->manageMissiles(7);
	}
	if (enemy8 != NULL) {
		enemy8->spawnMissile();
		enemy8->manageMissiles(8);
	}
	if (enemy9 != NULL) {
		enemy9->spawnMissile();
		enemy9->manageMissiles(9);
	}
	if (enemy10 != NULL) {
		enemy10->spawnMissile();
		enemy10->manageMissiles(10);
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


