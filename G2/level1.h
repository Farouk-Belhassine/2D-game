#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct{
	SDL_Surface *map;
	SDL_Surface *ladder;
	SDL_Rect posmap;
}LEVEL;

void play_music_level1(Mix_Music *music);
void initlevel1(LEVEL *level);
int ingamemenu(SDL_Surface *screen, SDL_Rect camera, int iconpos, int rest, SDL_Rect enemypos, SDL_Rect heropos);
