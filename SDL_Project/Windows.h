#pragma once
#include "Header.h"
#include "Field.h"
#include "text.h"
#include "Enums.h"



#define FIELD Field::Instance()

class Menu
{
private:
	text * textC;
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

class EndScreen {
protected:
	text * textC;
public:
	
	EndScreen();
	~EndScreen();
	void RenderEndScreen();
};

class Losescreen : public EndScreen {
public:
	void writeWinText();
};