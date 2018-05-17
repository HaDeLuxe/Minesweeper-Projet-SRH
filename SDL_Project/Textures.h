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

	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
	
	void renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y,int w, int h);
	

	SDL_Texture* getTex();

};
