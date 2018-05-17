#include "Field.h"



Field::Field()
{
	game = new Game();
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
		/*std::vector<int> temp;
		std::vector<int> temp2;*/
		std::vector<tile> temp;
		for (int x = 0; x < pX; x++) {
			/*temp.push_back(BACKGROUND);
			temp2.push_back(0);*/
			tile tileEmpty;
			temp.push_back(tileEmpty);
		}
		/*field.push_back(temp);
		bombs.push_back(temp2);*/
		tileField.push_back(temp);
	}
	enterObjectInField(2, 2, PLAYER);
	
	enterObjectInField(10, 10, BOMB);
	enterObjectInField(10, 12, BOMB);
	enterObjectInField(10, 14, BOMB);
	enterObjectInField(12, 12, BOMB);
	
}




void Field::createWindow() {
	win = SDL_CreateWindow("Minesweeper Adventure", 0, 20, 1920, 1080, SDL_WINDOW_SHOWN);
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
	for (int i = 0; i < tileField.size(); i++) {/*field.size()*/
		for (int m = 0; m < tileField[i].size(); m++) {/*field[i].size()*/
			if (tileField[i][m].tileType == PLAYER) {
				playerXPos = m;
				playerYPos = i;
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


void Field::placeMask()
{
	for (int y = 0; y < getPlayfieldYSize(); y++) {
		for (int x = 0; x < getPlayfieldXSize(); x++) {
			if (tileField[y][x].tileType != PLAYER && tileField[y][x].tileType != WALL) {
				tileField[y][x].isShown = false;
			}
		}
	}
}

void Field::setBombsBoolToFalse()
{
	bombCalculated = false;
}

void Field::bombsProx()
{
	calculatePlayerPos();
	
	if (!bombCalculated) {
		//reinitalizeBombCounts();
		for (int i = 0; i < tileField.size(); i++) {/*field.size()*/
			for (int m = 0; m < tileField[i].size(); m++) {/*field[i].size()*/
				if (i != tileField.size() - 1) {/*field.size()*/
					if (tileField[i+1][m].tileType  == BOMB) {/*field[i + 1][m]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != 0) {
					if (tileField[i-1][m].tileType == BOMB) {/*field[i - 1][m]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (m != 0) {
					if (tileField[i][m-1].tileType == BOMB) {/*field[i][m - 1]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (m != tileField[i].size() - 1) {/*field[i].size()*/
					if (tileField[i][m+1].tileType == BOMB) {/*field[i][m + 1]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != tileField.size() - 1 && m != tileField[i].size() - 1) {/*field.size()*//*field[i].size()*/
					if (tileField[i+1][m+1].tileType == BOMB) {/*field[i + 1][m + 1]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != tileField.size() - 1 && m != 0) {/*field.size()*/
					if (tileField[i+1][m-1].tileType == BOMB) {/*field[i + 1][m - 1]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != 0 && m != 0) {
					if ( tileField[i-1][m-1].tileType == BOMB) {/*field[i - 1][m - 1]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != 0 && m != tileField[i].size() - 1) {/*field[i].size()*/
					if ( tileField[i-1][m+1].tileType == BOMB) {/*field[i - 1][m + 1]*/
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}
			}
		}
		bombCalculated = true;
	}
}

int Field::returnBombCount(int x, int y) {
	//return bombs[y][x];
	return tileField[y][x].bombcount;
}

void Field::setRandomWalls()
{
	int maxWallsCount = 3;
	int i = 1;
	int x = 0;
	int y = 0;
	int beginDir = 0;
	int secondDir = 0;
	int count = 0;
	srand(time(NULL));
	while (i <= maxWallsCount) {

		count = 0;
		x = rand() % 50;
		y = rand() % 15;
		int a = (rand() % 30) + 5;
		int b = (rand() % 20);
		beginDir = rand() % 4;
		secondDir = rand() % 2;
		

		if (tileField[y][x].tileType != WALL) {/*field[y][x]*/
			if (x > 1 && x < tileField[0].size() - 1 && y > 1 && y < tileField.size() - 1) {/*field[0].size()*//*field.size()*/
				if (tileField[y-1][x].tileType == WALL)/*field[y - 1][x]*/
					count++;
				if (tileField[y+1][x].tileType == WALL)/*field[y + 1][x]*/
					count++;
				if (tileField[y][x+1].tileType == WALL)/*field[y][x + 1]*/
					count++;
				if (tileField[y][x-1].tileType == WALL)/*field[y][x - 1]*/
					count++;

				int tempx, tempy;
				
			
				enterObjectInField(x, y, WALL);
				tempx = x;
				tempy = y;
				i++;

				switch (beginDir) {
				case 0: //down
					for (int m = 0; m < a; m++) {
						if (count <= 2 && tempy < tileField.size() - 1) {/*field.size()*/
							tempy++;
							enterObjectInField(tempx, tempy, WALL);
							switch (secondDir) {
							case 0: // right
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempx <tileField[0].size() - 1) { /*field[0].size()*/
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
									if (count <= 2 && tempx < tileField[0].size() - 1) {/*field[0].size()*/
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
						if (count <= 2 && tempx < tileField[0].size() -1) {/*field[0].size()*/
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
									if (count <= 2 && tempy < tileField.size() - 1) {/*field.size()*/
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
									if (count <= 2 && tempy <  tileField.size() - 1) {/*field.size()*/
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

void Field::setRandowMines()
{
	int maxWallsCount = 100;
	int i = 1;
	int x = 0;
	int y = 0;
	srand(time(NULL));
	while (i < maxWallsCount) {
		x = rand() % 50;
		y = rand() % 15;
		if (tileField[y][x].tileType == BACKGROUND) {
			enterObjectInField(x, y, BOMB);
			i++;
		}
	}
	bombsProx();
}

void Field::floodFill(int newPositionX, int nextPositionY)
{

}




void Field::drawField()
{
	setRendererColor(0, 0, 0, 255);
	drawFillRect(0, 0, 1920, 1080);
	/*setRendererColor(0, 255, 0, 255);
	drawRect(335, 165, 1250, 750);*/
	//placeMask();

	int r = 0;
	int c = 0;

	for (int i = 0; i < tileField.size() ; i++) {/*field.size()*/
		for (int m = 0; m < tileField[i].size() ; m++) {/*field[i].size()*/ /*25*/
			xOrigin = (getWindowWidth()/2) - (playerXPos * 50) ;
			

			if (tileField[i][m].tileType == BACKGROUND) {/*field[i][m]*/
				setRendererColor(0, 255, 0, 255);

				drawRect(xOrigin + c*50, 165 + r * 50, 50, 50);
				//tex->renderTexture(tex->loadTexture("astronaut_SE.png", ren), ren, xOrigin + c * 50, 165 + r * 50, 50, 50);
			}
			if (tileField[i][m].tileType == WALL) {/*field[i][m]*/
				setRendererColor(0, 255, 0, 255);
				drawFillRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
			}
			if (tileField[i][m].tileType == PLAYER) {/*field[i][m]*/
				setRendererColor(0, 255, 0, 255);
				drawRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
				drawFillCircle(xOrigin + c * 50, 165 + r * 50, 25);
				
				//tex->renderTexture(tex->loadTexture("Assets\\metalTileLarge.jpg", ren), ren, xOrigin + c * 50, 165 + r * 50, 45,67);
			}
			if (tileField[i][m].tileType == BOMB) {/*field[i][m]*/
				setRendererColor(255, 0, 0, 255);
				drawRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
				drawFillCircle(xOrigin + c * 50, 165 + r * 50, 25);
				drawRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
			}
			/*if (!tileField[i][m].isShown) {
				setRendererColor(0, 0, 150, 255);
				drawFillRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
				setRendererColor(255, 255, 255, 255);
				drawRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
			}*/
			if (returnBombCount(m, i) == 1) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "1", ren);
			}
			if (returnBombCount(m, i) == 2) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "2", ren);
			}
			if (returnBombCount(m, i) == 3) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "3", ren);
			}
			if (returnBombCount(m, 1) == 4) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "4", ren);
			}
			if (returnBombCount(m, 1) == 5) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "5", ren);
			}
			if (returnBombCount(m, 1) == 6) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "6", ren);
			}
			if (returnBombCount(m, 1) == 7) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "7", ren);
			}
			if (returnBombCount(m, 1) == 8) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "8", ren);
			}
			if (returnBombCount(m, 1) == 9) {
				setRendererColor(0, 0, 0, 255);
				game->writeText(xOrigin + c * 50, 165 + r * 50, 40, 50, 100, "9", ren);
			}

			c++;
			if (c >= tileField[r].size() ) c = 0;/*field[r].size()*/ /*25*/



		}
		r++;
		//if (r >= field.size()) r = 0;
		if (r >= tileField.size()) r = 0;
	}

	SDL_RenderPresent(ren);
}






//BACKUP
//void Field::drawField()
//{
//	setRendererColor(0, 0, 0, 255);
//	drawFillRect(0, 0, 1920, 1080);
//	setRendererColor(0, 255, 0, 255);
//	drawRect(335, 165, 1250, 750);
//
//	
//	int r = 0;
//	int c = 0;
//	
//	for (int i = 0; i < field.size(); i++) {
//		for (int m = 0; m < field[i].size() /*25*/; m++) {
//			
//				if (field[i][m] == BACKGROUND) {
//					setRendererColor(0, 255, 0, 255);
//
//					drawRect(335 + m * 50 - scrollParameter * 50, 165 + r * 50, 50, 50);
//				}
//				if (field[i][m] == WALL) {
//					setRendererColor(0, 255, 0, 255);
//					drawFillRect(335 + c * 50 - (scrollParameter * 50), 165 + r * 50, 50, 50);
//				}
//				if (field[i][m] == PLAYER) {
//					setRendererColor(0, 255, 0, 255);
//					drawRect(335 + c * 50 - (scrollParameter * 50), 165 + r * 50, 50, 50);
//					drawFillCircle(335 + c * 50, 165 + r * 50, 25);
//				}
//				if (field[i][m] == BOMB) {
//					setRendererColor(255, 0, 0, 255);
//					drawRect(335 + c * 50 - (scrollParameter * 50), 165 + r * 50, 50, 50);
//					drawFillCircle(335 + c * 50 + (scrollParameter * 50), 165 + r * 50, 25);
//				}
//				if (returnBombCount(m, i) == 1) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "1", ren);
//				}
//				if (returnBombCount(m, i) == 2) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "2", ren);
//				}
//				if (returnBombCount(m, i) == 3) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "3", ren);
//				}
//				if (returnBombCount(m, 1) == 4) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "4", ren);
//				}
//				if (returnBombCount(m, 1) == 5) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "5", ren);
//				}
//				if (returnBombCount(m, 1) == 6) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "6", ren);
//				}
//				if (returnBombCount(m, 1) == 7) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "7", ren);
//				}
//				if (returnBombCount(m, 1) == 8) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "8", ren);
//				}
//				if (returnBombCount(m, 1) == 9) {
//					setRendererColor(0, 0, 0, 255);
//					game->writeText(335 + c * 50 + 8 - (scrollParameter * 50), 165 + r * 50, 40, 50, 100, "9", ren);
//				}
//
//				c++;
//				if (c >= /*field[r].size()*/ 25 ) c = 0;
//			
//				
//			
//		}
//		r++;
//		if (r >= field.size()) r = 0;
//	}
//
//	SDL_RenderPresent(ren);
//}