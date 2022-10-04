#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "health.h"

void inithealth(HEALTH *health)
{
	(*health).rest=3;
	(*health).bar3=IMG_Load("global/objects/health/health3.png");
	(*health).bar2=IMG_Load("global/objects/health/health2.png");
	(*health).bar1=IMG_Load("global/objects/health/health1.png");
	(*health).bar0=IMG_Load("global/objects/health/health0.png");
}


