#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct{
	int rest;
	SDL_Surface *bar0;
	SDL_Surface *bar1;
	SDL_Surface *bar2;
	SDL_Surface *bar3;
}HEALTH;

void inithealth(HEALTH *health);

