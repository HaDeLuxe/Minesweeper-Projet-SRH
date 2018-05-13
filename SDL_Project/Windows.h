#pragma once
#include "Header.h"
#include "Field.h"
#include "Game.h"
#include "Enums.h"



#define FIELD Field::Instance()

class Menu
{
private:
	Game * game;
public:
	Menu();
	~Menu();
	void RenderMenu();
	bool startButtonPushed(int x, int y);
	bool exitButtonPushed(int x, int y);
};

class Splashscreen {
private:
	float passframe = 0;
public:
	Splashscreen();
	~Splashscreen();
	void RenderSplashScreen();
	States Update(float deltaTime);
	
};


