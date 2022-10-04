#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ingamemenu.h"
#include "level1.h"


void initingamemenu(IGM *igm)
{
	(*igm).m1 = IMG_Load("menu/pictures/igmbackground.png");
	(*igm).m2 = IMG_Load("menu/pictures/igmwriting.png");
	(*igm).cursor = IMG_Load("menu/pictures/cursor.png");
	(*igm).posmenu.x=0;
	(*igm).posmenu.y=0;
	(*igm).poscursor.x=554;
	(*igm).poscursor.y=241;
}

void selection3(SDL_Rect *cursorpos, int xu, int xd)
{
	if(xu==1){
		if((*cursorpos).y==241) (*cursorpos).y=355;
		else{
			if((*cursorpos).y==355) (*cursorpos).y=279;
			else (*cursorpos).y-=38;
		}
	}
	if(xd==1){
		if((*cursorpos).y==279) (*cursorpos).y=355;
		else{
			if((*cursorpos).y==355) (*cursorpos).y=241;
			else (*cursorpos).y+=38;
		}
	}
}

void save(int x, int iconpos, int rest, SDL_Rect enemypos, SDL_Rect heropos)
{
	FILE* f=NULL;
	
	f=fopen("save","w");
        fprintf(f,"%d\n%d\n%d\n%d\n%d\n%d",x,iconpos,rest,enemypos.x,heropos.x,heropos.y);
        fclose(f);
}
