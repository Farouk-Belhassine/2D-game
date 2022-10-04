#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct{
	SDL_Surface *idleleft;
	SDL_Surface *idleright;
	SDL_Surface *left;
	SDL_Surface *right;
	SDL_Rect pos;
	SDL_Rect frame;
}Urbach;


typedef struct{
	SDL_Surface *idleleft;
	SDL_Surface *idleright;
	SDL_Surface *left;
	SDL_Surface *right;
	SDL_Rect pos;
	SDL_Rect frame;
}Weithe;

typedef struct{
	SDL_Surface *runleft;
	SDL_Surface *runright;
	SDL_Surface *attackleft;
	SDL_Surface *attackright;
	SDL_Rect pos;
	SDL_Rect frame;
}ENEMY;

void intitialiserurbach(Urbach *urbach);
SDL_Surface *urbachdirection(int xl, int xr, Urbach urbach, int l, int r);
void resetframeurbach(int xl, int xr, int *i, Urbach *urbach, int l, int r);
void intitialiserenemy(ENEMY *enemy);
SDL_Surface *enemydirection(ENEMY *enemy, SDL_Rect heropos, int m);
void drawenemy(int camlr, SDL_Rect *enemypos, int m);
void resetframenemy(int *i, ENEMY *enemy);
