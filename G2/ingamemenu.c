#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ingamemenu.h"


int ingamemenu(SDL_Surface *screen, SDL_Rect camera, int iconpos,int rest, SDL_Rect enemypos, SDL_Rect heropos)
{
	SDL_Event event;
	Mix_Chunk *cursorsound;
	int go=1,r=1;
	IGM igm;
	
	initingamemenu(&igm);
	cursorsound = Mix_LoadWAV("menu/sounds/cursor.wav");

	while(go)
    {
	SDL_WaitEvent(&event);
	switch(event.type)
	{

	case SDL_KEYDOWN:
	switch (event.key.keysym.sym)
	{
		case SDLK_UP:
			Mix_PlayChannel(-1,cursorsound, 0);
			selection3(&igm.poscursor,1,0);
		break;

		case SDLK_DOWN:
			Mix_PlayChannel(-1,cursorsound, 0);
			selection3(&igm.poscursor,0,1);
		break;

		case SDLK_ESCAPE:
			go=0;
		break;

		case SDLK_RETURN:
			if(igm.poscursor.y==241){
				r=go=0;
				save(camera.x,iconpos,rest,enemypos,heropos);
			}
			if(igm.poscursor.y==355) go=0;
		break;
        }
	
    	}


	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	SDL_BlitSurface(igm.m1, NULL, screen, &igm.posmenu);
	SDL_BlitSurface(igm.cursor, NULL, screen, &igm.poscursor);
	SDL_BlitSurface(igm.m2, NULL, screen, &igm.posmenu);
        SDL_Flip(screen);

	}
	SDL_FreeSurface(igm.m1);
	SDL_FreeSurface(igm.m2);
	SDL_FreeSurface(igm.cursor);
	Mix_FreeChunk(cursorsound);

	return r;
}
