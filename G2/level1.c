#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "level1.h"
#include "characters.h"
#include "collision.h"
#include "camera.h"
#include "objects.h"
#include "health.h"
#include "minimap.h"


void level1(SDL_Surface *ecran, int camx, int iconpos, int rest, int enemyposx,int heroposx,int heroposy)
{
	SDL_Surface *hero=NULL, *badguy=NULL, *h=NULL;
	SDL_Rect frame, camera, heropos;
	OBJECTS objects;
	Mix_Music *music;
	SDL_Event event;

	LEVEL level;
	Urbach urbach;
	ENEMY enemy;
	HEALTH health;
	RADAR radar;

	int continuer=1, m=20, heroframe=0, collision, xl=0, xr=0, l=0, r=1, clr=0, enemyframe=0,i=0;


	initlevel1(&level);
	initcamera(&camera);
	inithealth(&health);
	initminimap(&radar);
	intitialiserurbach(&urbach);
	initobjects(&objects);
	intitialiserenemy(&enemy);

	hero = urbach.idleright;

	if(enemyposx!=0){
		enemy.pos.x=enemyposx;
		urbach.pos.x=heroposx;
		urbach.pos.y=heroposy;
		camera.x=camx;
		radar.iconpos.x=iconpos;
		health.rest=rest;
	}

	play_music_level1(music);

	while(continuer){
        	SDL_PollEvent(&event);
        	switch(event.type)
       	 	
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
            		{
			case SDLK_LEFT:
				xl=1; l=r=0;
				cam(&camera,&urbach.pos,m,xl,xr,&clr);
				radar.iconpos.x-=2;
			break;
	
			case SDLK_RIGHT:
				xr=1; l=r=0;
				cam(&camera,&urbach.pos,m,xl,xr,&clr);
				radar.iconpos.x+=2;
			break;

			case SDLK_ESCAPE:
				continuer=ingamemenu(ecran,camera,radar.iconpos.x,health.rest,enemy.pos,urbach.pos);
			break;
       			}
		break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
            		{
			case SDLK_LEFT:
				r=xl=0; l=1; clr=0;
			break;
	
			case SDLK_RIGHT:
				l=xr=0; r=1; clr=0;
			break;
       			}
		break;
		}
	if(col(enemy.pos,urbach.pos)==1&&health.rest>=0&&i==0){
		health.rest-=1;
		i=1;
	}
	if(col(enemy.pos,urbach.pos)==0&&i!=0) i=0;
	if(health.rest==3) h=health.bar3;
	if(health.rest==2) h=health.bar2;
	if(health.rest==1) h=health.bar1;
	if(health.rest==0) h=health.bar0;
	drawenemy(clr,&enemy.pos,m);
	hero=urbachdirection(xl,xr,urbach,l,r);
	badguy=enemydirection(&enemy,urbach.pos,3);
	resetframeurbach(xl,xr,&heroframe,&urbach,l,r);
	resetframenemy(&enemyframe,&enemy);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	SDL_BlitSurface(level.map, &camera, ecran, &level.posmap);
	SDL_BlitSurface(h, NULL, ecran, &objects.healthpos);
	SDL_BlitSurface(hero, &urbach.frame, ecran, &urbach.pos);
	SDL_BlitSurface(badguy, &enemy.frame, ecran, &enemy.pos);
	SDL_BlitSurface(radar.minimap, NULL, ecran, &radar.minimappos);
	SDL_BlitSurface(radar.icon, NULL, ecran, &radar.iconpos);
        SDL_Flip(ecran);
    }

	SDL_FreeSurface(level.map);
	SDL_FreeSurface(hero);
	SDL_FreeSurface(badguy);
	SDL_FreeSurface(h);
}
