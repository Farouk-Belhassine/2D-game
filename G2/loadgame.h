#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void load(int *x, int *iconpos, int *rest, int *enemyposx,int *heroposx,int *heroposy);
void level1(SDL_Surface *ecran, int camx,int iconpos, int rest, int enemyposx,int heroposx,int heroposy);
