#include "Field.h"



Field::Field()
{
	
}

Field* Field::m_pInstance = NULL;

Field * Field::Instance()
{
	if (!m_pInstance) {
		m_pInstance = new Field;
	}
	return m_pInstance;
}

Field::~Field()
{
}

#pragma region Create Field and Renderer

void Field::createPlayField(int pX, int pY)
{

	
	//tileField[0][0].isShown = false;
	tileField.reserve(15);
	

	for (int y = 0; y < pY; y++) {
		std::vector<tile> temp;
		for (int x = 0; x < pX; x++) {
			tile tileEmpty;
			tileEmpty.tileType = BACKGROUND;
			temp.push_back(tileEmpty);
		}
		tileField.push_back(temp);
	}
	enterObjectInField(2, 2, PLAYER);
	
	enterObjectInField(10, 10, BOMB);
	enterObjectInField(10, 12, BOMB);
	enterObjectInField(10, 14, BOMB);
	enterObjectInField(12, 12, BOMB);
	enterObjectInField(48, 8, DEST);
	
}




void Field::createWindow() {
	win = SDL_CreateWindow("Minesweeper Adventure", 0, 30, 1920, 1010, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
}

void Field::createRenderer() {
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
}
#pragma endregion

#pragma region Getter/Setter

SDL_Renderer * Field::getRenderer()
{
	return ren;
}

SDL_Window* Field::getWindow() {
	return win;
}

void Field::setRendererColor(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(ren, r, g, b, a);
}

void Field::renderClear()
{
	SDL_RenderClear(ren);
}

#pragma endregion


void Field::calculatePlayerPos()
{
	for (int y = 0; y < static_cast<int>(tileField.size()); y++) {
		for (int x = 0; x < static_cast<int>(tileField[y].size()); x++) {
			if (static_cast<int>(tileField[y][x].tileType) == PLAYER) {
				playerXPos = x;
				playerYPos = y;
			}
		}
	}
}

#pragma region object draw functions
void Field::drawRect(int x1, int y1, int x2, int y2)
{
	SDL_Rect rect;
	rect.h = y2;
	rect.w = x2;
	rect.x = x1;
	rect.y = y1;
	//SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	SDL_RenderDrawRect(ren, &rect);
}

void Field::drawFillRect(int x1, int y1, int x2, int y2)
{
	SDL_Rect rect;
	rect.h = y2;
	rect.w = x2;
	rect.x = x1;
	rect.y = y1;
	//SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	SDL_RenderFillRect(ren, &rect);
}

void Field::drawFillCircle(int x, int y, int radius)
{
	//SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	for (int w = 0; w < radius * 2; w++)
	{
		for (int h = 0; h < radius * 2; h++)
		{
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx*dx + dy * dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(ren, x + 25 + dx, y + 25 + dy);
			}
		}
	}
}

void Field::drawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(ren, x1, y1, x2, y2);
}

void Field::drawTransparentRect(int x1, int y1, int x2, int y2)
{
	
}

void Field::drawHUD()
{
	if (ammuCount <= 0) {
		tex->renderTexture(tex->HUD_ammu, ren, 700, 910, 32, 32);
		tex->renderTexture(tex->HUD_ammu, ren, 740, 910, 32, 32);
		tex->renderTexture(tex->HUD_ammu, ren, 780, 910, 32, 32);
	}
	if (ammuCount == 1) {
		tex->renderTexture(tex->ammu, ren, 700, 910, 32, 32);
		tex->renderTexture(tex->HUD_ammu, ren, 740, 910, 32, 32);
		tex->renderTexture(tex->HUD_ammu, ren, 780, 910, 32, 32);
	}
	if (ammuCount == 2) {
		tex->renderTexture(tex->ammu, ren, 700, 910, 32, 32);
		tex->renderTexture(tex->ammu, ren, 740, 910, 32, 32);
		tex->renderTexture(tex->HUD_ammu, ren, 780, 910, 32, 32);
	}
	if (ammuCount == 3) {
		tex->renderTexture(tex->ammu, ren, 700, 910, 32, 32);
		tex->renderTexture(tex->ammu, ren, 740, 910, 32, 32);
		tex->renderTexture(tex->ammu, ren, 780, 910, 32, 32);
	}
}


#pragma endregion Hier sind die Funktionen um Objekte wie Kreise und Rechtecke zu zeichnen.

#pragma region getter
int Field::getPlayerXPos()
{
	return playerXPos;
}

int Field::getPlayerYPos()
{
	return playerYPos;
}

int Field::getPlayfieldXSize()
{
	//return (int)field[0].size();
	return (int)tileField[0].size();
}

int Field::getPlayfieldYSize()
{
	//return (int)field.size();
	return (int)tileField.size();
}

int Field::getWindowWidth()
{
	
	return SDL_GetWindowSurface(win)->w;
}

void Field::getDirection(int dir)
{
	lastDirection = dir;
}

int Field::getObjectAtCoord(int x, int y)
{
	//return field[y][x];
	return tileField[y][x].tileType;
}

#pragma endregion

void Field::enterObjectInField(int x, int y, int type)
{
	//field[y][x] = type;
	tileField[y][x].tileType = type;
}

bool Field::getFlagStatus(int x, int y)
{
	return tileField[y][x].flag;
}




int Field::getCorrectFlags()
{
	int correctFlagsCount = 0;
	for (int y = 0; y < tileField.size(); y++) {
		for (int x = 0; x < tileField.size(); x++) {
			if (tileField[y][x].tileType == BOMB && tileField[y][x].flag == true) {
				correctFlagsCount++;
			}
		}
	}
	return correctFlagsCount;
}

bool Field::bombCollision()
{
	return tileField[playerYPos][playerXPos].tileType == BOMB;
}

void Field::placeMask()
{
	for (int y = 0; y < getPlayfieldYSize(); y++) {
		for (int x = 0; x < getPlayfieldXSize(); x++) {
			if (tileField[y][x].tileType != PLAYER && tileField[y][x].tileType != DOOR) {
				tileField[y][x].isShown = false;
			}
			if (tileField[y][x].tileType == WALL) tileField[y][x].isShown = true;
		}
	}
}

void Field::bombsProx()
{
	calculatePlayerPos();
	
	
		for (int y = 0; y < static_cast<int>(tileField.size()); y++) {
			for (int x = 0; x < static_cast<int>(tileField[y].size()); x++) {
				if (y != tileField.size() - 1) {
					if (tileField[y+1][x].tileType  == BOMB) {
						
						tileField[y][x].bombcount++;
					}
				}
				if (y != 0) {
					if (tileField[y-1][x].tileType == BOMB) {
						
						tileField[y][x].bombcount++;
					}
				}

				if (x != 0) {
					if (tileField[y][x-1].tileType == BOMB) {
						
						tileField[y][x].bombcount++;
					}
				}

				if (x != tileField[y].size() - 1) {
					if (tileField[y][x+1].tileType == BOMB) {
						tileField[y][x].bombcount++;
					}
				}

				if (y != tileField.size() - 1 && x != tileField[y].size() - 1) {
					if (tileField[y+1][x+1].tileType == BOMB) {
						tileField[y][x].bombcount++;
					}
				}

				if (y != tileField.size() - 1 && x != 0) {
					if (tileField[y+1][x-1].tileType == BOMB) {
						tileField[y][x].bombcount++;
					}
				}

				if (y != 0 && x != 0) {
					if ( tileField[y-1][x-1].tileType == BOMB) {
						tileField[y][x].bombcount++;
					}
				}

				if (y != 0 && x != tileField[y].size() - 1) {
					if ( tileField[y-1][x+1].tileType == BOMB) {
						tileField[y][x].bombcount++;
					}
				}
				
				if (getObjectAtCoord(x, y) == BOMB) tileField[y][x].bombcount = 0;
			}
			//std::cout << std::endl;
		}
		
	
}

int Field::returnBombCount(int x, int y) {
	return tileField[y][x].bombcount;
}

void Field::setRandomWalls() //nicht benutzt in momentenan Build, da es nocht nicht möglich ist gute, spielbare Maps zu bauen
{
	int maxWallsCount = 4;
	int i = 1;
	int x = 0;
	int y = 0;
	int beginDir = 0;
	int secondDir = 0;
	int count = 0;
	(srand((unsigned int)time(NULL)));
	while (i <= maxWallsCount) {

		count = 0;
		x = rand() % 50;
		y = rand() % 15;
		int a = (rand() % 50) + 5;
		int b = (rand() % 50);
		beginDir = rand() % 4;
		secondDir = rand() % 2;
		

		if (tileField[y][x].tileType != WALL) {
			if (x > 1 && x < static_cast<int>(tileField[0].size()) - 1 && y > 1 && y < static_cast<int>(tileField.size()) - 1) {
				if (tileField[y-1][x].tileType == WALL)
					count++;
				if (tileField[y+1][x].tileType == WALL)
					count++;
				if (tileField[y][x+1].tileType == WALL)
					count++;
				if (tileField[y][x-1].tileType == WALL)
					count++;

				int tempx, tempy;
				
			
				enterObjectInField(x, y, WALL);
				tempx = x;
				tempy = y;
				i++;

				switch (beginDir) {
				case 0: //down
					for (int m = 0; m < a; m++) {
						if (count <= 2 && tempy < static_cast<int>(tileField.size()) - 1) {
							tempy++;
							enterObjectInField(tempx, tempy, WALL);
							switch (secondDir) {
							case 0: // right
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempx < static_cast<int>(tileField[0].size()) - 1) {
										tempx++;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							case 1: //left
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempx > 0) {
										tempx--;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							}
						}
					}
					break;
				case 1: //up
					for (int m = 0; m < a; m++) {
						if (count <= 2 && tempy > 1 ) {
							tempy--;
							enterObjectInField(tempx, tempy, WALL);
							switch (secondDir) {
							case 0: // right
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempx < static_cast<int>(tileField[0].size()) - 1) {
										tempx++;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							case 1: //left
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempx > 0) {
										tempx--;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							}
						}
					}
					break;
				case 2: //right
					for (int m = 0; m < a; m++) {
						if (count <= 2 && tempx < static_cast<int>(tileField[0].size() -1)) {
							tempx++;
							enterObjectInField(tempx, tempy, WALL);
							switch (secondDir) {
							case 0: // up
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempy > 1) {
										tempy--;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							case 1: //down
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempy < static_cast<int>(tileField.size() - 1)) {
										tempy++;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							}
						}
					}
					break;
				case 3: //left
					for (int m = 0; m < a; m++) {
						if (count <= 2 && tempx > 0) {
							tempx--;
							enterObjectInField(tempx, tempy, WALL);
							switch (secondDir) {
							case 0: // up
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempy > 1) {
										tempy--;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							case 1: //down
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempy <  static_cast<int>(tileField.size() - 1)) {
										tempy++;
										enterObjectInField(tempx, tempy, WALL);
									}
								}
								break;
							}
						}
					}
					break;
				}				
			}
		}		
		
	}

}

void Field::setRandomMines()
{
	int maxMinesCount = 50;
	int i = 1;
	int x = 0;
	int y = 0;
	srand((unsigned int)time(NULL));
	while (i < maxMinesCount) {
		x = rand() % 50;
		y = rand() % 15;
		if (tileField[y][x].tileType == BACKGROUND) {
			enterObjectInField(x, y, BOMB);
			i++;
		}
	}
	bombsProx();
}

void Field::floodFillOpenFieldsUR(int nextPositionX, int nextPositionY)
{


	if (nextPositionX >= 0 && nextPositionY >= 0 && nextPositionX < static_cast<int>(tileField[1].size()) && nextPositionY < static_cast<int>(tileField.size())) {
	

		if (tileField[nextPositionY][nextPositionX].isShown == true) {
			return;
		}
		if (tileField[nextPositionY][nextPositionX].isShown == false) {
			if(tileField[nextPositionY][nextPositionX].bombcount != 0){
				tileField[nextPositionY][nextPositionX].isShown = true;
				return;
			}
			if (tileField[nextPositionY][nextPositionX].tileType == WALL) {
				return;
			}

			//return;
		}
		
		tileField[nextPositionY][nextPositionX].isShown = true;
		floodFillOpenFieldsUR(nextPositionX, nextPositionY-1);
		floodFillOpenFieldsUR(nextPositionX+1, nextPositionY);
		floodFillOpenFieldsUR(nextPositionX, nextPositionY+1);
		floodFillOpenFieldsUR(nextPositionX-1, nextPositionY);
		
	}
	//return;
	
}



void Field::initializeTextC() {
	textC->TTF_Initiate();
	textC->preIntializeTexts(ren);
}

void Field::initializeTex()
{
	tex->preLoadTextures(ren);
}


void Field::drawField()
{
	//std::cout << "Lifepoints (3) in Field.cpp: " << lifePoints << std::endl;
	SDL_SetRenderDrawBlendMode(FIELD->getRenderer(), SDL_BLENDMODE_NONE);

	int r = 0;
	int c = 0;

	for (int y = 0; y < static_cast<int>(tileField.size()) ; y++) {/*field.size()*/
		for (int x = 0; x < static_cast<int>(tileField[y].size()) ; x++) {/*field[y].size()*/ /*25*/
			xOrigin = (getWindowWidth()/2) - (playerXPos * 50) ;
			

			if (tileField[y][x].tileType == BACKGROUND) {/*field[y][x]*/
				setRendererColor(100, 100, 255, 50);

				drawRect(xOrigin + c*50, 115 + r * 50, 50, 50);
				//tex->renderTexture(tex->loadTexture("Assets//meteorBrown_med1.png", ren), ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
			}
			
			if (tileField[y][x].tileType == BOMB) {
				setRendererColor(100, 100, 255, 50);
				/*drawRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
				drawFillCircle(xOrigin + c * 50, 115 + r * 50, 25);*/
				drawRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
				tex->renderTexture(tex->bombLaser, ren, xOrigin + c * 50+12, 115 + r * 50+12, 25, 25);
			}

			if (tileField[y][x].tileType == DEST) {
				setRendererColor(255, 255, 255, 255);
				drawFillCircle(xOrigin + c * 50, 115 + r * 50, 25);
			}
			if (returnBombCount(x, y) == 1 && getObjectAtCoord(x,y)) {
				textC->renderNumber(1, ren, xOrigin + c * 50+15, 115 + r * 50+10, 20, 35);
			}
			int bombCount = returnBombCount(x, y);
			if (bombCount == 2) {
				textC->renderNumber(2, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 3) {
				textC->renderNumber(3, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 4) {
				textC->renderNumber(4, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 5) {
				textC->renderNumber(5, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 6) {
				textC->renderNumber(6, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 7) {
				textC->renderNumber(7, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 8) {
				textC->renderNumber(8, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (bombCount == 9) {
				textC->renderNumber(9, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 20, 35);
			}
			if (tileField[y][x].tileType == AMMU) {
				tex->renderTexture(tex->ammu, ren, xOrigin + c * 50 + 9, 115 + r * 50 + 9, 32, 32);
			}
			if (!tileField[y][x].isShown) {
				setRendererColor(0, 0, 150, 255);
				//drawFillRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
				setRendererColor(100, 100, 255, 50);
				drawRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
				tex->renderTexture(tex->maskTex, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
			}
			if (tileField[y][x].tileType == WALL) {
				
				setRendererColor(100, 100, 255, 50);
				drawRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
				//drawFillRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
			
				tex->renderTexture(tex->wallTex, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
			}
			if (tileField[y][x].tileType == PLAYER) {
				setRendererColor(100, 100, 255, 50);
				drawRect(xOrigin + c * 50, 115 + r * 50, 50, 50);
				//drawFillCircle(xOrigin + c * 50, 115 + r * 50, 25);
				
				if (lastDirection == 1) {
					tex->renderTexture(tex->playerTexUp, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 3) tex->renderTexture(tex->playerDam1Up, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 2) tex->renderTexture(tex->playerDam2Up, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 1) tex->renderTexture(tex->playerDam3Up, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
				}
				if (lastDirection == 2) {
					tex->renderTexture(tex->playerTexRight, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 3) tex->renderTexture(tex->playerDam1Right, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 2) tex->renderTexture(tex->playerDam2Right, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 1) tex->renderTexture(tex->playerDam3Right, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
				}
				if (lastDirection == 3) {
					tex->renderTexture(tex->playerTexDown, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 3) tex->renderTexture(tex->playerDam1Down, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 2) tex->renderTexture(tex->playerDam2Down, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 1) tex->renderTexture(tex->playerDam3Down, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
				}
				if (lastDirection == 4) {
					tex->renderTexture(tex->playerTexLeft, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 3) tex->renderTexture(tex->playerDam1Left, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 2) tex->renderTexture(tex->playerDam2Left, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
					if (lifePoints == 1) tex->renderTexture(tex->playerDam3Left, ren, xOrigin + c * 50, 115 + r * 50, 50, 50);
				}

			}
			if (tileField[y][x].tileType == DOOR) {
				tex->renderTexture(tex->doorEnemy, ren, xOrigin + c * 50, 115 + r * 50+4, 50, 41);
			}
			if (tileField[y][x].crosshair == true) {
				tex->renderTexture(tex->crosshairTex, ren, xOrigin + c * 50+2, 115 + r * 50+2, 45, 45);
			}
			if (tileField[y][x].flag == true) {
				tex->renderTexture(tex->flag, ren, xOrigin + c * 50 + 15, 115 + r * 50 + 10, 19, 30);
			}
			if (tileField[y][x].tileType == ENEMY) {
				tex->renderTexture(tex->doorEnemy, ren, xOrigin + c * 50, 115 + r * 50 + 4, 50, 41);
			}
			if (tileField[y][x].missile == true) {
				if(direction == 1) tex->renderTexture(tex->laserUp, ren, xOrigin + c * 50 + 20, 115 + r * 50, 10, 50);
				if(direction == 2) tex->renderTexture(tex->laserRight, ren, xOrigin + c * 50, 115 + r * 50 + 20, 50, 10);
				if(direction == 3) tex->renderTexture(tex->laserDown, ren, xOrigin + c * 50 + 20, 115 + r * 50, 10, 50);
				if(direction == 4) tex->renderTexture(tex->laserLeft, ren, xOrigin + c * 50, 115 + r * 50 + 20, 50, 10);
			}
			
			c++;
			if (c >= static_cast<int>(tileField[r].size()) ) c = 0;

			drawHUD();

		}
		r++;
		if (r >= static_cast<int>(tileField.size())) r = 0;
	}

	SDL_RenderPresent(ren);
}

