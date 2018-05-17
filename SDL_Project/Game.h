#pragma once

#include "Header.h"
//#include "Textures.h"
//#include "Field.h"
//#include "Windows.h"

//#include "Textures.h"

//#define WINDOW Field::Instance()


class Game
{
private:

	TTF_Font * OpenFont(const char *file, int ptsize);
	TTF_Font *font;
public:
	Game();
	~Game();

	
	int TTF_Initiate();
	void writeText(int x1, int y1, int x2, int y2, int pSize, std::string text, SDL_Renderer* ren);
	//SDL_Texture* SurfaceToTexture(SDL_Surface* surf);

};
