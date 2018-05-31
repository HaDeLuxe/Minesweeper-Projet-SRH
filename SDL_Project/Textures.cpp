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
	return tex;

	if (tex == nullptr) {
		SDL_DestroyRenderer(ren);
		//SDL_DestroyWindow(window->getWindow());
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
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


}



void Textures::preLoadTextures(SDL_Renderer * ren)
{
	backgroundTex = loadTexture("Assets/milky-way.jpg", ren);
	wallTex = loadTexture("Assets/meteorBrown_med1.png", ren);
	playerTexUp = loadTexture("Assets/playerShip2_blue_Up.png", ren);
	playerTexLeft = loadTexture("Assets/playerShip2_blue -Left.png", ren);
	playerTexRight = loadTexture("Assets/playerShip2_blue -Right.png", ren);
	playerTexDown = loadTexture("Assets/playerShip2_blue - Down.png", ren);
	playerDam1Up = loadTexture("Assets/playerShip2_damage1_Up.png", ren);
	playerDam2Right = loadTexture("Assets/playerShip2_damage1_Right.png", ren);
	playerDam1Down = loadTexture("Assets/playerShip2_damage1_Down.png", ren);
	playerDam1Left = loadTexture("Assets/playerShip2_damage1_Left.png", ren);
	playerDam2Up = loadTexture("Assets/playerShip2_damage2_Up.png", ren);
	playerDam2Right = loadTexture("Assets/playerShip2_damage2_Right.png", ren);
	playerDam2Down = loadTexture("Assets/playerShip2_damage2_Down.png", ren);
	playerDam2Left = loadTexture("Assets/playerShip2_damage2_Left.png", ren);
	playerDam3Up = loadTexture("Assets/playerShip2_damage3_Up.png", ren);
	playerDam3Right = loadTexture("Assets/playerShip2_damage3_Right.png", ren);
	playerDam3Down = loadTexture("Assets/playerShip2_damage3_Down.png", ren);
	playerDam3Left = loadTexture("Assets/playerShip2_damage3_Left.png", ren);
	crosshairTex = loadTexture("Assets/crosshair110.png", ren);
	maskTex = loadTexture("Assets/Mask.png", ren);
}

SDL_Texture * Textures::getTex()
{
	return tex;
}