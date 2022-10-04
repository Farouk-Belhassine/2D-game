#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "camera.h"

void initcamera(SDL_Rect *cam)
{
	(*cam).x=0;
	(*cam).y=0;
	(*cam).h=720;
	(*cam).w=1280;

}

void cam(SDL_Rect *camera, SDL_Rect *heropos, int m, int xl, int xr, int *clr)
{
	if(xl){
		if((*camera).x<=0||(*heropos).x>=640){
			(*heropos).x-=m;
			if(*clr!=0) *clr=0;
		}
		else{
			(*camera).x-=m;
			*clr=1;
		}
	}

	if(xr){
		if((*camera).x>=6398/*mapwidth-screenwidth*/||(*heropos).x<=640){
			(*heropos).x+=m;
			if(*clr!=0) *clr=0;
		}
		else{
			(*camera).x+=m;
			*clr=-1;
		}
	}
}

