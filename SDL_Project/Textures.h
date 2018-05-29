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
	SDL_Texture * backgroundTex = NULL;
	SDL_Texture * wallTex = NULL;
	SDL_Texture * playerTex = NULL;
	SDL_Texture * maskTex = NULL;
	

	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
	
	void renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y,int w, int h);

	void preLoadTextures(SDL_Renderer * ren);

	SDL_Texture* getTex();

};
