#pragma once
#include "Header.h"
#include "Enums.h"




typedef struct Tile {
	TileTypes currentTileType = TileTypes::Empty;
	int bombsCount = 0;
}tile;


#define BACKGROUND 1
#define WALL 2
#define PLAYER 3


class Field
{


private:
	SDL_Window * win;
	SDL_Renderer *ren;
	int playerXPos;
	int playerYPos;

	static Field* instance;

	

	Field();
	Field(Field const&) {};
	Field& operator =(Field const&) {};
	static Field* m_pInstance;


	

public:
	
	std::vector<std::vector<TileTypes>> field;
	

	static Field* Instance();



	~Field();
	void createPlayField(int pX, int pY);
	void createWindow();
	void createRenderer();
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

	void setRendererColor(int r, int g, int b, int a);
	void renderClear();

	void calculatePlayerPos(); //Gets the player coordinates

	#pragma region object draw functions
	void drawRect(int x1, int y1, int x2, int y2);
	void drawFillRect(int x1, int y1, int x2, int y2);
	void drawFillCircle(int x, int y, int radius);
#pragma endregion Hier sind die Funktionen um Objekte wie Kreise und Rechtecke zu zeichnen.



	int getPlayerXPos();
	int getPlayerYPos();

	TileTypes getObjectAtCoord(int x, int y);
	void enterObjectInField(int x, int y, TileTypes type);

	void writeNumbers();

	void drawField();
};






