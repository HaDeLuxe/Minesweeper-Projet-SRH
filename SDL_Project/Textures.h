#pragma once
#include "Header.h"
//#include "Field.h"



class Textures
{
private:
	//Window* window = new Window();


	SDL_Texture* tex;
public:
	Textures();
	~Textures();
	//creates all textures for textures
	SDL_Texture * backgroundTex = NULL;
	SDL_Texture * wallTex = NULL;
	SDL_Texture * playerTexUp = NULL;
	SDL_Texture * playerTexLeft = NULL;
	SDL_Texture * playerTexRight = NULL;
	SDL_Texture * playerTexDown = NULL;
	SDL_Texture * playerDam1Up = NULL;
	SDL_Texture * playerDam1Right = NULL;
	SDL_Texture * playerDam1Down = NULL;
	SDL_Texture * playerDam1Left = NULL;
	SDL_Texture * playerDam2Up = NULL;
	SDL_Texture * playerDam2Right = NULL;
	SDL_Texture * playerDam2Down = NULL;
	SDL_Texture * playerDam2Left = NULL;
	SDL_Texture * playerDam3Up = NULL;
	SDL_Texture * playerDam3Right = NULL;
	SDL_Texture * playerDam3Down = NULL;
	SDL_Texture * playerDam3Left = NULL;
	SDL_Texture * maskTex = NULL;
	SDL_Texture * crosshairTex = NULL;
	SDL_Texture * bombLaser = NULL;
	SDL_Texture * splash = NULL;
	SDL_Texture * flag = NULL;
	SDL_Texture * doorEnemy = NULL;
	SDL_Texture * ammu = NULL;
	SDL_Texture * HUD_ammu = NULL;
	SDL_Texture * enemy = NULL;
	SDL_Texture * laserUp = NULL;
	SDL_Texture * laserRight = NULL;
	SDL_Texture * laserDown = NULL;
	SDL_Texture * laserLeft = NULL;
	SDL_Texture * shield = NULL;
	SDL_Texture * arrowUp = NULL;
	SDL_Texture * arrowDown = NULL;
	SDL_Texture * arrowLeft = NULL;
	SDL_Texture * arrowRight = NULL;
	SDL_Texture * checkmark = NULL;
	SDL_Texture * playerSpriteSheetUp = NULL;
	SDL_Texture * playerSpriteSheetDown = NULL;
	SDL_Texture * playerSpriteSheetRight = NULL;
	SDL_Texture * playerSpriteSheetLeft = NULL;
	SDL_Texture * Ammu_Glowing = NULL;
	SDL_Texture * pill = NULL;
	SDL_Texture * starDestroyer = NULL;
	SDL_Texture * playerDamage = NULL;
	SDL_Texture * goalShip = NULL;
	SDL_Texture * story = NULL;

	SDL_Texture * Tutorial_Controls_DE = NULL;
	SDL_Texture * Tutorial_Controls_FR = NULL;
	SDL_Texture * Tutorial_Controls_EN = NULL;
	SDL_Texture * Tutorial_Controls_LU = NULL;


	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren); //loads texture
	
	void renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y,int w, int h);
	void renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y, int w, int h, SDL_Rect drawRect);

	void preLoadTextures(SDL_Renderer * ren);// preloades all textures for better performance
	void renderTurnedTexture(SDL_Texture* tex, SDL_Renderer * ren, int deg, int x, int y, int w, int h);
	void renderTurnedTexture(SDL_Texture* tex, SDL_Renderer * ren, int deg, int x, int y, int w, int h, SDL_Rect drawRect);
	SDL_Texture* getTex();

};
