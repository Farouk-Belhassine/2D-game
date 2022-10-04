#include "defs.h"
typedef struct Enigme
{

    SDL_Surface *img;
    SDL_Rect p;
     

} Enigme;
typedef struct Input
{

    int left, right, up, down, jump, attack, enter, erase, pause;

} Input;
typedef struct Monstre
   {
       
       SDL_Surface *sprite;
       int x, y;
       int frameNumber, frameTimer;
       int direction ;

   } Monstre;
typedef struct Gestion
{

    SDL_Surface *screen;
    SDL_Surface *background;
    SDL_Rect camera ; 
    SDL_Rect pos_background ; 
    int dt  ;
    int menuout;
    int on ;

} Gestion;

typedef struct menu
{

    SDL_Surface *background;
    SDL_Surface *rectangle;
    TTF_Font *police1 ;
    TTF_Font *police2 ;
    SDL_Surface *texte[7];
    SDL_Color noir ;
    SDL_Color blanc ;
    SDL_Rect pos_rectangle;
    int menuout ;
    Mix_Chunk * click_sound ;
    Mix_Music* soundtrack ;
} Menu;

typedef struct vie
{
      SDL_Surface *img ;
      int x,y;

}vie;

typedef struct hero
{

    SDL_Surface *sprite;
    int frameNumber, frameTimer;
    int d,x,y;
    float v,a;
   
    int hvie;
    
   
} hero;


typedef struct object
{
      SDL_Surface *imo;
      int x,y,ED;
}object;

typedef struct partage
{
    SDL_Surface *background;
     SDL_Rect pos1 ;
    SDL_Rect pos2 ; 
    SDL_Rect camera1 , camera2 ; 
 
   
} partage;


