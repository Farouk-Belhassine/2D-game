#include "structs.h"
extern void initmenu( Menu *menu);
extern void loadMenu(Menu *menu);
extern SDL_Surface* drawImage(SDL_Surface *image,SDL_Surface *screen, int x, int y) ;
extern SDL_Surface* draw_menu (Menu menu , SDL_Surface* screen ) ;
extern SDL_Surface* draw_menu2 (Menu menu , SDL_Surface* screen ) ;
extern void cleanup_menu(Menu *menu );
extern Mix_Music* loadSound_infini(char *name);
extern  Mix_Chunk * loadSound(char *name);
extern void playSound(Mix_Chunk * sfx);
extern void playSound_infini(Mix_Music* sfx);
extern void initializehero(hero *he);
  extern void initializeEnnemy(Monstre *monstre) ; 
   
