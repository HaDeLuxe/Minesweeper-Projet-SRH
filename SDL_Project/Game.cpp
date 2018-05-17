#include "Game.h"
#include <cstdlib>
#include <iostream>





Game::Game()
{
}


Game::~Game()
{
}


int Game::TTF_Initiate()
{
	if (TTF_Init() == -1) {
		std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
		exit(2);
	}
	return 1;
}

TTF_Font * Game::OpenFont(const char * file, int ptsize)
{
	font = TTF_OpenFont(file, ptsize);

	if (!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	return font;
}

void Game::writeText(int x1, int y1, int x2, int y2, int pSize, std::string text, SDL_Renderer* ren)
{
	TTF_Initiate();

	std::string fontfile = "OpenSans-Regular.ttf";

	OpenFont(fontfile.c_str(), pSize);

	SDL_Texture* solidTexture;
	SDL_Rect solidRect;
	solidRect.x = x1;
	solidRect.y = y1;
	solidRect.h = y2;
	solidRect.w = x2;

	SDL_Color textColor = { 255, 255, 255, 255 };
	SDL_Surface * solid = TTF_RenderText_Solid(font, text.c_str(), textColor);

	solidTexture = SDL_CreateTextureFromSurface(ren, solid);
	SDL_FreeSurface(solid);
	//std::cout << "Text has been written out" << std::endl;
	SDL_RenderCopy(ren, solidTexture, NULL, &solidRect);
	TTF_CloseFont(font);
	SDL_DestroyTexture(solidTexture);
}

