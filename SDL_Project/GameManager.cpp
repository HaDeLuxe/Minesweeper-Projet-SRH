#include "GameManager.h"



GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

 void GameManager::checkForSolvability(int x, int y)
{
	 struct coordinate { int x, y; };
	 std::queue<coordinate> to_check;
	 to_check.push({ x,y });

	 while (!to_check.empty()) {
		 auto top = to_check.front();
		 to_check.pop();
		 if ((top.x >= 0 && top.x < 50) && (top.y >= 0 && top.y < 15)) {
			 if (FIELD->tileField[y][x].tileType == DEST) {
				 std::cout << "Destination has been found" << std::endl;
				 isSolvable = true;
				 return;
			 }
			 if (FIELD->tileField[y][x].tileType == WALL || FIELD->tileField[y][x].tileType == BOMB) {
				 return;
			 }
			 to_check.push({ top.x, top.y + 1 });
			 to_check.push({ top.x, top.y - 1 });
			 to_check.push({ top.x + 1,top.y });
			 to_check.push({ top.x - 1, top.y });
		 }
	 }	
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
		checkForSolvability(2,2);
		isSolvable = true;
	}
}

void GameManager::readWallData(std::string filePath)
{
	FILE* file;
	fopen_s(&file, "Assets\\Level1.txt","r");
	char text[100];
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


