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

void Field::createPlayField(int pX, int pY)
{
	for (int y = 0; y < pY; y++) {
		std::vector<TileTypes> temp;

		for (int x = 0; x < pX; x++) {
			temp.push_back(TileTypes::Empty);
			
		}
		field.push_back(temp);
		
	}
}

#pragma region Create Field and Renderer
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
			if (field[i][m] == PLAYER) {
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

TileTypes Field::getObjectAtCoord(int x, int y)
{
	return field.at[y][x].currentTileType;
}

#pragma endregion

void Field::enterObjectInField(int x, int y, int type)
{
	field.at[y].at[x].tileType = type;
	//Hallo


}

void Field::writeNumbers()
{

}


void Field::drawField()
{
	setRendererColor(0, 0, 0, 255);
	drawFillRect(0, 0, 1920, 1080);
	setRendererColor(0, 255, 0, 255);
	drawRect(335, 165, 1250, 750);
	
	int r = 0;
	int c = 0;
	for (int i = 0; i < field.size(); i++) {
		for (int m = 0; m < field[i].size(); m++) {
			if (field[i][m] == TileTypes::Empty) {
				setRendererColor(0, 255, 0, 255);
			
				drawRect(335 + c * 50, 165 + r * 50, 50, 50);
			}
			if (field[i][m] == TileTypes::Wall) {
				setRendererColor(0, 255, 0, 255);
				drawRect(335 + c * 50, 165 + r * 50, 50, 50);
			}
			if (field[i][m] == TileTypes::Player) {
				setRendererColor(0, 255, 0, 255);
				drawRect(335 + c * 50, 165 + r * 50, 50, 50);
				drawFillCircle(335 + c * 50, 165 + r * 50, 25);
			}
			c++;
			if (c >= field[r].size()) c = 0;
		}
		r++;
		if (r >= field.size()) r = 0;
	}

	SDL_RenderPresent(ren);
}
