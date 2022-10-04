#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "objects.h"

void initobjects(OBJECTS *object)
{
	(*object).healthpos.x =40;
	(*object).healthpos.y =30;
	(*object).healthpos.h =39;
	(*object).healthpos.w =139;
}

void drawobject(int cam, SDL_Rect *objectpos, int m)
{
	if(cam==1) (*objectpos).x+=m;
	if(cam==-1) (*objectpos).x-=m;
}
