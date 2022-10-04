#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "characters.h"
#include "collision.h"

void intitialiserurbach(Urbach *urbach)
{
	(*urbach).idleleft = IMG_Load("global/characters/urbach/idleleft.png");
	(*urbach).idleright = IMG_Load("global/characters/urbach/idleright.png");	
	(*urbach).left = IMG_Load("global/characters/urbach/urbachleft.png");
	(*urbach).right = IMG_Load("global/characters/urbach/urbachright.png");
	(*urbach).pos.x=339;
	(*urbach).pos.y=521;
	(*urbach).frame.x=0;
	(*urbach).frame.y=0;
	(*urbach).frame.w=74;
	(*urbach).frame.h=130;
}

SDL_Surface *urbachdirection(int xl, int xr, Urbach urbach, int l, int r)
{
	SDL_Surface *hero;

	if(xl==1) hero=urbach.left;
	if(xr==1) hero=urbach.right;
	if(l==1) hero=urbach.idleleft;
	if(r==1) hero=urbach.idleright;

	return hero;
}

void resetframeurbach(int xl, int xr, int *i, Urbach *urbach, int l, int r)
{
	if(xl==1){
		if(*i==-1||*i>=4) *i=3;
		(*urbach).frame.x=(*i)*(*urbach).frame.w;
		(*i)--;
		SDL_Delay(64);
	}
	if(xr==1){
		if(*i>=4||*i<=-1) *i=0;
		(*urbach).frame.x=(*i)*(*urbach).frame.w;
		(*i)++;
		SDL_Delay(64);
	}
	if(l==1){
		if(*i==7||*i==-1) *i=6;
		(*urbach).frame.x=(*i)*(*urbach).frame.w;
		(*i)--;
		SDL_Delay(64);
	}
	if(r==1){
		if(*i==7||*i==-1) *i=0;
		(*urbach).frame.x=(*i)*(*urbach).frame.w;
		(*i)++;
		SDL_Delay(64);
	}
}

void intitialiserenemy(ENEMY *enemy)
{	
	(*enemy).runleft = IMG_Load("global/characters/enemy/runleft.png");
	(*enemy).runright = IMG_Load("global/characters/enemy/runright.png");
	(*enemy).attackleft = IMG_Load("global/characters/enemy/attackleft.png");
	(*enemy).attackright = IMG_Load("global/characters/enemy/attackright.png");
	(*enemy).pos.x=900;
	(*enemy).pos.y=540;
	(*enemy).frame.x=0;
	(*enemy).frame.y=0;
	(*enemy).frame.w=130;
	(*enemy).frame.h=130;
}

SDL_Surface *enemydirection(ENEMY *enemy, SDL_Rect heropos, int m)
{
	SDL_Surface *surf;

	if((*enemy).pos.x<heropos.x&&col((*enemy).pos,heropos)==0){
		surf=(*enemy).runright;
		(*enemy).pos.x+=m;
	}
	if((*enemy).pos.x>heropos.x&&col((*enemy).pos,heropos)==0){
		surf=(*enemy).runleft;
		(*enemy).pos.x-=m;
	}
	if(col((*enemy).pos,heropos)&&(*enemy).pos.x>heropos.x) surf=(*enemy).attackleft;
	if(col((*enemy).pos,heropos)&&(*enemy).pos.x<heropos.x) surf=(*enemy).attackright;

	return surf;
}

void drawenemy(int camlr, SDL_Rect *enemypos, int m)
{
	if(camlr==1) (*enemypos).x+=m;
	if(camlr==-1) (*enemypos).x-=m;
}

void resetframenemy(int *i, ENEMY *enemy)
{
	if(*i==7||*i==-1) *i=6;
	(*enemy).frame.x=(*i)*(*enemy).frame.w;
	(*i)--;
}
