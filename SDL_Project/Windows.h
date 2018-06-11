#pragma once
#include "Header.h"
#include "Field.h"
#include "text.h"
#include "Enums.h"
#include "Textures.h"



#define FIELD Field::Instance()

class Window {
private:
	int langSelection = 0;
protected:
	text * textC;
public:
	Window();
	~Window();
	void renderPauseScreen();
	bool continueButtonPushed(int x, int y);
	bool pauseExitButtonPushed(int x, int y);
	void renderLangMenu();
	Language languagesButtonPushed(int x, int y);
	bool langBackButtonPushed(int x, int y);
	int moveButtonPushed(int x, int y);
	bool flagButtonPushed(int x, int y);
	void langSelectionUp();
	void langSelectionDown();
	int getCurrentSelection();
};

class Menu : public Window
{
private:
	int MenuSelection = 0;
public:
	Menu();
	~Menu();
	void RenderMenu();
	void menuSelectionUp();
	void menuSelectionDown();
	bool startButtonPushed(int x, int y);
	bool exitButtonPushed(int x, int y);
	bool creditsButtonPushed(int x, int y);
	bool langButtonPushed(int x, int y);
	int getCurrentSelection();
	
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
	bool EndBackButtonPushed(int x, int y);
};

class Losescreen : public EndScreen {
public:
	void writeWinText();
	
};

class credits : public Window {
private:
public:
	void renderCreditsWindow();
	bool creditsBackButtonPushed(int x, int y);
};