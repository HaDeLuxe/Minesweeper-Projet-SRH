
#include "Header.h"

#include "Field.h"
#include "Textures.h"
#include "text.h"
#include "Movement.h"
#include "GameManager.h"
#include "Enums.h"


#define FIELD Field::Instance()



Textures* textures;
Movement* movement;
text * textC;
GameManager * gameManager;
Menu* mainMenu;
SDL_Window *win;
Splashscreen* splashScreen;

void PollEvents();


States currentGameState = States::Splashscreen;

int main(int argc, char* argv[])
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	textures = new Textures();
	movement = new Movement();
	textC = new text();
	gameManager = new GameManager();
	mainMenu = new Menu();
	splashScreen = new Splashscreen();
	FIELD->createWindow();
	FIELD->createRenderer();
	win = FIELD->getWindow();
	currentGameState = States::Splashscreen;
	//textC->TTF_Initiate();
	textC->preIntializeTexts(FIELD->getRenderer());
	FIELD->createPlayField(50, 15);
	FIELD->setRandomWalls();
	FIELD->setRandowMines();
	FIELD->placeMask();
	
	PollEvents();




	////textures->loadTexture("C:\\Users\\Pascal\\Desktop\\inf.jpg",  FIELD->getRenderer());
	////textures->renderTexture(textures->getTex(),  FIELD->getRenderer(), 0, 0);
	//FIELD->enterObjectInField(1, 1, PLAYER);
	SDL_DestroyRenderer(FIELD->getRenderer());
	SDL_DestroyWindow(win);
	SDL_Quit();


	return 0;
}




void PollEvents() {

	SDL_Event event;
	double i = 1;
	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
	Uint64 lastTimestamp = 0;
	float deltaTime = 0;


	while (i) {
		FIELD->setRendererColor(50, 20, 50, 255);
		FIELD->renderClear();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				i = 0;
				break;
			}


			if (event.type == SDL_KEYDOWN) { // && event.key.repeat == 0
				switch (event.key.keysym.sym) {
				case SDLK_w:
					if (currentGameState == States::Game) {
						movement->moveUp();
					}
					break;
				case SDLK_s:
					if (currentGameState == States::Game) {
						movement->moveDown();
					}
					break;
				case SDLK_d:
					if (currentGameState == States::Game) {
						movement->moveRight();
					}
					break;
				case SDLK_a:
					if (currentGameState == States::Game) {
						movement->moveLeft();
					}
					break;

				}

			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				int mouseX;
				int mouseY;
				switch (event.button.button) {
				case SDL_BUTTON_LEFT:
					std::cout << "Left Mouse Button Pressed" << std::endl;
					mouseX = event.motion.x;
					mouseY = event.motion.y;
					if (currentGameState == States::Game)
					{
						movement->moveAfterClick(mouseX, mouseY);
					}
					if (currentGameState == States::MainMenu) {
						if (mainMenu->startButtonPushed(mouseX, mouseY)) currentGameState = States::Game;
						if (mainMenu->exitButtonPushed(mouseX, mouseY)) i = 0;
					}
					if (currentGameState == States::Splashscreen) {
						currentGameState = States::MainMenu;
					}
					break;
				}
			}
			if (currentGameState == States::Game) {
				//FIELD->drawField();
			}


		}
		lastTimestamp = currentTimestamp;
		currentTimestamp = SDL_GetPerformanceCounter();
		deltaTime = ((currentTimestamp - lastTimestamp) / (float)SDL_GetPerformanceFrequency());

		switch (currentGameState) {
		default:

		case States::Splashscreen:
			splashScreen->RenderSplashScreen();
			currentGameState = splashScreen->Update(deltaTime);
			break;
		case States::MainMenu:
			mainMenu->RenderMenu();
			break;
		case States::Game:
			FIELD->renderClear();
			FIELD->drawField();
			break;
		case States::End:
			break;
		}



		//game->writeNumbers();
		SDL_RenderPresent(FIELD->getRenderer());
	}
}


