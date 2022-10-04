#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menuheader.h"

typedef struct{
	SDL_Surface *vfx;
	SDL_Surface *music;
}ONOFF;

void selection2(SDL_Rect *cursorpos, int xu, int xd);
void initonoff(ONOFF *onoff, SDL_Rect *vfxpos, SDL_Rect *musicpos);
void modfile(ONOFF *onoff, SDL_Rect cursorpos, Mix_Music *music);
