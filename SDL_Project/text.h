#pragma once

#include "Header.h"
//#include "Textures.h"
//#include "Field.h"
//#include "Windows.h"

//#include "Textures.h"

//#define WINDOW Field::Instance()

typedef struct Texts {
	std::string text = "";
	SDL_Texture * texture;
	SDL_Surface * surface;
};
class Game
{
private:

	TTF_Font * OpenFont(const char *file, int ptsize);
	TTF_Font *font;

	Texts t1;
	Texts t2;
	Texts t3;
	Texts t4;
	Texts t5;
	Texts t6;
	Texts t7;
	Texts t8;
	Texts t9;
	
	int TTF_Initiate();
public:
	Game();
	~Game();

	void preIntializeTexts(SDL_Renderer* ren);
	void RenderText(SDL_Renderer* ren, SDL_Texture * texture, int x1, int y1, int x2, int y2);


	void writeText(int x1, int y1, int x2, int y2, int pSize, std::string text, SDL_Renderer* ren);
	//SDL_Texture* SurfaceToTexture(SDL_Surface* surf);

};
