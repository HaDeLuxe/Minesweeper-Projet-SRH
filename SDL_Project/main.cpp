
#include "Header.h"

#include "Field.h"
#include "Textures.h"
#include "text.h"
#include "Movement.h"
#include "GameManager.h"
#include "Enums.h"
#include "Player.h"
#include "Collision.h"
#include "Enemy.h"

#define FIELD Field::Instance()



Textures* textures;
Movement* movement;
text * textC;
GameManager * gameManager;
Menu* mainMenu;
SDL_Window *win;
Window * window;
Splashscreen* splashScreen;
Player * player;
Collision * col;
Losescreen * losescreen;
credits * creditsS;

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
	player = new Player();
	textC = new text();
	col = new Collision();
	gameManager = new GameManager();
	window = new Window();
	mainMenu = new Menu();
	splashScreen = new Splashscreen();
	losescreen = new Losescreen();
	creditsS = new credits();
	

	FIELD->createWindow();
	FIELD->createRenderer();
	win = FIELD->getWindow();
	currentGameState = States::Splashscreen;
	FIELD->initializeTextC();
	FIELD->initializeTex();
	textures->preLoadTextures(FIELD->getRenderer());
	
	FIELD->createPlayField(50, 15);
	//gameManager->readWallData("Assets/Level1");
	
	gameManager->Tutorial();
	FIELD->setRandomMines();
	//enemy1 = new Enemy(15, 5, 4);
	//enemy1->spawnMissile(0);
	//enemy1->manageMissiles();
	
	FIELD->placeMask();
	gameManager->TutorialRemoveMask();

	std::cout << "Lifepoints in Main (2): " << lifePoints - 1 << std::endl;
	PollEvents();

	
	SDL_DestroyRenderer(FIELD->getRenderer());
	SDL_DestroyWindow(win);
	SDL_Quit();


	return 0;
}




void PollEvents() {

	SDL_Event event;
	short i = 1;
	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
	Uint64 lastTimestamp = 0;

	float deltaTime = 0;

	/*int frameRate = 25;
	int frameMs = 1000 / frameRate;*/
	while (i) {
	//int startMs = SDL_GetTicks();

	#pragma region gameLoop

		
		


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
						FIELD->getDirection(1);
					}
					break;
				case SDLK_s:
					if (currentGameState == States::Game) {
						movement->moveDown();
						FIELD->getDirection(3);
					}
					break;
				case SDLK_d:
					if (currentGameState == States::Game) {
						movement->moveRight();
						FIELD->getDirection(2);
					}
					break;
				case SDLK_a:
					if (currentGameState == States::Game) {
						movement->moveLeft();
						FIELD->getDirection(4);
					}
					break;
				case SDLK_f:
					if (currentGameState == States::Game) {
						
						//gameManager->removeFlag(movement->getCrosshairXPos(), movement->getCrosshairYPos());
						gameManager->changeFlag(movement->getCrosshairXPos(), movement->getCrosshairYPos());

						if (FIELD->tileField[movement->getCrosshairYPos()][movement->getCrosshairXPos()].tileType == DOOR && ammuCount == 3) {
							FIELD->enterObjectInField(movement->getCrosshairXPos(), movement->getCrosshairYPos(), BACKGROUND);
							ammuCount = 0;
						}
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
						if (mainMenu->creditsButtonPushed(mouseX, mouseY)) currentGameState = States::Credits;
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
			currentGameState = splashScreen->Update(deltaTime);
			textures->renderTexture(textures->splash, FIELD->getRenderer(), 0, 0, 1920, 1080);
			splashScreen->RenderSplashScreen();
			break;
		case States::MainMenu:
			mainMenu->RenderMenu();
			break;
		case States::Game:
			FIELD->renderClear();
			textures->renderTexture(textures->backgroundTex,FIELD->getRenderer(),0,0,1920,1080);

			FIELD->drawField();
			if (player->returnLifePoints() == 0) currentGameState = States::End;
			break;
		case States::End:
			losescreen->RenderEndScreen();
			losescreen->writeWinText();
			break;
		case States::Credits:
			creditsS->renderCreditsWindow();
		}
		
		

		
		SDL_RenderPresent(FIELD->getRenderer());
#pragma endregion

		/*int endMs = SDL_GetTicks();
		int delayMs = frameMs - (endMs - startMs);
		SDL_Delay(delayMs);*/
	}

}



