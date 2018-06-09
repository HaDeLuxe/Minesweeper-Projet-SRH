#pragma once
#include "Header.h"
#include "Enums.h"
#include "text.h"
#include "Textures.h"
#include "Player.h"
#include "GameManager.h"


#define BACKGROUND 1
#define WALL 2
#define PLAYER 3
#define BOMB 4
#define GOAL 5
#define DOOR 6
#define AMMU 7
#define ENEMY 8



typedef struct tile {
	int tileType = 1;
	int bombcount = 0;
	bool isShown = true;
	bool crosshair = false;
	bool flag = false;
	bool missile = false;
}tile;

class Field
{


private:
	SDL_Window * win;
	SDL_Renderer *ren;
	int playerXPos;
	int playerYPos;
	int lastDirection = 1;

	static Field* instance;
	Textures * tex = new Textures();
	
	

	Field();
	Field(Field const&) {};
	Field& operator =(Field const&) {};
	static Field* m_pInstance;

	text *textC = new text();
public:


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
	void initializeTextC();
	void initializeTex();

#pragma region object draw functions
	void drawRect(int x1, int y1, int x2, int y2);
	void drawFillRect(int x1, int y1, int x2, int y2);
	void drawFillCircle(int x, int y, int radius);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawTransparentRect(int x1, int y1, int x2, int y2);
#pragma endregion Hier sind die Funktionen um Objekte wie Kreise und Rechtecke zu zeichnen.
	void drawHUD();

	int getPlayerXPos();
	int getPlayerYPos();
	int getPlayfieldXSize();
	int getPlayfieldYSize();
	int getWindowWidth();
	void getDirection(int dir);
	int getObjectAtCoord(int x, int y);
	void enterObjectInField(int x, int y, int type);
	bool getFlagStatus(int x, int y);
	
	int getCorrectFlags();
	bool bombCollision();
	void placeMask();
	void bombsProx();
	int returnBombCount(int x, int y);
	void setRandomWalls();
	void setRandomMines();
	void floodFillOpenFieldsUR(int nextPositionX, int nextPositionY);
	
	void drawField();
};





