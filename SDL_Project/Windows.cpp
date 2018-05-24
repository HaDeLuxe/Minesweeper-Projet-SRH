
#include "Windows.h"
#include "Field.h"

Menu::Menu()
{
	
	textC = new text();
}

Menu::~Menu()
{
}

void Menu::RenderMenu()
{
	FIELD->renderClear();
	FIELD->setRendererColor(50, 100, 100, 255);
	FIELD->drawFillRect(100, 100, 1720, 880);

	//Render Start Button	
	FIELD->setRendererColor(66, 195, 148, 255);
	FIELD->drawFillRect(300, 500, 300, 75);
	textC->writeText(310, 500, 280, 75, 50, "Start Game", FIELD->getRenderer());

	//Render Quit Button
	FIELD->setRendererColor(66, 195, 148, 255);
	FIELD->drawFillRect(300, 700, 300, 75);
	textC->writeText(300, 700, 200, 75, 50, "Quit", FIELD->getRenderer());
}

bool Menu::startButtonPushed(int x, int y) {
	if (x > 300 && x < 600 && y > 500 && y < 575) {
		return true;
	}
	else return false;
}

bool Menu::exitButtonPushed(int x, int y)
{

	if (x > 300 && x < 600 && y > 700 && y < 775) {
		return true;
	}
	else return false;
}



void Splashscreen::RenderSplashScreen()
{
	FIELD->renderClear();
	FIELD->setRendererColor(200, 200, 200, 255);
	FIELD->drawFillRect(0, 0, 1920, 1080);

}



Splashscreen::Splashscreen() {}
Splashscreen::~Splashscreen() {}
States Splashscreen::Update(float deltaTime)
{
	passframe += deltaTime;
	if (passframe >= 3)
		return States::MainMenu;
	return States::Splashscreen;
}
