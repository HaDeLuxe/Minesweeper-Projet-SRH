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
	SDL_Texture * backgroundTex			= NULL;
	SDL_Texture * wallTex				= NULL;
	SDL_Texture * playerTexUp			= NULL;
	SDL_Texture * playerTexLeft			= NULL;
	SDL_Texture * playerTexRight		= NULL;
	SDL_Texture * playerTexDown			= NULL;
	SDL_Texture * playerDam1Up			= NULL;
	SDL_Texture * playerDam1Right		= NULL;
	SDL_Texture * playerDam1Down		= NULL;
	SDL_Texture * playerDam1Left		= NULL;
	SDL_Texture * playerDam2Up			= NULL;
	SDL_Texture * playerDam2Right		= NULL;
	SDL_Texture * playerDam2Down		= NULL;
	SDL_Texture * playerDam2Left		= NULL;
	SDL_Texture * playerDam3Up			= NULL;
	SDL_Texture * playerDam3Right		= NULL;
	SDL_Texture * playerDam3Down		= NULL;
	SDL_Texture * playerDam3Left		= NULL;
	SDL_Texture * maskTex				= NULL;
	SDL_Texture * crosshairTex			= NULL;
	SDL_Texture * bombLaser				= NULL;
	SDL_Texture * splash				= NULL;
	SDL_Texture * flag					= NULL;
	SDL_Texture * doorEnemy				= NULL;
	SDL_Texture * ammu					= NULL;
	SDL_Texture * HUD_ammu				= NULL;
	SDL_Texture * enemy					= NULL;
	SDL_Texture * laserUp				= NULL;
	SDL_Texture * laserRight			= NULL;
	SDL_Texture * laserDown				= NULL;
	SDL_Texture * laserLeft				= NULL;
	

	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
	
	void renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y,int w, int h);

	void preLoadTextures(SDL_Renderer * ren);

	SDL_Texture* getTex();

};
