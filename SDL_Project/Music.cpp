#include "Music.h"



Music::Music()
{
}


Music::~Music()
{
}

void Music::initMusic()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024 == -1);
}

void Music::loadBackGroundMusic()
{
	std::string path1 = "Music/cebuana_one.mp3";
	backgroundMusic = Mix_LoadMUS(path1.c_str());
	if (!backgroundMusic) {
		printf("SDL_Mixer: %s\n", Mix_GetError());
		
		// handle error
		exit(2);
	}
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
}

void Music::playBackgroundMusic()
{
	Mix_PlayMusic(backgroundMusic, -1);
}

void Music::loadSounds()
{
	markSound = Mix_LoadWAV("Music/tone1.wav");
	mouseClick = Mix_LoadWAV("Music/mouserelease1.wav");
	Mix_VolumeChunk(mouseClick, MIX_MAX_VOLUME);
	
}

void Music::playMarkSound()
{
	Mix_PlayChannel(-1, markSound, 0);
}

void Music::playMouseClickSound()
{
	Mix_PlayChannel(-1, mouseClick, 0);
}


