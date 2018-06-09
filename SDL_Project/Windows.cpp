
#include "Windows.h"
#include "Field.h"

Window::Window()
{
	textC = new text();
}

Window::~Window()
{
}

void Window::renderPauseScreen()
{
	FIELD->setRendererColor(255, 255, 255, 255);
	SDL_SetRenderDrawBlendMode(FIELD->getRenderer(), SDL_BLENDMODE_BLEND);
	FIELD->setRendererColor(0, 0, 0, 10);
	FIELD->drawFillRect(0, 0, 1920, 1080);

	FIELD->setRendererColor(66, 195, 148, 255);
	SDL_Color color = { 255, 255, 255, 255 };
	textC->writeText(1400, 505, 280, 65, 95, "Continue", FIELD->getRenderer(), color);

	FIELD->setRendererColor(66, 195, 148, 255);
	
	textC->writeText(1400, 705, 280, 65, 95, "Main Menu", FIELD->getRenderer(), color);
}

bool Window::continueButtonPushed(int x, int y)
{
	if (x > 1400 && x < 1680 && y > 505 && y < 570) {
		return true;
	}
	else return false;
}

bool Window::pauseExitButtonPushed(int x, int y)
{
	if (x > 1400 && x < 1680 && y > 705 && y < 770) {
		return true;
	}
	else return false;
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
	//FIELD->setRendererColor(66, 195, 148, 255);
	//FIELD->drawFillRect(1450, 700, 300, 75);
	textC->writeText(900, 705, 200, 65, 95, "Credits", FIELD->getRenderer(), color);
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
	if (x > 900 && x < 1100 && y > 700 && y < 775) {
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
	std::stringstream temporary;
	temporary << "Bombs found: " << (int)(FIELD->getCorrectFlags());
	std::string highscore = temporary.str();
	textC->writeText(100, 700, 500, 50, 300, highscore, FIELD->getRenderer(), color);
}

void credits::renderCreditsWindow()
{
	
	FIELD->setRendererColor(255, 255, 255, 20);
	FIELD->drawFillRect(0, 0, 1920, 1080);
	SDL_Color color = { 0, 0, 0, 255 };
	textC->writeText(100, 100, 150, 100, 300, "Credits", FIELD->getRenderer(), color);
	textC->writeText(700, 390, 350, 75, 300, "Haas Pascal", FIELD->getRenderer(), color);
	textC->writeText(1700, 100, 120, 100, 300, "Back", FIELD->getRenderer(), color);
}

bool credits::creditsBackButtonPushed(int x, int y)
{
	if (x > 1700 && x < 1820 && y > 100 && y < 200) {
		return true;
	}
	else return false;
}


