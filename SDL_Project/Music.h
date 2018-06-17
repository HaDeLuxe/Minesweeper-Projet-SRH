#pragma once

#include "SDL_mixer.h"
#include "Header.h"
class Music
{
private:
	Mix_Chunk * markSound;
	Mix_Chunk * mouseClick;
	Mix_Music * backgroundMusic;
	
public:
	Music();
	~Music();
	void initMusic();	//iniate music
	void loadBackGroundMusic();	
	void playBackgroundMusic();
	void loadSounds();
	void playMarkSound();
	void playMouseClickSound();


};

