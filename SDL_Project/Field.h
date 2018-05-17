#pragma once
#include "Header.h"
#include "Enums.h"
#include "Game.h"
#include "Textures.h"
#include "SDL_image.h"


#define BACKGROUND 1
#define WALL 2
#define PLAYER 3
#define BOMB 4
#define NOBOMB 5

typedef struct tile {
	int tileType = 1;
	int bombcount = 0;
	bool isShown = true;
}tile;

class Field
{


private:
	SDL_Window * win;
	SDL_Renderer *ren;
	int playerXPos;
	int playerYPos;

	static Field* instance;
	Textures * tex = new Textures();
	bool bombCalculated = false;

	Field();
	Field(Field const&) {};
	Field& operator =(Field const&) {};
	static Field* m_pInstance;

	Game* game;

	SDL_Texture * metalTileLarge = tex->loadTexture("Assets\\metalTileLarge.jpg", ren);

public:

	/*std::vector<std::vector<int>> field;
	std::vector<std::vector<int>> bombs;*/

	std::vector<std::vector<tile>> tileField;
	
	
	int xOrigin;
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
	int getPlayfieldXSize();
	int getPlayfieldYSize();
	int getWindowWidth();

	int getObjectAtCoord(int x, int y);
	void enterObjectInField(int x, int y, int type);

	void setBombsBoolToFalse();
	void bombsProx();
	int returnBombCount(int x, int y);
	void setRandomWalls();
	
	void drawField();
};





