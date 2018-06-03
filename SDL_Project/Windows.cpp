
#include "Windows.h"
#include "Field.h"

Window::Window()
{
	textC = new text();
}

Window::~Window()
{
}

Menu::Menu()
{
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

	//Render Credits Button
	FIELD->setRendererColor(66, 195, 148, 255);
	FIELD->drawFillRect(1450, 700, 300, 75);
	textC->writeText(1500, 705, 200, 65, 95, "Credits", FIELD->getRenderer(), color);
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

bool Menu::creditsButtonPushed(int x, int y)
{
	if (x > 1450 && x < 1750 && y > 700 && y < 775) {
		return true;
	}
	else return false;
}

Splashscreen::Splashscreen() {
}

Splashscreen::~Splashscreen() {}

void Splashscreen::RenderSplashScreen()
{
	//FIELD->renderClear();
	//FIELD->setRendererColor(255, 200, 200, 255);
	//FIELD->drawFillRect(0, 0, 1920, 1080);
	//textures->renderTexture(textures->splash, FIELD->getRenderer(), 0, 0, 1920, 1080);
	SDL_Color color = { 255, 255, 255, 255 };
	textC->writeText(300, 900, 1400, 20, 50, "Press Mouse Button to Continue Faster", FIELD->getRenderer(), color);
}





States Splashscreen::Update(float deltaTime)
{
	passframe += deltaTime;
	if (passframe >= 3)
		return States::MainMenu;
	return States::Splashscreen;
}

EndScreen::EndScreen()
{
}

EndScreen::~EndScreen()
{
}

void EndScreen::RenderEndScreen()
{
	//FIELD->renderClear();
	SDL_SetRenderDrawBlendMode(FIELD->getRenderer(), SDL_BLENDMODE_BLEND);
	FIELD->setRendererColor(255, 255, 255, 1);
	FIELD->drawFillRect(0, 0, 1920, 1080);
	
}

void Losescreen::writeWinText()
{
	SDL_Color color = { 255, 0, 0, 255 };
	textC->writeText(700, 390, 500, 200, 300, "You Lose", FIELD->getRenderer(),color );
}

void credits::renderCreditsWindow()
{
	
	FIELD->setRendererColor(255, 255, 255, 20);
	FIELD->drawFillRect(0, 0, 1920, 1080);
	SDL_Color color = { 0, 0, 0, 255 };
	textC->writeText(100, 100, 150, 100, 300, "Credits", FIELD->getRenderer(), color);
	textC->writeText(700, 390, 350, 75, 100, "Haas Pascal", FIELD->getRenderer(), color);
}
