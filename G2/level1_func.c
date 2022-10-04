#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "level1.h"

void play_music_level1(Mix_Music *music)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	music=Mix_LoadMUS("level1/sounds/music.mp3");
	Mix_PlayMusic(music, -1);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_EnableKeyRepeat(10, 100);
}

void initlevel1(LEVEL *level)
{
	(*level).map = IMG_Load("level1/pictures/map.png");
	(*level).ladder = IMG_Load("level1/pictures/ladder.png");
	(*level).posmap.x=0;
	(*level).posmap.y=0;
	(*level).posmap.w=6400;
	(*level).posmap.h=1440;
}
