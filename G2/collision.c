#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "collision.h"

int col(SDL_Rect pos1, SDL_Rect pos2)
{
	if(pos1.x<=pos2.x+pos2.w&&pos1.x>=pos2.x-pos2.w&&pos1.y<=pos2.y+pos2.h&&pos1.y>=pos2.y-pos2.h) return 1;
	else return 0;
}
