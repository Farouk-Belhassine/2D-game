#ifndef HEADER2_H_INCLUDED
#define HEADER2_H_INCLUDED

#define FPS 60
#define ENNEMY_WIDTH 80
#define ENNEMY_HEIGHT 80
#define TIME_BETWEEN_2_FRAMES 4

typedef struct
{
SDL_Rect positionObjet;
}objet;

typedef struct{
objet o;
float val;
}vie;
typedef struct
{int id;
 SDL_Rect position;
 SDL_Surface *sprite;
 vie v; 
 int score;
float  vitesse;
float acceleration;
int direction;
}Hero;
typedef struct ENNEMY
   {
       
       SDL_Surface *sprite1 , * sprite2 , *sprite , *attleft , *attright;
       int x, y;
       int frameNumber, frameTimer;
       int direction ;
       int limite;

   } ENNEMY;
	

typedef struct 
{
SDL_Surface *mask;
SDL_Surface *background;
SDL_Surface *ecran;
SDL_Rect pos;
int dt;
int on ;
}stage;

//int Collission(SDL_Rect a,SDL_Rect b); FUCKING WORTHLESS
int Collision(SDL_Rect box1,SDL_Rect box2);
void anim_perso(int *i, SDL_Event *event,personnage *p);
int collision_parfaite(SDL_Surface *bg,SDL_Rect r);
SDL_Color GetPixel(SDL_Surface *bg,SDL_Rect r);
int Collission(SDL_Rect a,SDL_Rect b);
//MENU
int menu1();
int menu2(SDL_Surface *screen);
void menu3(SDL_Surface *screen,int *config,int *music);
void menu4(SDL_Surface *screen);
//TINY ITTY-BITTY MENUS
int sous_menu1(SDL_Surface *fenetre,SDL_Event *event);
//afficher
void afficher_background(SDL_Surface *bg,SDL_Rect *pos,SDL_Surface *screen);
objet init (objet obj,int x1,int y1,int w1,int h1); 
void charger_image(char image[],SDL_Surface *screen,SDL_Surface *sprite,SDL_Rect *positionsprite);
void afficher_personnage(personnage p,char image[],SDL_Surface *screen);
void afficher_objet(objet obj,char lien[],SDL_Surface *screen);

void afficher_vie(vie v,SDL_Surface *screen);
//initialiser
void initialiser_personnage(personnage *p);
SDL_Surface *initialiser_stage(stage *s,char x[]);
//scrolling et deplacement 
 
void Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s);
unsigned int crono(stage *s,unsigned int start_game);
//charger background ... 
//void loadGame(void);
//quitter SDL ...
//void cleanup();
//les entrees 
//void getInput() ;
//initialiser ennemi
void initializeEnnemy(void);
//afficher ennemi
void drawEnnemy();
//charger + afficher une image
SDL_Surface *loadImage(char *name);
void drawImage(SDL_Surface *image, int x, int y);
void sautetdepla(personnage *p,SDL_Event *event,int *continuer);
//limiter le prog a 60 images par seconde !! importante !!
void delay(unsigned int frameLimit);
// fonctions temporaires pour l'hero !! a changer
//void initializehero(void);
//void drawhero();
//void dohero();
//fonction principale de l'ennemi
void drawanimatedEnnemy();
//enigme
void solution(SDL_Surface *ecran,int d);

void quiz(SDL_Surface *ecran,int d);

void good(SDL_Surface *ecran);

void reponse(SDL_Surface *ecran,int d);
void generatequiz();
int fin_jeu(unsigned int time);
// entite secondaire
//void initentity();
//void doEntity();
Mix_Music *musique;
personnage p;
ENNEMY monstre;
//ENTITY entity ;
stage s;

#endif // HEADER2_H_INCLUDED
