#include "Textures.h"

Textures::Textures()
{
}

Textures::~Textures()
{
}

SDL_Texture * Textures::loadTexture(const std::string & file, SDL_Renderer * ren)
{
	SDL_Surface * loadedImage = IMG_Load(file.c_str());
	tex = SDL_CreateTextureFromSurface(ren, loadedImage);
	SDL_FreeSurface(loadedImage);

	if (tex == nullptr) {
		SDL_DestroyRenderer(ren);
		//SDL_DestroyWindow(window->getWindow());
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}


	return tex;

}

void Textures::renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	dst.h = h;
	dst.w = w;
	SDL_RenderCopy(ren, tex, NULL, &dst);
	//SDL_DestroyTexture(tex);
}

void Textures::renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y, int w, int h, SDL_Rect drawRect)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	dst.h = h;
	dst.w = w;
	SDL_RenderCopy(ren, tex, &drawRect, &dst);
	//SDL_DestroyTexture(tex);
}

void Textures::preLoadTextures(SDL_Renderer * ren)
{
	backgroundTex	= loadTexture("Assets/milky-way.jpg",					ren);
	wallTex			= loadTexture("Assets/Meteorite2.png",					ren);
	playerTexUp		= loadTexture("Assets/playerShip2_blue_Up.png",			ren);
	playerTexLeft	= loadTexture("Assets/playerShip2_blue -Left.png",		ren);
	playerTexRight	= loadTexture("Assets/playerShip2_blue -Right.png",		ren);
	playerTexDown	= loadTexture("Assets/playerShip2_blue - Down.png",		ren);
	playerDam1Up	= loadTexture("Assets/playerShip2_damage1_Up.png",		ren);
	playerDam1Right = loadTexture("Assets/playerShip2_damage1_Right.png",	ren);
	playerDam1Down	= loadTexture("Assets/playerShip2_damage1_Down.png",	ren);
	playerDam1Left	= loadTexture("Assets/playerShip2_damage1_Left.png",	ren);
	playerDam2Up	= loadTexture("Assets/playerShip2_damage2_Up.png",		ren);
	playerDam2Right = loadTexture("Assets/playerShip2_damage2_Right.png",	ren);
	playerDam2Down	= loadTexture("Assets/playerShip2_damage2_Down.png",	ren);
	playerDam2Left	= loadTexture("Assets/playerShip2_damage2_Left.png",	ren);
	playerDam3Up	= loadTexture("Assets/playerShip2_damage3_Up.png",		ren);
	playerDam3Right = loadTexture("Assets/playerShip2_damage3_Right.png",	ren);
	playerDam3Down	= loadTexture("Assets/playerShip2_damage3_Down.png",	ren);
	playerDam3Left	= loadTexture("Assets/playerShip2_damage3_Left.png",	ren);
	crosshairTex	= loadTexture("Assets/crosshair110.png",				ren);
	maskTex			= loadTexture("Assets/Mask.png",						ren);
	bombLaser		= loadTexture("Assets/laserRed11.png",					ren);
	splash			= loadTexture("Assets/universe.jpg",					ren);
	flag			= loadTexture("Assets/bolt_bronze.png",					ren);
	doorEnemy		= loadTexture("Assets/spaceShips-enemy.png",					ren);
	ammu			= loadTexture("Assets/things_gold.png",					ren);
	HUD_ammu		= loadTexture("Assets/things_bronze_Raender.png",		ren);
	enemy			= loadTexture("Assets/spaceShips-enemy.png",			ren);
	laserUp			= loadTexture("Assets/laserGreen.png",					ren);
	laserRight		= loadTexture("Assets/laserGreen-right.png",			ren);
	laserDown		= loadTexture("Assets/laserGreen-down.png",				ren);
	laserLeft		= loadTexture("Assets/laserGreen-left.png",				ren);
	shield			= loadTexture("Assets/shield_gold.png",					ren);
	arrowUp			= loadTexture("Assets/grey_sliderUp.png",				ren);
	arrowRight		= loadTexture("Assets/grey_sliderRight.png",			ren);
	arrowDown		= loadTexture("Assets/grey_sliderDown.png",				ren);
	arrowLeft		= loadTexture("Assets/grey_sliderLeft.png",				ren);
	checkmark		= loadTexture("Assets/checkmark.png",					ren);
	playerSpriteSheetUp = loadTexture("Assets/PlayerSpriteSheetUp.png",		ren);
	playerSpriteSheetDown = loadTexture("Assets/PlayerSpriteSheetDown.png", ren);
	playerSpriteSheetRight = loadTexture("Assets/PlayerSpriteSheetRight.png", ren);
	playerSpriteSheetLeft = loadTexture("Assets/PlayerSpriteSheetLeft.png", ren);
	Ammu_Glowing	= loadTexture("Assets/Ammu_Glowing.png",				ren);
	pill			= loadTexture("Assets/pill_red.png",					ren);
	starDestroyer	= loadTexture("Assets/Star Destroyer.png",				ren);
	playerDamage	= loadTexture("Assets/PlayerDamage.png",				ren);
	goalShip		= loadTexture("Assets/ship4.png",						ren);
	story = loadTexture("Assets/story.png", ren);


	Tutorial_Controls_DE = loadTexture("Assets/Tutorial Felder/Tutorial_Steuerung_DE.png", ren);
	Tutorial_Controls_FR = loadTexture("Assets/Tutorial Felder/Tutorial_Steuerung_FR.png", ren);
	Tutorial_Controls_EN = loadTexture("Assets/Tutorial Felder/Tutorial_Steuerung_EN.png", ren);
	Tutorial_Controls_LU = loadTexture("Assets/Tutorial Felder/Tutorial_Steuerung_LU.png", ren);

}

void Textures::renderTurnedTexture(SDL_Texture* tex, SDL_Renderer * ren, int deg, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.h = h;
	dst.w = w;
	SDL_RenderCopyEx(ren, tex,NULL , &dst, deg, NULL, SDL_FLIP_NONE);
}

void Textures::renderTurnedTexture(SDL_Texture* tex, SDL_Renderer * ren, int deg, int x, int y, int w, int h, SDL_Rect drawRect)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.h = h;
	dst.w = w;
	SDL_RenderCopyEx(ren, tex, &drawRect, &dst, deg, NULL, SDL_FLIP_NONE);
}


SDL_Texture * Textures::getTex()
{
	return tex;
}