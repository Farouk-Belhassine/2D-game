#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menuheader.h"

void play_music_menu(Mix_Music *music, int on)
{
	if(on==1){	
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
		music = Mix_LoadMUS("menu/sounds/menu.mp3");
		Mix_PlayMusic(music, -1);
		SDL_EnableKeyRepeat(10, 100);
	}
	else{
		Mix_FreeMusic(music);
		Mix_CloseAudio();
	}
}

void free_menu(Mix_Music *music, Mix_Chunk *cursorsound,Menu *menu)
{
	Mix_FreeMusic(music);
	Mix_FreeChunk(cursorsound);
	Mix_CloseAudio();
	SDL_FreeSurface((*menu).background);
	SDL_FreeSurface((*menu).m1);
	SDL_FreeSurface((*menu).m2);
	SDL_FreeSurface((*menu).m3);
	SDL_FreeSurface((*menu).cursor);
}

void selection(SDL_Rect *cursorpos, int xu, int xd)
{
	if(xu==1){
		if((*cursorpos).y==298) (*cursorpos).y=418;
		else (*cursorpos).y-=40;
	}
	if(xd==1){
		if((*cursorpos).y==418) (*cursorpos).y=298;
		else (*cursorpos).y+=40;
	}
}

void initmenu(Menu *menu)
{
	(*menu).background = IMG_Load("menu/pictures/background.png");
	(*menu).m1 = IMG_Load("menu/pictures/menu1.png");
	(*menu).m2 = IMG_Load("menu/pictures/menu2.png");
	(*menu).m3 = IMG_Load("menu/pictures/menu3.png");
	(*menu).cursor = IMG_Load("menu/pictures/cursor.png");
	(*menu).cursorpos.x=99;
	(*menu).cursorpos.y=298;
	(*menu).pos.x=0;
	(*menu).pos.y=0;
}

void sounds(Mix_Music *music)
{
	FILE *f;
	int vfxactive,musicactive,on;

	f=fopen("settings.txt","r");

	fscanf(f,"vfxactive: %d musicactive: %d\n",&vfxactive,&musicactive);
	if(musicactive==1) play_music_menu(music, 1);
	else play_music_menu(music, 0);
	
	fclose(f);
}
