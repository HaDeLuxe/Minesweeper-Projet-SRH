
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
#include "Music.h"

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
Music * music;
SDL_Joystick* gameController = NULL;
const int Joystick_Dead_Zone = 32000;
void PollEvents();


void initJoySubSystem()
{
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		printf("Warning: Linear texture filtering not enabled!");
	}

	//Check for joysticks
	if (SDL_NumJoysticks() < 1)
	{
		printf("Warning: No joysticks connected!\n");
	}
	else
	{
		//Load joystick
		gameController = SDL_JoystickOpen(0);
		if (gameController == NULL)
		{
			printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
		}
	}
}

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
	music = new Music();
	
	
	FIELD->createWindow();
	FIELD->createRenderer();
	win = FIELD->getWindow();
	movement->initController();
	initJoySubSystem();
	currentGameState = States::Splashscreen;
	FIELD->initializeTextC();
	FIELD->initializeTex();
	textures->preLoadTextures(FIELD->getRenderer());
	
	FIELD->createPlayField(50, 15);
	//gameManager->readWallData("Assets/Level1");
	
	gameManager->Tutorial();
	FIELD->setRandomMines();
	FIELD->placeMask();
	gameManager->TutorialRemoveMask();

	music->initMusic();
	music->loadBackGroundMusic();
	music->playBackgroundMusic();
	music->loadSounds();
	
	std::cout << "Lifepoints in Main (2): " << lifePoints - 1 << std::endl;
	
	PollEvents();

	SDL_JoystickClose(gameController);
	SDL_DestroyRenderer(FIELD->getRenderer());
	SDL_DestroyWindow(win);
	
	SDL_Quit();


	return 0;
}

bool mousePushed = false;


void PollEvents() {
	
	bool pause = false;
	SDL_Event event;
	short i = 1;
	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
	Uint64 lastTimestamp = 0;
	int xDir = 0;
	int yDir = 0;
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
			if (event.type == SDL_JOYAXISMOTION) {
				bool alreadyMoved = false;
				if (event.jaxis.which == 0) {
					//X axis
					if (event.jaxis.axis == 0) {
						if (event.jaxis.value < -Joystick_Dead_Zone) {
							
							if (currentGameState == States::Game) {
								while (alreadyMoved == false) {
									movement->moveLeft();
									FIELD->getDirection(4);
									gameManager->manageMissiles();
									alreadyMoved = true;
								}
							}
							
						}
						else if (event.jaxis.value > Joystick_Dead_Zone) {
							
							if (currentGameState == States::Game) {
								while (alreadyMoved == false) {
									movement->moveRight();
									FIELD->getDirection(2);
									gameManager->manageMissiles();
									alreadyMoved = true;
								}
							}
						}
						else alreadyMoved = true;
					}

					if (event.jaxis.axis == 1) {
						if (event.jaxis.value < -Joystick_Dead_Zone) {

							if (currentGameState == States::Game) {
								while (alreadyMoved == false) {
									movement->moveUp();
									FIELD->getDirection(1);
									gameManager->manageMissiles();
									alreadyMoved = true;
								}
							}
							if (currentGameState == States::Game && !pause) {
								movement->moveUp();
								FIELD->getDirection(1);
								gameManager->manageMissiles();
							}
							if (currentGameState == States::MainMenu) {
								mainMenu->menuSelectionUp();
							}
							if (currentGameState == States::Language) {
								window->langSelectionUp();
							}
						}
						else if (event.jaxis.value > Joystick_Dead_Zone) {

							if (currentGameState == States::Game) {
								while (alreadyMoved == false) {
									movement->moveDown();
									FIELD->getDirection(3);
									gameManager->manageMissiles();
									alreadyMoved = true;
								}
							}
							if (currentGameState == States::Game && !pause) {
								movement->moveDown();
								FIELD->getDirection(3);
								gameManager->manageMissiles();
							}
							if (currentGameState == States::MainMenu) {
								mainMenu->menuSelectionDown();
							}
							if (currentGameState == States::Language) {
								window->langSelectionDown();
							}
						}
						else alreadyMoved = true;
					}
				}
			}


			if (event.type == SDL_JOYBUTTONDOWN) {
				switch (event.jbutton.button) {

				/*case SDL_CONTROLLER_BUTTON_DPAD_UP:
					if (currentGameState == States::Game && !pause) {
						movement->moveUp();
						FIELD->getDirection(1);
						gameManager->manageMissiles();
					}
					if (currentGameState == States::MainMenu) {
						mainMenu->menuSelectionUp();
					}
					if (currentGameState == States::Language) {
						window->langSelectionUp();
					}
					break;

				case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
					if (currentGameState == States::Game && !pause) {
						movement->moveDown();
						FIELD->getDirection(3);
						gameManager->manageMissiles();
					}
					if (currentGameState == States::MainMenu) {
						mainMenu->menuSelectionDown();
					}
					if (currentGameState == States::Language) {
						window->langSelectionDown();
					}
					break;*/

				case SDL_CONTROLLER_BUTTON_A:
					if (currentGameState == States::Game) {
						gameManager->changeFlag(movement->getCrosshairXPos(), movement->getCrosshairYPos());
						music->playMarkSound();
						if (FIELD->tileField[movement->getCrosshairYPos()][movement->getCrosshairXPos()].tileType == DOOR && ammuCount == 3) {
							FIELD->enterObjectInField(movement->getCrosshairXPos(), movement->getCrosshairYPos(), BACKGROUND);
							ammuCount = 0;
						}
					}
					if (currentGameState == States::Credits) {
						currentGameState = States::MainMenu;
						break;
					}
					if (currentGameState == States::MainMenu) {
						switch (mainMenu->getCurrentSelection()) {
						case 1:
							currentGameState = States::Game;
							break;
						case 2:
							i = 0;
							break;
						case 3:
							currentGameState = States::Credits;
							break;
						case 4:
							currentGameState = States::Language;
							break;
						}
						break;
					}
					if (currentGameState == States::Language) {
						switch (window->getCurrentSelection()) {
						case 1:
							currentGameState = States::MainMenu;
							break;
						case 2:
							FIELD->currentLanguage = Language::German;
							break;
						case 3:
							FIELD->currentLanguage = Language::English;
							break;
						case 4:
							FIELD->currentLanguage = Language::Francais;
							break;
						case 5:
							FIELD->currentLanguage = Language::Letzebuergesch;
							break;
						}
						break;
					}
					break;
				}
			}


			if (event.type == SDL_KEYDOWN) { // && event.key.repeat == 0
				switch (event.key.keysym.sym) {
				case SDLK_w:
					if (currentGameState == States::Game && !pause) {
						movement->moveUp();
						FIELD->getDirection(1);
						gameManager->manageMissiles();
					}
					if (currentGameState == States::MainMenu) {
						mainMenu->menuSelectionUp();
					}
					if (currentGameState == States::Language) {
						window->langSelectionUp();
					}
					break;
				case SDLK_s:
					if (currentGameState == States::Game && !pause) {
						movement->moveDown();
						FIELD->getDirection(3);
						gameManager->manageMissiles();
					}
					if (currentGameState == States::MainMenu) {
						mainMenu->menuSelectionDown();
					}
					if (currentGameState == States::Language) {
						window->langSelectionDown();
					}
					break;
				case SDLK_d:
					if (currentGameState == States::Game && !pause) {
						movement->moveRight();
						FIELD->getDirection(2);
						gameManager->manageMissiles();
					}
					break;
				case SDLK_a:
					if (currentGameState == States::Game && !pause) {
						movement->moveLeft();
						FIELD->getDirection(4);
						gameManager->manageMissiles();
					}
					break;
				case SDLK_f:
					if (currentGameState == States::Game) {

						//gameManager->removeFlag(movement->getCrosshairXPos(), movement->getCrosshairYPos());
						gameManager->changeFlag(movement->getCrosshairXPos(), movement->getCrosshairYPos());
						music->playMarkSound();
						if (FIELD->tileField[movement->getCrosshairYPos()][movement->getCrosshairXPos()].tileType == DOOR && ammuCount == 3) {
							FIELD->enterObjectInField(movement->getCrosshairXPos(), movement->getCrosshairYPos(), BACKGROUND);
							ammuCount = 0;
						}
					}
					break;
				case SDLK_p:
					if (!pause) pause = true;
					else pause = false;
					break;
				case SDLK_RETURN:
					if (currentGameState == States::Credits) {
						currentGameState = States::MainMenu;
						break;
					}
					if (currentGameState == States::MainMenu) {
						//if (mainMenu->getCurrentSelection() >= 1 && mainMenu->getCurrentSelection() <= 4) {
							switch (mainMenu->getCurrentSelection()) {
							case 1:
								currentGameState = States::Game;
								break;
							case 2:
								i = 0;
								break;
							case 3:
								currentGameState = States::Credits;
								break;
							case 4:
								currentGameState = States::Language;
								break;
							}
							break;
						//}
					}
					if (currentGameState == States::End) {
						currentGameState = States::MainMenu;
						break;
					}
					if (currentGameState == States::Language) {
						switch (window->getCurrentSelection()) {
						case 1:
							currentGameState = States::MainMenu;
							break;
						case 2:
							FIELD->currentLanguage = Language::German;
							break;
						case 3:
							FIELD->currentLanguage = Language::English;
							break;
						case 4:
							FIELD->currentLanguage = Language::Francais;
							break;
						case 5:
							FIELD->currentLanguage = Language::Letzebuergesch;
							break;
						}
						break;
					}
					break;
				}
			}

			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				mousePushed = false;
			}

			if (event.type == SDL_MOUSEBUTTONUP && mousePushed == false) {
				mousePushed = true;
				music->playMouseClickSound();
				int mouseX;
				int mouseY;
				switch (event.button.button) {
				case SDL_BUTTON_LEFT:
					//std::cout << "Left Mouse Button Pressed" << std::endl;
					mouseX = event.motion.x;
					mouseY = event.motion.y;
					if (currentGameState == States::Game)
					{
						switch (window->moveButtonPushed(mouseX,mouseY)) {
						case 0:
							if (currentGameState == States::Game && !pause) {
								movement->moveUp();
								FIELD->getDirection(1);
								gameManager->manageMissiles();
							}
							break;
						case 1:
							if (currentGameState == States::Game && !pause) {
								movement->moveRight();
								FIELD->getDirection(2);
								gameManager->manageMissiles();
							}
							break;
						case 2:
							if (currentGameState == States::Game && !pause) {
								movement->moveDown();
								FIELD->getDirection(3);
								gameManager->manageMissiles();
							}
							break;
						case 3:
							if (currentGameState == States::Game && !pause) {
								movement->moveLeft();
								FIELD->getDirection(4);
								gameManager->manageMissiles();
							}
							break;
						}
						if(pause) {
							if (window->continueButtonPushed(mouseX, mouseY)) pause = false;
							if (window->pauseExitButtonPushed(mouseX, mouseY)) currentGameState = States::MainMenu;
						}
						if (window->flagButtonPushed(mouseX, mouseY)) {
							gameManager->changeFlag(movement->getCrosshairXPos(), movement->getCrosshairYPos());
							music->playMarkSound();
							if (FIELD->tileField[movement->getCrosshairYPos()][movement->getCrosshairXPos()].tileType == DOOR && ammuCount == 3) {
								FIELD->enterObjectInField(movement->getCrosshairXPos(), movement->getCrosshairYPos(), BACKGROUND);
								ammuCount = 0;
							}
						}
					}
					if (currentGameState == States::MainMenu) {
						if (mainMenu->startButtonPushed(mouseX, mouseY)) currentGameState = States::Game;
						if (mainMenu->exitButtonPushed(mouseX, mouseY)) i = 0;
						if (mainMenu->creditsButtonPushed(mouseX, mouseY)) currentGameState = States::Credits;
						if (mainMenu->langButtonPushed(mouseX, mouseY)) currentGameState = States::Language;
					}
					if (currentGameState == States::Splashscreen) {
						currentGameState = States::MainMenu;
					}
					if (currentGameState == States::Credits) {
						if (creditsS->creditsBackButtonPushed(mouseX, mouseY)) currentGameState = States::MainMenu;
					}
					if (currentGameState == States::Language) {
						/*FIELD->currentLanguage = window->languagesButtonPushed(mouseX, mouseY);*/
						switch (window->languagesButtonPushed(mouseX, mouseY)) {
						case Language::German:
							FIELD->currentLanguage = Language::German;
							break;
						case Language::English:
							FIELD->currentLanguage = Language::English;
							break;
						case Language::Francais:
							FIELD->currentLanguage = Language::Francais;
							break;
						case Language::Letzebuergesch:
							FIELD->currentLanguage = Language::Letzebuergesch;
						}
						std::cout << (int)FIELD->currentLanguage;
						if (window->langBackButtonPushed(mouseX, mouseY)) currentGameState = States::MainMenu;
					}
					if (currentGameState == States::End) {
						if (losescreen->EndBackButtonPushed(mouseX, mouseY)) {
							currentGameState = States::MainMenu;
						}
					}
					break;
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
			FIELD->renderClear();
			textures->renderTexture(textures->backgroundTex, FIELD->getRenderer(), 0, 0, 1920, 1080);
			mainMenu->RenderMenu();
			break;
		case States::Game:
			if (!pause) {
				FIELD->renderClear();
				textures->renderTexture(textures->backgroundTex, FIELD->getRenderer(), 0, 0, 1920, 1080);

				FIELD->drawField();
				if (player->returnLifePoints() == 0) currentGameState = States::End;
			}
			if (pause) {
				window->renderPauseScreen();
			}
			break;
		case States::End:
			losescreen->RenderEndScreen();
			losescreen->writeWinText();
			break;
		case States::Credits:
			FIELD->renderClear();
			textures->renderTexture(textures->backgroundTex, FIELD->getRenderer(), 0, 0, 1920, 1080);
			creditsS->renderCreditsWindow();
			break;
		case States::Language:
			FIELD->renderClear();
			textures->renderTexture(textures->backgroundTex, FIELD->getRenderer(), 0, 0, 1920, 1080);
			window->renderLangMenu();
			break;
		}
		
		
		

		
		SDL_RenderPresent(FIELD->getRenderer());
#pragma endregion

		/*int endMs = SDL_GetTicks();
		int delayMs = frameMs - (endMs - startMs);
		SDL_Delay(delayMs);*/
	}

}



