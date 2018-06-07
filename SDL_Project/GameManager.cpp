#include "GameManager.h"

short ammuCount = 0;
int currentLevel = (int)(Levels::Tutorial);

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

 

void GameManager::renewField()
{
	
	while (!isSolvable) {
		for (int y = 0; y < FIELD->getPlayfieldYSize(); y++) {
			for (int x = 0; x < FIELD->getPlayfieldXSize(); x++) {
				if (FIELD->getObjectAtCoord(x, y) == WALL) FIELD->enterObjectInField(x, y, BACKGROUND);
			}
		}
		FIELD->setRandomWalls();
		FIELD->setRandomMines();
		
		isSolvable = true;
	}
}

void GameManager::readWallData(std::string filePath)
{
	FILE* file;
	fopen_s(&file, "Levels\\Tutorial.txt","r");
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

void GameManager::Tutorial()
{
	readWallData("Levels\\Level1.txt");
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			FIELD->enterObjectInField(x, y, BACKGROUND);
		}
	}
	FIELD->enterObjectInField(5, 5, PLAYER);

	Enemy * enemy1 = new Enemy(5,10, 4);
	Enemy * enemy2 = new Enemy(14, 2, 4);
	enemy1->spawnMissile(3);
	enemy2->spawnMissile(4);


}

void GameManager::TutorialRemoveMask()
{
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			FIELD->tileField[y][x].isShown = true;
		}
	}
}

void GameManager::Level1()
{
	
}

void GameManager::manageMissiles(/*std::vector<Enemy> pTemp*/)
{
	for (int i = 0; i < static_cast<int>(enemies.size()); i++) {
		enemies[i].manageMissiles();
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


