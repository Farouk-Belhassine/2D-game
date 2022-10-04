#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct{
	SDL_Surface *m1;
	SDL_Surface *m2;
	SDL_Surface *cursor;
	SDL_Rect posmenu;
	SDL_Rect poscursor;
}IGM;

void initingamemenu(IGM *igm);
void selection3(SDL_Rect *cursorpos, int xu, int xd);
void save(int x,int iconpos, int rest, SDL_Rect enemypos, SDL_Rect heropos);
