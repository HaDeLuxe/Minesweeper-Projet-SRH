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

	tileField.resize(10);
	tile newTile;
	tileField[0].push_back(newTile);
	tileField[0][0].isShown = false;


	for (int y = 0; y < pY; y++) {
		/*std::vector<int> temp;
		std::vector<int> temp2;*/
		std::vector<tile> temp3;
		for (int x = 0; x < pX; x++) {
			/*temp.push_back(BACKGROUND);
			temp2.push_back(0);*/
			tile tileEmpty;
			temp3.push_back(tileEmpty);
		}
		/*field.push_back(temp);
		bombs.push_back(temp2);*/
		tileField.push_back(temp3);
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
	for (int i = 0; i < field.size(); i++) {
		for (int m = 0; m < field[i].size(); m++) {
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


void Field::setBombsBoolToFalse()
{
	bombCalculated = false;
}

void Field::bombsProx()
{
	calculatePlayerPos();
	
	if (!bombCalculated) {
		//reinitalizeBombCounts();
		for (int i = 0; i < tileField.size()/*field.size()*/; i++) {
			for (int m = 0; m < tileField[i].size()/*field[i].size()*/; m++) {
				if (i != tileField.size()/*field.size()*/ - 1) {
					if (tileField[i+1][m].tileType /*field[i + 1][m]*/ == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != 0) {
					if (tileField[i-1][m].tileType/*field[i - 1][m]*/ == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (m != 0) {
					if (tileField[i][m-1].bombcount/*field[i][m - 1]*/ == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (m != tileField[i].size()/*field[i].size()*/ - 1) {
					if (tileField[i][m+1].tileType/*field[i][m + 1]*/ == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != tileField.size()/*field.size()*/ - 1 && m != tileField[i].size()/*field[i].size()*/ - 1) {
					if (tileField[i+1][m+1].tileType/*field[i + 1][m + 1]*/ == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != tileField.size()/*field.size()*/ - 1 && m != 0) {
					if (tileField[i+1][m-1].tileType/*field[i + 1][m - 1]*/ == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != 0 && m != 0) {
					if (/*field[i - 1][m - 1]*/ tileField[i-1][m-1].tileType == BOMB) {
						//bombs[i][m]++;
						tileField[i][m].bombcount++;
					}
				}

				if (i != 0 && m != /*field[i].size()*/tileField[i].size() - 1) {
					if (/*field[i - 1][m + 1]*/ tileField[i-1][m+1].tileType == BOMB) {
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
	int maxWallsCount = 5;
	int i = 0;
	int x = 0;
	int y = 0;
	int beginDir = 0;
	int secondDir = 0;
	int count = 0;
	srand(time(NULL));
	while (i < maxWallsCount) {

		count = 0;
		x = rand() % 50;
		y = rand() % 15;
		int a = (rand() % 20) + 5;
		int b = (rand() % 15);
		beginDir = rand() % 4;
		secondDir = rand() % 2;
		

		if (/*field[y][x]*/tileField[y][x].tileType != WALL) {
			if (x > 1 && x < /*field[0].size()*/tileField[0].size() - 1 && y > 1 && y < /*field.size()*/tileField.size() - 1) {
				if (/*field[y - 1][x]*/tileField[y-1][x].tileType == WALL)
					count++;
				if (/*field[y + 1][x]*/tileField[y+1][x].tileType == WALL)
					count++;
				if (/*field[y][x + 1]*/tileField[y][x+1].tileType == WALL)
					count++;
				if (/*field[y][x - 1]*/tileField[y][x-1].tileType == WALL)
					count++;

				int tempx, tempy;
				
			
				enterObjectInField(x, y, WALL);
				tempx = x;
				tempy = y;
				i++;

				switch (beginDir) {
				case 0: //down
					for (int m = 0; m < a; m++) {
						if (count <= 2 && tempy < /*field.size()*/tileField.size() - 1) {
							tempy++;
							enterObjectInField(tempx, tempy, WALL);
							switch (secondDir) {
							case 0: // right
								for (int m = 0; m < b; m++) {
									if (count <= 2 && tempx < /*field[0].size()*/tileField[0].size() - 1) {
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
									if (count <= 2 && tempx < /*field[0].size()*/tileField[0].size() - 1) {
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
						if (count <= 2 && tempx < /*field[0].size()*/tileField[0].size() -1) {
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
									if (count <= 2 && tempy < /*field.size()*/tileField.size() - 1) {
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
									if (count <= 2 && tempy < /*field.size()*/ tileField.size() - 1) {
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




void Field::drawField()
{
	setRendererColor(0, 0, 0, 255);
	drawFillRect(0, 0, 1920, 1080);
	/*setRendererColor(0, 255, 0, 255);
	drawRect(335, 165, 1250, 750);*/
	

	int r = 0;
	int c = 0;

	for (int i = 0; i < tileField.size() /*field.size()*/; i++) {
		for (int m = 0; m < tileField[i].size() /*field[i].size()*/ /*25*/; m++) {
			xOrigin = (getWindowWidth()/2) - (playerXPos * 50) ;
			

			if (/*field[i][m]*/tileField[i][m].tileType == BACKGROUND) {
				setRendererColor(0, 255, 0, 255);

				drawRect(xOrigin + c*50, 165 + r * 50, 50, 50);
				//tex->renderTexture(tex->loadTexture("astronaut_SE.png", ren), ren, xOrigin + c * 50, 165 + r * 50, 50, 50);
			}
			if (/*field[i][m]*/tileField[i][m].tileType == WALL) {
				setRendererColor(0, 255, 0, 255);
				drawFillRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
			}
			if (/*field[i][m]*/tileField[i][m].tileType == PLAYER) {
				setRendererColor(0, 255, 0, 255);
				drawRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
				drawFillCircle(xOrigin + c * 50, 165 + r * 50, 25);
				
				//tex->renderTexture(tex->loadTexture("Assets\\metalTileLarge.jpg", ren), ren, xOrigin + c * 50, 165 + r * 50, 45,67);
			}
			if (/*field[i][m]*/tileField[i][m].tileType == BOMB) {
				setRendererColor(255, 0, 0, 255);
				drawRect(xOrigin + c * 50, 165 + r * 50, 50, 50);
				drawFillCircle(xOrigin + c * 50, 165 + r * 50, 25);
			}
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
			if (c >= tileField[r].size() /*field[r].size()*/ /*25*/) c = 0;



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