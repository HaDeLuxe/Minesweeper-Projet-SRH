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

void Textures::renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	dst.h = 500;
	dst.w = 500;
	SDL_RenderCopy(ren, tex, NULL, &dst);


}

SDL_Texture * Textures::getTex()
{
	return tex;
}
