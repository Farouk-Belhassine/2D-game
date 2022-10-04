#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "loadgame.h"

void loadgame(SDL_Surface *ecran)
{
	int camx,iconpos,rest,enemyposx,heroposx,heroposy;

	load(&camx,&iconpos,&rest,&enemyposx,&heroposx,&heroposy);
	level1(ecran,camx,iconpos,rest,enemyposx,heroposx,heroposy);
}
