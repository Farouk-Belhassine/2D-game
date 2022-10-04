#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "settingsheader.h"

void settings(SDL_Surface *ecran, Menu menu, int continuer, Mix_Chunk *cursorsound, Mix_Music *music)
{
	SDL_Rect cursorpos, vfx, musicpos;
	SDL_Event event;
	ONOFF onoff;

	cursorpos=menu.cursorpos;
	
	cursorpos.y=298;

	initonoff(&onoff,&vfx,&musicpos);

	while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
	case SDL_QUIT:
		continuer=0;
	break;

	 case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
		case SDLK_UP:
			Mix_PlayChannel(-1,cursorsound, 0);
			selection2(&cursorpos,1,0);
		break;

                case SDLK_DOWN:
			Mix_PlayChannel(-1,cursorsound, 0);
			selection2(&cursorpos,0,1);
		break;

		case SDLK_ESCAPE:
			continuer=0;
		break;

		case SDLK_RETURN:
			modfile(&onoff,cursorpos,music);
			if(cursorpos.y==418) continuer=0;
		break;
        }
	
    }


	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	SDL_BlitSurface(menu.background, NULL, ecran, &menu.pos);
	SDL_BlitSurface(menu.cursor, NULL, ecran, &cursorpos);
	SDL_BlitSurface(onoff.vfx, NULL, ecran, &vfx);
	SDL_BlitSurface(onoff.music, NULL, ecran, &musicpos);
	SDL_BlitSurface(menu.m2, NULL, ecran, &menu.pos);
        SDL_Flip(ecran);

	}
	SDL_FreeSurface(onoff.vfx);
	SDL_FreeSurface(onoff.music);

}
