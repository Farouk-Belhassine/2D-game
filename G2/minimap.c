#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minimap.h"

void initminimap(RADAR *radar)
{
	(*radar).minimap=IMG_Load("level1/pictures/minimap.png");
	(*radar).icon=IMG_Load("level1/pictures/icon.png");
	(*radar).minimappos.x=250;
	(*radar).minimappos.y=30;
	(*radar).iconpos.x=270;
	(*radar).iconpos.y=70;
}
