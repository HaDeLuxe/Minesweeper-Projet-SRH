#include "text.h"
#include <cstdlib>
#include <iostream>







text::text()
{

}


text::~text()
{
}

void text::preIntializeTexts(SDL_Renderer* ren)
{
	
	SDL_Color textColor = { 255, 255, 255, 255 };
	font = OpenFont("OpenSans - Regular.ttf", 50);
	std::string text = "1";
	SDL_Surface * solidSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);

	t1.surface = solidSurface;
	t1.texture = SDL_CreateTextureFromSurface(ren, t1.surface);
	t2.surface = TTF_RenderText_Solid(font, "2", textColor);
	t2.texture = SDL_CreateTextureFromSurface(ren, t2.surface);
	t3.surface = TTF_RenderText_Solid(font, "3", textColor);
	t3.texture = SDL_CreateTextureFromSurface(ren, t3.surface);
	t4.surface = TTF_RenderText_Solid(font, "4", textColor);
	t4.texture = SDL_CreateTextureFromSurface(ren, t4.surface);
	t5.surface = TTF_RenderText_Solid(font, "5", textColor);
	t5.texture = SDL_CreateTextureFromSurface(ren, t5.surface);
	t6.surface = TTF_RenderText_Solid(font, "6", textColor);
	t6.texture = SDL_CreateTextureFromSurface(ren, t6.surface);
	t7.surface = TTF_RenderText_Solid(font, "7", textColor);
	t7.texture = SDL_CreateTextureFromSurface(ren, t7.surface);
	t8.surface = TTF_RenderText_Solid(font, "8", textColor);
	t8.texture = SDL_CreateTextureFromSurface(ren, t8.surface);
}

void text::RenderText(SDL_Renderer * ren, SDL_Texture * texture, int x1, int y1, int x2, int y2)
{
	SDL_Rect solidRect;
	solidRect.x = x1;
	solidRect.y = y1;
	solidRect.h = y2;
	solidRect.w = x2;
	SDL_RenderCopy(ren, texture, NULL, &solidRect);
}

void text::renderNumber(int number, SDL_Renderer * ren, int x1, int y1, int x2, int y2)
{
	if (number > 0 && number <= 8) {
		SDL_Rect solidRect;
		solidRect.x = x1;
		solidRect.y = y1;
		solidRect.h = y2;
		solidRect.w = x2;
		switch (number) {
		case 0:
			break;
		case 1:
			SDL_RenderCopy(ren, t1.texture, NULL, &solidRect);
			break;
		case 2:
			SDL_RenderCopy(ren, t2.texture, NULL, &solidRect);
			break;
		case 3:
			SDL_RenderCopy(ren, t3.texture, NULL, &solidRect);
			break;
		case 4:
			SDL_RenderCopy(ren, t4.texture, NULL, &solidRect);
			break;
		case 5: 
			SDL_RenderCopy(ren, t5.texture, NULL, &solidRect);
			break;
		case 6:
			SDL_RenderCopy(ren, t6.texture, NULL, &solidRect);
			break;
		case 7:
			SDL_RenderCopy(ren, t7.texture, NULL, &solidRect);
			break;
		case 8:
			SDL_RenderCopy(ren, t8.texture, NULL, &solidRect);
			break;
		}
	}
	else std::cout << "renderNumber(): The entered Number is out of range!" << std::endl;
}


int text::TTF_Initiate()
{
	if (TTF_Init() == -1) {
		std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
		exit(2);
	}
	return 1;
}

TTF_Font * text::OpenFont(const char * file, int ptsize)
{
	font = TTF_OpenFont(file, ptsize);

	if (!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	return font;
}

void text::writeText(int x1, int y1, int x2, int y2, int pSize, std::string text, SDL_Renderer* ren)
{
	int TTF_Initiate();
	std::string fontfile = "OpenSans-Regular.ttf";
	OpenFont(fontfile.c_str(), 50);
	

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



