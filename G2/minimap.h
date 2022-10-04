#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
	SDL_Surface *minimap;
	SDL_Surface *icon;
	SDL_Rect minimappos;
	SDL_Rect iconpos;
}RADAR;

void initminimap(RADAR *radar);
