#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "loadgame.h"

void load(int *camx, int *iconpos,int *rest, int *enemyposx,int *heroposx,int *heroposy)
{
	FILE* f;
	f=fopen("save","r");
	if(f!=NULL){
		fscanf(f,"%d\n%d\n%d\n%d\n%d\n%d",&*camx,&*iconpos,&*rest,&*enemyposx,&*heroposx,&*heroposy);
		fclose(f);
	}
	else *enemyposx=0;
}

