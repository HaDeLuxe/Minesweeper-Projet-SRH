
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
	switch (FIELD->currentLanguage) {
	case Language::German:
		textC->writeText(1400, 505, 280, 65, 95, "Weiter", FIELD->getRenderer(), color);
		textC->writeText(1400, 705, 280, 65, 95, "Hauptmenü", FIELD->getRenderer(), color);
		break;
	case Language::English:
		textC->writeText(1400, 505, 280, 65, 95, "Continue", FIELD->getRenderer(), color);
		textC->writeText(1400, 705, 280, 65, 95, "Main Menu", FIELD->getRenderer(), color);
		break;
	case Language::Francais:
		textC->writeText(1400, 505, 280, 65, 95, "Continuer", FIELD->getRenderer(), color);
		textC->writeText(1400, 705, 280, 65, 95, "Menu principal", FIELD->getRenderer(), color);
		break;
	case Language::Letzebuergesch:
		textC->writeText(1400, 505, 280, 65, 95, "Weider", FIELD->getRenderer(), color);
		textC->writeText(1400, 705, 280, 65, 95, "Hauptmenu", FIELD->getRenderer(), color);
		break;
	}
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

void Window::renderLangMenu()
{
	/*FIELD->setRendererColor(0, 0, 0, 10);
	FIELD->drawFillRect(0, 0, 1920, 1080);*/
	SDL_Color backColor = { 255,255,255,255 };
	SDL_Color deColor = { 255, 255, 255, 255 };
	SDL_Color engColor = { 255,255,255,255 };
	SDL_Color frColor = { 255,255,255,255 };
	SDL_Color luColor = { 255,255,255,255 };

	if (langSelection == 1) {
		backColor = { 150, 150, 150, 255 };
		deColor = { 255,255,255,255 };
		engColor = { 255,255,255,255 };
		frColor = { 255,255,255,255 };
		luColor = { 255,255,255,255 };
	}
	if (langSelection == 2) {
		deColor = { 150,150,150,255 };
		backColor = { 255,255,255,255 };
		engColor = { 255,255,255,255 };
		frColor = { 255,255,255,255 };
		luColor = { 255,255,255,255 };
	}
	if (langSelection == 3) {
		engColor = { 150, 150, 150, 255 };
		backColor = { 255,255,255,255 };
		deColor = { 255,255,255,255 };
		frColor = { 255,255,255,255 };
		luColor = { 255,255,255,255 };
	}
	if (langSelection == 4) {
		frColor = { 150, 150, 150, 255 };
		backColor = { 255,255,255,255 };
		deColor = { 255,255,255,255 };
		engColor = { 255,255,255,255 };
		luColor = { 255,255,255,255 };
	}
	if (langSelection == 5) {
		luColor = { 150,150,150,255 };
		backColor = { 255,255,255,255 };
		deColor = { 255,255,255,255 };
		engColor = { 255,255,255,255 };
	}
	textC->writeText(1400, 205, 280, 65, 95, "Deutsch", FIELD->getRenderer(), deColor);
	textC->writeText(1400, 405, 280, 65, 95, "English", FIELD->getRenderer(), engColor);
	textC->writeText(1400, 605, 280, 65, 95, "Francais", FIELD->getRenderer(), frColor);
	textC->writeText(1400, 805, 280, 65, 95, "Lëtzebuergesch", FIELD->getRenderer(), luColor);

	switch (FIELD->currentLanguage) {
	case Language::German:
		textC->writeText(305, 505, 280, 65, 95, "Zurück", FIELD->getRenderer(), backColor);
		break;
	case Language::English:
		textC->writeText(305, 505, 280, 65, 95, "Back", FIELD->getRenderer(), backColor);
		break;
	case Language::Francais:
		textC->writeText(305, 505, 280, 65, 95, "Retourner", FIELD->getRenderer(), backColor);
		break;
	case Language::Letzebuergesch:
		textC->writeText(305, 505, 280, 65, 95, "Zereck", FIELD->getRenderer(), backColor);
		break;
	}
}

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::RenderMenu()
{
	SDL_Color StartColor = { 255, 255, 255, 255 };
	SDL_Color QuitColor = { 255, 255, 255, 255 };
	SDL_Color creditsColor = { 255, 255, 255, 255 };
	SDL_Color langColor = { 255, 255, 255, 255 };

	if (MenuSelection == 1) {
		StartColor = { 150, 150, 150, 255 };
		QuitColor = { 255, 255, 255, 255 };
		creditsColor = { 255, 255, 255, 255 };
		langColor = { 255, 255, 255, 255 };
	}
	if (MenuSelection == 2) {
		QuitColor = { 150,150,150,255 };
		StartColor = { 255, 255, 255, 255 };
		creditsColor = { 255, 255, 255, 255 };
		langColor = { 255, 255, 255, 255 };
	}
	if (MenuSelection == 3) {
		creditsColor = {150, 150, 150, 255};
		StartColor = { 255, 255, 255, 255 };
		QuitColor = { 255, 255, 255, 255 };
		langColor = { 255, 255, 255, 255 };
	}
	if (MenuSelection == 4) {
		langColor = { 150, 150, 150, 255};
		StartColor = { 255, 255, 255, 255 };
		QuitColor = { 255, 255, 255, 255 };
		creditsColor = { 255, 255, 255, 255 };
	}

	
	switch (FIELD->currentLanguage) {
	case Language::German:
		
		textC->writeText(305, 505, 280, 65, 95, "Spiel starten", FIELD->getRenderer(), StartColor);
		textC->writeText(345, 705, 200, 65, 95, "Verlassen", FIELD->getRenderer(), QuitColor);
		textC->writeText(900, 705, 200, 65, 95, "Credits", FIELD->getRenderer(), creditsColor);
		textC->writeText(900, 805, 200, 65, 95, "Sprachen", FIELD->getRenderer(), langColor);
		break;
	case Language::English:
		textC->writeText(305, 505, 280, 65, 95, "Start Game", FIELD->getRenderer(), StartColor);
		textC->writeText(345, 705, 200, 65, 95, "Quit", FIELD->getRenderer(), QuitColor);
		textC->writeText(900, 705, 200, 65, 95, "Credits", FIELD->getRenderer(), creditsColor);
		textC->writeText(900, 805, 200, 65, 95, "Languages", FIELD->getRenderer(), langColor);
		break;
	case Language::Francais:
		textC->writeText(305, 505, 280, 65, 95, "Commencer", FIELD->getRenderer(), StartColor);
		textC->writeText(345, 705, 200, 65, 95, "Quitter", FIELD->getRenderer(), QuitColor);
		textC->writeText(900, 705, 200, 65, 95, "Générique", FIELD->getRenderer(), creditsColor);
		textC->writeText(900, 805, 200, 65, 95, "Langues", FIELD->getRenderer(), langColor);
		break;
	case Language::Letzebuergesch:
		textC->writeText(305, 505, 280, 65, 95, "Spill starten", FIELD->getRenderer(), StartColor);
		textC->writeText(345, 705, 200, 65, 95, "Verloossen", FIELD->getRenderer(), QuitColor);
		textC->writeText(900, 705, 200, 65, 95, "Credits", FIELD->getRenderer(), creditsColor);
		textC->writeText(900, 805, 200, 65, 95, "Sproochen", FIELD->getRenderer(), langColor);
		break;
	}
}

void Menu::menuSelectionUp()
{
	MenuSelection--;
	if (MenuSelection < 1) MenuSelection = 4;
}

void Menu::menuSelectionDown()
{
	MenuSelection++;
	if (MenuSelection > 4) MenuSelection = 1;
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

bool Menu::langButtonPushed(int x, int y)
{
	if (x > 900 && x < 1100 && y > 805 && y < 975) {
		return true;
	}
	else return false;
}

int Menu::getCurrentSelection()
{
	return MenuSelection;
}

Language Window::languagesButtonPushed(int x, int y)
{
	if (x > 1400 && x < 1680 && y > 205 && y < 300) {
		return Language::German;
	}
	if (x > 1400 && x < 1680 && y > 405 && y < 500) {
		return Language::English;
	}
	if (x > 1400 && x < 1680 && y > 605 && y < 700) {
		return Language::Francais;
	}
	if (x > 1400 && x < 1680 && y > 805 && y < 900) {
		return Language::Letzebuergesch;
	}
	return Language::German;
}

bool Window::langBackButtonPushed(int x, int y)
{
	if (x > 305 && x < 585 && y > 505 && y < 570) {
		return true;
	}
	else return false;
}

int Window::moveButtonPushed(int x, int y)
{
	if (x > 200 && x < 228 && y > 900 && y < 942) {
		return 0;
	}
	if (x > 200 && x < 228 && y > 950 && y < 992) {
		return 2;
	}
	if (x > 223 && x < 272 && y > 936 && y < 967) {
		return 1;
	}
	if (x > 155 && x < 194 && y > 936 && y < 967) {
		return 3;
	}
	return 4;
}

bool Window::flagButtonPushed(int x, int y)
{
	if (x > 280 && x < 380 && y > 900 && y < 1000) {
		return true;
	}
	else return false;
}

void Window::langSelectionUp()
{
	langSelection--;
	if (langSelection < 1) {
		langSelection = 5;
	}
}

void Window::langSelectionDown()
{
	langSelection++;
	if (langSelection > 5) {
		langSelection = 1;
	}
}

int Window::getCurrentSelection()
{
	return langSelection;
}

Splashscreen::Splashscreen() {
}

Splashscreen::~Splashscreen() {}

void Splashscreen::RenderSplashScreen()
{
	
	SDL_Color color = { 255, 255, 255, 255 };
	switch (FIELD->currentLanguage) {
	case Language::German:
		textC->writeText(300, 900, 1400, 20, 50, "Zum Überspringen linke Maustaste drücken!", FIELD->getRenderer(), color);
		break;
	case Language::English:
		textC->writeText(300, 900, 1400, 20, 50, "Press Left Mouse Button to Continue Faster", FIELD->getRenderer(), color);
		break;
	case Language::Francais:
		textC->writeText(300, 900, 1400, 20, 50, "Poussez le button gauche de la souris pour avancer plus vite!", FIELD->getRenderer(), color);
		break;
	case Language::Letzebuergesch:
		textC->writeText(300, 900, 1400, 20, 50, "Lénks Maustast drécken, fir mi schnell weider ze kommen!", FIELD->getRenderer(), color);
		break;
	}
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

bool EndScreen::EndBackButtonPushed(int x, int y)
{
	if (x > 850 && x < 1050 && y > 700 && y < 750) {
		return true;
	}
	else return false;
}

void Losescreen::writeWinText()
{
	SDL_Color color = { 255, 0, 0, 255 };
	
	std::stringstream temporary;
	
	switch (FIELD->currentLanguage) {
	case Language::German:
		textC->writeText(700, 390, 500, 200, 300, "Du hast verloren", FIELD->getRenderer(), color);
		textC->writeText(850, 700, 200, 50, 300, "Zurück", FIELD->getRenderer(), color);
		temporary << "Gefundene Bomben: " << (int)(FIELD->getCorrectFlags());
		break;
	case Language::English:
		textC->writeText(700, 390, 500, 200, 300, "You Lose", FIELD->getRenderer(), color);
		textC->writeText(850, 700, 200, 50, 300, "Back", FIELD->getRenderer(), color);
		temporary << "Bombs found: " << (int)(FIELD->getCorrectFlags());
		break;
	case Language::Francais:
		textC->writeText(700, 390, 500, 200, 300, "Tu as perdu", FIELD->getRenderer(), color);
		textC->writeText(850, 700, 200, 50, 300, "Retourner", FIELD->getRenderer(), color);
		temporary << "Bombes trouvées: " << (int)(FIELD->getCorrectFlags());
		break;
	case Language::Letzebuergesch:
		textC->writeText(600, 390, 700, 200, 300, "Du hues verluer!", FIELD->getRenderer(), color);
		textC->writeText(850, 700, 200, 50, 300, "Zereck", FIELD->getRenderer(), color);
		temporary << "Bommen fonnt: " << (int)(FIELD->getCorrectFlags());
		break;
	}
	std::string highscore = temporary.str();
	textC->writeText(100, 700, 500, 50, 300, highscore, FIELD->getRenderer(), color);
}

void credits::renderCreditsWindow()
{
	
	FIELD->setRendererColor(255, 255, 255, 20);
	//FIELD->drawFillRect(0, 0, 1920, 1080);
	SDL_Color color = { 255, 255, 255, 255 };
	switch (FIELD->currentLanguage) {
	case Language::German:
		textC->writeText(100, 100, 150, 100, 300, "Credits", FIELD->getRenderer(), color);
		textC->writeText(700, 390, 350, 75, 300, "Haas Pascal", FIELD->getRenderer(), color);
		textC->writeText(1700, 100, 120, 100, 300, "Zurück", FIELD->getRenderer(), color);
		break;
	case Language::English:
		textC->writeText(100, 100, 150, 100, 300, "Credits", FIELD->getRenderer(), color);
		textC->writeText(700, 390, 350, 75, 300, "Haas Pascal", FIELD->getRenderer(), color);
		textC->writeText(1700, 100, 120, 100, 300, "Back", FIELD->getRenderer(), color);
		break;
	case Language::Francais:
		textC->writeText(100, 100, 150, 100, 300, "Générique", FIELD->getRenderer(), color);
		textC->writeText(700, 390, 350, 75, 300, "Haas Pascal", FIELD->getRenderer(), color);
		textC->writeText(1700, 100, 120, 100, 300, "Retourner", FIELD->getRenderer(), color);
		break;
	case Language::Letzebuergesch:
		textC->writeText(100, 100, 150, 100, 300, "Credits", FIELD->getRenderer(), color);
		textC->writeText(700, 390, 350, 75, 300, "Haas Pascal", FIELD->getRenderer(), color);
		textC->writeText(1700, 100, 120, 100, 300, "Zereck", FIELD->getRenderer(), color);
		break;
	}
	
}

bool credits::creditsBackButtonPushed(int x, int y)
{
	if (x > 1700 && x < 1820 && y > 100 && y < 200) {
		return true;
	}
	else return false;
}


