#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menuheader.h"


void menu()
{
SDL_Surface *ecran=NULL;
SDL_Rect mouse;
Mix_Music *music;
Mix_Chunk *cursorsound;
SDL_Event event;
Menu menu;

int continuer=1,enemyposx=0,rest,iconpos,heroposx,heroposy,x;

SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("Trial Of the gray matter", NULL);
initmenu(&menu);
SDL_Flip(ecran);

sounds(music);
cursorsound=Mix_LoadWAV("menu/sounds/cursor.wav");

while (continuer)
    {
	SDL_WaitEvent(&event);
        switch(event.type)
        {
	case SDL_QUIT:
		continuer=0;
	break;

	case SDL_MOUSEMOTION:
		mouse.x = event.motion.x;
		mouse.y = event.motion.y;
	break;

	case SDL_MOUSEBUTTONDOWN:
		if(mouse.x>=100&&mouse.x<=313&&mouse.y>=298&&mouse.y<=336){
			free_menu(music,cursorsound,&menu);
			level1(ecran,x,iconpos,rest,enemyposx,heroposx,heroposy);
			initmenu(&menu);
			sounds(music);
			cursorsound=Mix_LoadWAV("menu/sounds/cursor.wav");
		}
		if(mouse.x>=100&&mouse.x<=313&&mouse.y>=338&&mouse.y<=376) loadgame(ecran);
		if(mouse.x>=100&&mouse.x<=313&&mouse.y>=378&&mouse.y<=416) settings(ecran,menu,continuer,cursorsound,music);
		if(mouse.x>=100&&mouse.x<=313&&mouse.y>=418&&mouse.y<=456){
			continuer=0;
		}
	break;

	 case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
		case SDLK_UP:
			Mix_PlayChannel(-1,cursorsound, 0);
			selection(&menu.cursorpos,1,0);
		break;

                case SDLK_DOWN:
			Mix_PlayChannel(-1,cursorsound, 0);
			selection(&menu.cursorpos,0,1);
		break;

		case SDLK_ESCAPE:
			continuer=0;
		break;

		case SDLK_RETURN:
			if(menu.cursorpos.y==298){
				free_menu(music,cursorsound,&menu);
				level1(ecran,x,iconpos,rest,enemyposx,heroposx,heroposy);
				initmenu(&menu);
				sounds(music);
				cursorsound=Mix_LoadWAV("menu/sounds/cursor.wav");
			}
			if(menu.cursorpos.y==338) loadgame(ecran);
			if(menu.cursorpos.y==378) settings(ecran,menu,continuer,cursorsound,music);
			if(menu.cursorpos.y==418) continuer=0;
		break;
        	}
	}
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	SDL_BlitSurface(menu.background, NULL, ecran, &menu.pos);
	SDL_BlitSurface(menu.cursor, NULL, ecran, &menu.cursorpos);
	SDL_BlitSurface(menu.m1, NULL, ecran, &menu.pos);
        SDL_Flip(ecran);
    }

	free_menu(music,cursorsound,&menu);
	SDL_Quit();
}
