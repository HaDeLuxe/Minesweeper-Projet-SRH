#pragma once
#include "Header.h"
#include "Enums.h"
#include "text.h"
#include "Textures.h"
#include "Player.h"
#include "GameManager.h"
#include "Timer.h"

#define BACKGROUND 1
#define WALL 2
#define PLAYER 3
#define BOMB 4
#define GOAL 5
#define DOOR 6
#define AMMU 7
#define ENEMY 8
#define SHIELD 9
#define PILL 10



typedef struct tile {
	int tileType = 1;
	int bombcount = 0;
	bool isShown = true;
	bool crosshair = false;
	bool flag = false;
	bool missile1 = false;
	bool missile2 = false;
	bool missile3 = false;
	bool missile4 = false;
	bool missile5 = false;
	bool missile6 = false;
	bool missile7 = false;
	bool missile8 = false;
	bool missile9 = false;
	bool missile10 = false;
}tile;

class Field
{


private:
	SDL_Window * win;
	SDL_Renderer *ren;
	int playerXPos;
	int playerYPos;
	int lastDirection = 1;						// last Direction that was moved to
	bool activeTutorialWindow = true;			// is the Tutorial Window still active?
	static Field* instance;
	Textures * tex = new Textures();
	Timer * timer = new Timer();
	
	Field();
	Field(Field const&) {};
	Field& operator =(Field const&) {};
	static Field* m_pInstance;


	int tickInit = timer->getTicks(10);				//initial Ticks value for easterEgg Anim.
	int tickInitDamage = timer->getTicks(500);		//initial Ticks value for damage Anim.
	int easterEggXPos = -200;
	int easterEggYPos = 700;
	int easterEggAngle = 180;
	int easterEggStage = 1;
	int damageAnimCounter = 5;
	text *textC = new text();
public:
	bool damgageTriggered = false;		//trigger when damage has been triggered
	Language currentLanguage = Language::German;
	
	std::vector<std::vector<tile>> tileField;		//2d vector for Field representation
	
	
	int xOrigin;				//x pos of first tile
	static Field* Instance();
	
	~Field();
	void createPlayField(int pX, int pY);		//enters values into field vector
	void clearPlayField();
	void createWindow();		
	void createRenderer();
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
	void RenderStoryScreen();

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
	void drawUI();
	void drawTutorial();

	int getPlayerXPos();
	int getPlayerYPos();
	int getPlayfieldXSize();
	int getPlayfieldYSize();
	int getWindowWidth();
	void getDirection(int dir);	//return direction
	int getObjectAtCoord(int x, int y);	//return Object at specific position
	void enterObjectInField(int x, int y, int type);	//creates object at specific position
	bool getFlagStatus(int x, int y);	//returns if flag has been placed at specific position
	void removeAllWalls();	
	int getCorrectFlags();	//return number of all flags placed over bombs
	bool bombCollision();
	bool pillCollision();
	void placeMask();	//placec Mask over gamefield
	void bombsProx();	//calculates numbers around bombs
	int returnBombCount(int x, int y);
	/*void setRandomWalls();*/
	void easterEggAnimation();	//animates the easter egg
	void triggerDamageAnim();	// excecute to trigger damage Animation
	
	void setRandomMines(int mineCount);
	void floodFillOpenFieldsUR(int nextPositionX, int nextPositionY);	//removes free masktiles with floodfill algorithm
	void drawField();	//draws everything on the field
};





