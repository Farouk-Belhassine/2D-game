#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


typedef struct{
	SDL_Surface *background;
	SDL_Surface *m1;
	SDL_Surface *m2;
	SDL_Surface *m3;
	SDL_Surface *cursor;
	SDL_Rect pos;
	SDL_Rect cursorpos;
}Menu;

void play_music_menu(Mix_Music *music, int on);
void initmenu(Menu *menu);
void free_menu(Mix_Music *music, Mix_Chunk *cursorsound,Menu *menu);
void selection(SDL_Rect *cursorpos, int xu, int xd);
void test(SDL_Surface *ecran);
void level1(SDL_Surface *ecran, int camx, int iconpos, int rest, int enemyposx,int heroposx,int heroposy);
void settings(SDL_Surface *ecran, Menu menu, int continuer, Mix_Chunk *cursorsound, Mix_Music *music);
void sounds(Mix_Music *music);
void loadgame(SDL_Surface *ecran);
