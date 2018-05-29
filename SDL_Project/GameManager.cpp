#include "GameManager.h"



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
	fopen_s(&file, "Assets\\Level1.txt","r");
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
			x++;
		}
		x = 0;
		x1 = 0;
	}
		
	}


