#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "settingsheader.h"

void selection2(SDL_Rect *cursorpos, int xu, int xd)
{
	if(xu==1){
		if((*cursorpos).y==298) (*cursorpos).y=418;
		else{
			if((*cursorpos).y==418) (*cursorpos).y=338;
			else (*cursorpos).y-=40;
	}
	}
	if(xd==1){
		if((*cursorpos).y==338) (*cursorpos).y=418;
		else{
			if((*cursorpos).y==418) (*cursorpos).y=298;
			else (*cursorpos).y+=40;
		}
	}
}

void initonoff(ONOFF *onoff, SDL_Rect *vfxpos, SDL_Rect *musicpos)
{
	FILE *f;
	int vfxactive,musicactive;
	f=fopen("settings.txt","r");

	if(f!=NULL){
    		fscanf(f,"vfxactive: %d musicactive: %d\n",&vfxactive,&musicactive);			
			if(vfxactive==1) (*onoff).vfx = IMG_Load("menu/pictures/on.png");
			else (*onoff).vfx = IMG_Load("menu/pictures/off.png");

			if(musicactive==1) (*onoff).music = IMG_Load("menu/pictures/on.png");
			else (*onoff).music = IMG_Load("menu/pictures/off.png");
		fclose(f);
	}
	else{
		f=fopen("settings.txt","w");
		fprintf(f,"vfxactive: %d musicactive: %d\n",1,1);
		fclose(f);
	}

	(*vfxpos).x=247;
	(*vfxpos).y=304;
	(*musicpos).x=247;
	(*musicpos).y=344;
}

void modfile(ONOFF *onoff, SDL_Rect cursorpos, Mix_Music *music)
{
	FILE *f;
	int vfxactive,musicactive;
	f=fopen("settings.txt","r");
	
	if(cursorpos.y==338){
		fscanf(f,"vfxactive: %d musicactive: %d\n",&vfxactive,&musicactive);
		f=fopen("settings.txt","w");
		if(musicactive==1){
			(*onoff).music = IMG_Load("menu/pictures/off.png");
			fprintf(f,"vfxactive: %d musicactive: %d\n",vfxactive,0);
		}
		else{
			(*onoff).music = IMG_Load("menu/pictures/on.png");
			fprintf(f,"vfxactive: %d musicactive: %d\n",vfxactive,1);
		}
		fclose(f);
		sounds(music);
	}
	if(cursorpos.y==298){
		fscanf(f,"vfxactive: %d musicactive: %d\n",&vfxactive,&musicactive);
		f=fopen("settings.txt","w");
		if(vfxactive==1){
			(*onoff).vfx = IMG_Load("menu/pictures/off.png");
			fprintf(f,"vfxactive: %d musicactive: %d\n",0,musicactive);
		}
		else{
			(*onoff).vfx = IMG_Load("menu/pictures/on.png");
			fprintf(f,"vfxactive: %d musicactive: %d\n",1,musicactive);
		}
		fclose(f);
	}
}
