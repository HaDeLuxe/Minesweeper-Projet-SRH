#pragma once

#include "Header.h"



#define WINDOW Field::Instance()

typedef struct Texts {
	std::string text = "";
	SDL_Texture * texture;
	SDL_Surface * surface;
}Texts;


class text
{
private:

	void OpenFont(const char *file, int ptsize);
	TTF_Font *font;


	
	
public:
	text();
	~text();

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
	void preIntializeTexts(SDL_Renderer* ren);	//Creating Textures with Numbers to save processing power.
	//void RenderText(SDL_Renderer* ren, SDL_Texture * texture, int x1, int y1, int x2, int y2);
	void renderNumber(int number, SDL_Renderer * ren, int x1, int y1, int x2, int y2);			//Renders an precreated number between 1 and 8 to the renderer.


	void writeText(int x1, int y1, int x2, int y2, int pSize, std::string text, SDL_Renderer* ren, SDL_Color textColor);
	//SDL_Texture* SurfaceToTexture(SDL_Surface* surf);

};
