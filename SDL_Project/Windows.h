#pragma once
#include "Header.h"
#include "Field.h"
#include "text.h"
#include "Enums.h"
#include "Textures.h"



#define FIELD Field::Instance()

class Window {
protected:
	text * textC;
public:
	Window();
	~Window();
};

class Menu : public Window
{
private:
	
	
public:
	Menu();
	~Menu();
	void RenderMenu();
	bool startButtonPushed(int x, int y);
	bool exitButtonPushed(int x, int y);
	bool creditsButtonPushed(int x, int y);
};

class Splashscreen : public Window{
private:
	float passframe = 0;
	
public:
	Splashscreen();
	~Splashscreen();
	void RenderSplashScreen();
	States Update(float deltaTime);

};

class EndScreen : public Window{
protected:
	
public:
	
	EndScreen();
	~EndScreen();
	void RenderEndScreen();
};

class Losescreen : public EndScreen {
public:
	void writeWinText();
};

class credits : public Window {
private:
public:
	void renderCreditsWindow();
};