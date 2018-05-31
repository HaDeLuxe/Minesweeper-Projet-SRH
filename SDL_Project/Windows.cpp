
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
	SDL_Color color = { 255, 255, 255, 255 };
	textC->writeText(305, 505, 280, 65, 95, "Start Game", FIELD->getRenderer(), color);

	//Render Quit Button
	FIELD->setRendererColor(66, 195, 148, 255);
	FIELD->drawFillRect(300, 700, 300, 75);
	textC->writeText(345, 705, 200, 65, 95, "Quit", FIELD->getRenderer(), color);
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

EndScreen::EndScreen()
{
	textC = new text();
}

EndScreen::~EndScreen()
{
}

void EndScreen::RenderEndScreen()
{
	//FIELD->renderClear();
	FIELD->setRendererColor(255, 255, 255, 20);
	FIELD->drawFillRect(0, 0, 1920, 1080);
	
}

void Losescreen::writeWinText()
{
	SDL_Color color = { 255, 0, 0, 255 };
	textC->writeText(700, 390, 500, 200, 300, "You Lose", FIELD->getRenderer(),color );
}
