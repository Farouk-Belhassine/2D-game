#include "structs.h"

  /* Prototypes des fonctions utilisées */

 extern  void init(char * , Gestion * jeu);
  extern void initializeEnnemy(Monstre *monstre) ; 
  extern void drawanimatedEnnemy(Monstre *monstre , hero he , Gestion * jeu);
  extern void cleanup(void);
  extern Input  getInput(Input input);
  extern void  draw_object (Gestion * jeu,  object o[5] );
 extern SDL_Surface* drawImage(SDL_Surface *image,SDL_Surface *screen, int x, int y ) ;
   extern SDL_Surface* menu_principale(SDL_Surface*, int *menuout);
  extern void delay(unsigned int);
 extern void drawanimatedplayer(hero* he , Gestion * jeu);
 extern void loadGame(Gestion * jeu);
extern void initializehero(hero *he);
extern void reset(hero *he ,Monstre *monstre , vie v[4] , object o[5]) ;
extern void initialiservie(vie v[]);
extern SDL_Surface*  draw_vie (SDL_Surface* screen,  vie v[4] , int hvie );
extern Mix_Music* loadSound_infini(char *name);
extern void initialiserobject(object o[]);
// extern void drawgame( );
extern void dohero( hero *he , Input input,Gestion * jeu );
extern void dovie(hero *he, object o[5],vie v[4],SDL_Rect camera,Monstre monstre);
//extern void dotime(hero *he);
//extern void doscore(hero *he,coin *cn);
extern void playSound_infini(Mix_Music* sfx);
extern void drawhero(hero * he , Gestion *jeu);
extern void init_enigme(Enigme * e);
extern void generate_afficher (SDL_Surface * screen  , char image [],Enigme *e,int *alea);
extern int solution_e (char image []);
extern int resolution (int * go ,int * run );
extern void afficher_resultat (SDL_Surface * screen,int s,int r,Enigme *en);
extern int Collision_bounding_box2(hero *o1, Monstre monstre ,SDL_Rect camera);
extern void loadpartage(partage* jeu );
extern void drawpartage(partage * p , Gestion * jeu  );
extern void dohero1( hero *he , Input input, Gestion *jeu , partage *  p );
extern void initializehero2(hero *he) ;
extern void dohero2( hero *he , Input input, Gestion *jeu , partage *  p );
extern void crono(Gestion *s);
extern SDL_Surface* menu_2(SDL_Surface* screen , int *menuout , hero * he  , Monstre *monstre);
