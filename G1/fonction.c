#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
int fin_jeu(unsigned int time){
int cn=1;
SDL_Event event;
SDL_Surface *texte=NULL,*sprite1=NULL,*sprite2=NULL;
TTF_Font *police = NULL;
SDL_Color couleur = {255,255, 255};
SDL_Rect textposition,positionsprite2,positionsprite1;
//position sprite& texte 
textposition.x=230;
textposition.y=210;
positionsprite1.x=230;
positionsprite1.y=290;
positionsprite1.w =128;
positionsprite1.h =26;
positionsprite2.x=230;
positionsprite2.y=340;
positionsprite2.w =128;
positionsprite2.h =26;
objet game_over;
char score[20];
char timech[20];
game_over=init(game_over,0,0,0,0);
afficher_objet(game_over,"gameover1.png",s.ecran);
police = TTF_OpenFont("GODOFWAR.TTF",20);
sprintf(score, "score : %d",p.score);
sprintf(timech,"time: %d Sec",time);
texte = TTF_RenderText_Blended(police,score, couleur);
SDL_BlitSurface(texte, NULL,s.ecran, &textposition); /* Blit du texte */
SDL_Flip(s.ecran);
texte = TTF_RenderText_Blended(police,timech, couleur);
textposition.x=230;
textposition.y=250;
SDL_BlitSurface(texte, NULL,s.ecran, &textposition); /* Blit du texte */
charger_image("play.png",s.ecran,sprite1,&positionsprite1);
charger_image("quit.png",s.ecran,sprite2,&positionsprite2);
int mouse=0,keyboard=0;
while(cn){
SDL_WaitEvent(&event);
switch(event.type)
        { 
   case SDL_QUIT: cn=0; break ;
   case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
             {case SDLK_UP:
              keyboard--;
              break;
              case SDLK_DOWN:  
              keyboard++;
              break;
              case SDLK_RETURN: 
              if(keyboard==2){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
cn = 0;return -1;} 
              if(keyboard==1){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
return 1;}
              break;
              }}
if(keyboard==1){charger_image("play2.png",s.ecran,sprite1,&positionsprite1);
}else {charger_image("play.png",s.ecran,sprite1,&positionsprite1);}
if(keyboard==2){charger_image("quit2.png",s.ecran,sprite2,&positionsprite2);}else {charger_image("quit.png",s.ecran,sprite2,&positionsprite2);}
if(keyboard<1){keyboard=2; 
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);}
if(keyboard>2){keyboard=1;
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
}
} 
TTF_Quit();
SDL_FreeSurface(texte);

}
void solution(SDL_Surface *ecran,int d)
{
    char im[100];
    SDL_Surface *image1 = NULL;
    SDL_Rect positionFond1;
    positionFond1.x =  0 ;
    positionFond1.y =  0 ;
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    image1= IMG_Load("no.png");
    SDL_BlitSurface(image1,NULL,ecran,&positionFond1);
    SDL_Flip(ecran);
    SDL_Delay(3000);
    sprintf(im,"solu/%d.png",d);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

void good(SDL_Surface *ecran)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"goood.png");
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

void quiz(SDL_Surface *ecran,int d)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"quiz2/%d.png",d);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}


void reponse(SDL_Surface *ecran,int d)
{
    SDL_Event event;
    char im[100], im1[100], im2[100], im3[100];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect positionim;
    positionim.x =  0 ;
    positionim.y =  0 ;
    sprintf(im,"reponse/%d.png",d);
    image= IMG_Load(im);
    sprintf(im1,"reponse/%d/1.png",d);
    sprintf(im2,"reponse/%d/2.png",d);
    sprintf(im3,"reponse/%d/3.png",d);
    image1= IMG_Load(im1);
    image2= IMG_Load(im2);
    image3= IMG_Load(im3);
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_Flip(ecran);
    int continuer =1;
    int i=0;



    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==1 && d%3==1)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==2 && d%3==2)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==3 && d%3==0)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else
                    {
                        solution(ecran,d);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=3;
                }
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                break;
            }
        }
        //SDL_BlitSurface(image,NULL,ecran,&positionim);
        SDL_Flip(ecran);
    }


}
void generatequiz(){
int d=1;
srand(time(NULL));   
d=rand()%13; 
TTF_Init();
if(TTF_Init()==-1)
{fprintf(stderr,"ERREUR INIT: %s \n",TTF_GetError());
exit(EXIT_FAILURE);}
SDL_Color couleurnoir={0,0,0};
SDL_Surface *texte = NULL, *backg=NULL ; //declaration des variables globale 
SDL_Rect positiontexte,positiond;
positiontexte.x=100;
positiontexte.y=160;
TTF_Font *police;//(pointeur contient parametre de la police) 
SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
police=TTF_OpenFont("font.ttf",50);
backg = IMG_Load("quiz.png");
positiond.x=0 ; 
positiond.y=0 ; 
SDL_BlitSurface(backg,NULL,s.ecran, &positiond);
SDL_Flip(s.ecran);
texte=TTF_RenderText_Blended(police,"enigme ",couleurnoir);
SDL_BlitSurface(texte,NULL,s.ecran,&positiontexte);
SDL_Flip(s.ecran);
SDL_Delay(150);
quiz(s.ecran,d);
SDL_BlitSurface(backg,NULL,s.ecran, &positiond);
SDL_Flip(s.ecran);
reponse(s.ecran,d);
SDL_FreeSurface(backg);
TTF_CloseFont(police);
TTF_Quit();
SDL_Quit();
}
unsigned int crono(stage *s,unsigned int start_game){
char temps[20]={0};
TTF_Font *police = NULL;
SDL_Color couleurNoire = {0,0,0};
SDL_Surface *texte = NULL;
SDL_Rect textposition;
textposition.x=400;
textposition.y=20;
police = TTF_OpenFont("GODOFWAR.TTF",20);
unsigned int currentTime=SDL_GetTicks();
currentTime=(currentTime/1000)-(start_game/1000);
sprintf(temps,"time : %d Sec",currentTime); 
texte = TTF_RenderText_Blended(police,temps,couleurNoire);
SDL_BlitSurface(texte, NULL,s->ecran, &textposition);
return currentTime; 
}

void initialiser_personnage(personnage *p)
{
  p->position.x=20;
  p->position.y=220;
p->position.w=75;
p->position.h=80;  
p->v.val=100;
p->direction=1;
  p->acceleration=0;
  p->vitesse=0;
  p->score=20;
p->id=1;
p->v.o=init(p->v.o,25,25,83,18);

}

void sautetdepla(personnage *p,SDL_Event *event,int *continuer)
{     
    while (SDL_PollEvent(event))
    {
        switch(event->type)
        {
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
            {
            case SDLK_b:
                p->position.y-=p->vitesse*5;
                p->position.x+=p->vitesse*3;
                break;
            case SDLK_v:
                p->position.y-=p->vitesse*5;
                p->position.x-=p->vitesse*3;
                break;
            case SDLK_UP:
                p->position.y-=20*5;
                break;
            }
            break;
        case SDL_KEYUP:
            switch(event->key.keysym.sym)
            {
            case SDLK_b:
                p->position.y+=p->vitesse*5;
                p->position.x+=p->vitesse*3;
                break;
            case SDLK_v:
                p->position.y+=p->vitesse*5;
                p->position.x-=p->vitesse*3;
                break;
            case SDLK_UP:
                p->position.y+=20*5;
                break;
         
            }
            break;
        }
    }


    switch(event->type)
    {
    case SDL_QUIT:
        (*continuer) = 0;
        break;
    case SDL_KEYDOWN:
        switch(event->key.keysym.sym)
        {
        case SDLK_LEFT:
           p->acceleration+=0.00005;
            p->vitesse=0.2;
p->direction=-1;
s.on=0;
            break;
        case SDLK_RIGHT:
            p->acceleration+=0.00005;
            p->vitesse=0.2;
            p->direction=1;
            s.on=0;
            break;
        }
        break;
    case SDL_KEYUP:
            s.on=0;
            p->direction=0;
            break;
    }
if(p->direction==1)
{
if((p->position.x>=250)&&(s.pos.x<=(4730-558)))
            {
                s.pos.x+= 0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt;
                s.on = 1 ; 
               // monstre.x+=( 0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt) ;
               // p->position.x-=20;
               // p->v.o.positionObjet.x+=0.1;
            }
            else
            {    s.on = 0 ;
                p->position.x +=0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt;
                //monstre.x+=( 0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt -20) ;
            }
}

 if (p->direction==-1)
{
 if((p->position.x<=250)&&(s.pos.x>=0))
            {   s.on = -1 ;
                s.pos.x-= 0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt;
                //monstre.x+=20;
                //p->position.x+=20;
                //p->v.o.positionObjet.x-=0.1;
            }
            else
            {   s.on = -1 ; 
                p->position.x-=0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt;
                // monstre.x-=( 0.5 * (s.dt * s.dt ) * p->acceleration + p->vitesse * s.dt -20) ;
            }

}

p->vitesse=0;
p->acceleration-=0.000005;
if (p->acceleration < -0.00000001)    p->acceleration =0 ;
 
}

int sous_menu(SDL_Surface *fenetre,SDL_Event *event)
{
int menu=1;
int choice=1;
SDL_Rect pos[2];
SDL_Surface *youdied=NULL;
SDL_Surface *choix[4]={NULL,NULL,NULL,NULL};
fenetre=SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
choix[0]=IMG_Load("greyedyes.png");
choix[1]=IMG_Load("greyedno.png");
choix[2]=IMG_Load("Selectedyes.png");
choix[3]=IMG_Load("Selectedno.png");
youdied=IMG_Load("Coll.png");
pos[0].x=100;
pos[0].y=400;
pos[1].x=300;
pos[1].y=400;
SDL_BlitSurface(youdied,0,fenetre,0);
SDL_BlitSurface(choix[0],NULL,fenetre,&pos[0]);
SDL_BlitSurface(choix[1],NULL,fenetre,&pos[1]);
SDL_Flip(fenetre);
while(menu){
SDL_WaitEvent(event);
switch(event->type)
{
case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
case SDLK_RIGHT : choice=2;
break;
case SDLK_LEFT : choice=1;
break;
case SDLK_RETURN : if(choice==1) 
return 1;
else return 2;
break;
}
}
if(choice==1)
{
SDL_BlitSurface(youdied,0,fenetre,0);
SDL_BlitSurface(choix[1],NULL,fenetre,&pos[1]);
SDL_BlitSurface(choix[2],NULL,fenetre,&pos[0]);
SDL_Flip(fenetre);
}
else
{
SDL_BlitSurface(youdied,0,fenetre,0);
SDL_BlitSurface(choix[0],NULL,fenetre,&pos[0]);
SDL_BlitSurface(choix[3],NULL,fenetre,&pos[1]);
SDL_Flip(fenetre);
} 

}
     
}


/*
//SAVE GAME
void SaveGame(personnage *p,enemy *e ,stage *s,FILE *f)
 {
     f=fopen("/home/hbib/Desktop/TheGameSoFar/save.txt","w");
     if (f==NULL)
     {
         printf("\nAn error has occured during your save.");
     }
     else
     {
     fprintf(f,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",s->pos_enemy_x,s->pos_enemy_y,s->pos_p_x,s->pos_p_y,s->score,s->var,s->vie,s->scrol_x,s->scrol_y,s->niv,s->direction);

    }
 fclose(f);
 }
//LOAD GAME

void LoadGame(personnage *p,enemy *e ,stage *stage1,FILE *f,save *s)
{
    f=fopen("/home/hbib/Desktop/Ga/Ga","r");
    if (f==NULL){

  printf ("erreur d'ouverture du fichier en mode r");}

fscanf(f,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n",&s->pos_enemy_x,&s->pos_enemy_y,&s->pos_p_x,&s->pos_p_y,&s->score,&s->var,&s->vie,&s->scrol_x,&s->scrol_y,&s->niv,&s->direction);
fclose(f);
    p->position.x= s->pos_p_x;
    p->position.y=s->pos_p_y;
     p->direction=s->direction;
     p->var=s->var;
     p->score=s->score;
     p->vie=s->vie;
     stage1->pos.x=s->scrol_x;
     e->p.x=s->pos_enemy_x;
     e->p.y=s->pos_enemy_y;
     stage1->pos.y=s->scrol_y;
     stage1->niv=s->niv;

}
//END LOAD.
*/

//LOWLY-COLLISION.
int Collission(SDL_Rect a,SDL_Rect b)
{
   if((a.x==b.x)&&(a.y==b.y))

          return 1;
   else
          return 0;
}

int Collision(SDL_Rect box1,SDL_Rect box2)
{
   if((box2.x >= box1.x + box1.w)|| (box2.x + box2.w <= box1.x) || (box2.y >= box1.y + box1.h) || (box2.y + box2.h <= box1.y))
          return 0;
   else
          return 1;
}

int collision_parfaite(SDL_Surface *bg,SDL_Rect r)
{
SDL_Color color;

color=GetPixel(bg,r);

if(color.r==255 && color.g==255 && color.b==255)
return 1;
else return 0;
}

SDL_Color GetPixel(SDL_Surface *bg,SDL_Rect r)
{
 SDL_Color color;
Uint32 col=0;

char* pPosition=(char*) bg->pixels;

pPosition+=(bg->pitch*r.y);
pPosition+=(bg->format->BytesPerPixel*r.x);

memcpy(&col,pPosition,bg->format->BytesPerPixel);
SDL_GetRGB(col,bg->format,&color.r,&color.g,&color.b);
return (color);
}






void anim_perso(int *i, SDL_Event *event,personnage *p){
char lien[20];
SDL_PollEvent(event);
                          switch(event->type)
                          {case SDL_KEYDOWN:
                                     switch(event->key.keysym.sym)
                                     {case SDLK_RIGHT: 
                                      (*i)++;
if(*i>4)*i=1;
                                      sprintf(lien,"%dr%d.png",p->id,*i);
SDL_Delay(150);

                                      p->sprite = IMG_Load(lien);   
                                      break;
                                      case SDLK_LEFT: (*i)++;
if(*i>4)*i=1;
                                      sprintf(lien,"%dl%d.png",p->id,*i);
SDL_Delay(150);
                                      p->sprite = IMG_Load(lien); 
                                      break;
                                      case SDLK_z: p->id=2; 
                                      sprintf(lien,"%dr%d.png",p->id,*i);
SDL_Delay(150);
                                      p->sprite = IMG_Load(lien); 
break; 

case SDLK_x: p->id=1; 
                                      sprintf(lien,"%dr%d.png",p->id,*i);
SDL_Delay(150);
                                      p->sprite = IMG_Load(lien); 
break; 
                                      }
                            break; }   
}
// initi objet 
objet init (objet obj,int x1,int y1,int w1,int h1)
{
obj.positionObjet.x=x1;
obj.positionObjet.y=y1;
obj.positionObjet.w=w1;
obj.positionObjet.h=h1;
return obj;
}

void afficher_objet(objet obj,char lien[],SDL_Surface *screen)
{
SDL_Surface *sprite=NULL;
sprite=IMG_Load(lien);
SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255,255,255));
SDL_BlitSurface(sprite,NULL,screen,&obj.positionObjet);
}
// vie 
void afficher_vie(vie v,SDL_Surface *screen)
{
if (v.val>=100) {
afficher_objet(v.o,"100.png",screen); }
else if(v.val==87.5)  {
afficher_objet(v.o,"88.png",screen); }
else if(v.val==75)  {
afficher_objet(v.o,"75.png",screen); }
else if(v.val==62.5)  {
afficher_objet(v.o,"62.png",screen); }
else if(v.val==50)  {
afficher_objet(v.o,"50.png",screen); }
else if(v.val==37.5)  {
afficher_objet(v.o,"38.png",screen); }
else if(v.val==25)  {
afficher_objet(v.o,"25.png",screen); }
else if(v.val==12.5) 
{ afficher_objet(v.o,"12.png",screen); }
else if(v.val<=0)  {
afficher_objet(v.o,"0.png",screen); }

}
//chargement image 
void charger_image(char image[],SDL_Surface *screen,SDL_Surface *sprite,SDL_Rect *positionsprite){
sprite = IMG_Load(image);
SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255,255,255));
    SDL_BlitSurface(sprite, NULL, screen, positionsprite);
SDL_Flip(screen);
}
// menu 2 (single/multi)

int menu2(SDL_Surface *screen){ SDL_Surface  
*image=NULL,*sprite1=NULL,*sprite2=NULL,*sprite3=NULL;
SDL_Rect positionecran,positionsprite1,positionsprite2,positionsprite3;

//Fond 
positionecran.x=0;
positionecran.y=0;
//single_player
positionsprite1.x=85;
positionsprite1.y=180;
positionsprite1.w=128;
positionsprite1.h=26;
//multi-player
positionsprite2.x=85;
positionsprite2.y=220;
positionsprite2.w=128;
positionsprite2.h=26;
//back
positionsprite3.x=85;
positionsprite3.y=260;
positionsprite3.w=128;
positionsprite3.h=26;
charger_image("bg.png",screen,image,&positionecran);  
charger_image("sp.png",screen,sprite1,&positionsprite1);
charger_image("mp.png",screen,sprite2,&positionsprite2);
charger_image("back.png",screen,sprite3,&positionsprite3);

int continuer = 1;
int mouse=0;
int keyboard=0;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        break ;
case SDL_MOUSEMOTION:
if((event.motion.x>positionsprite1.x)&&(event.motion.x<positionsprite1.x + positionsprite1.w)&&(event.motion.y>positionsprite1.y)&&(event.motion.y<positionsprite1.y + positionsprite1.h))
{mouse=1;
charger_image("sp2.png",screen,sprite1,&positionsprite1);
}else {charger_image("sp.png",screen,sprite1,&positionsprite1);
}
if((event.motion.x>positionsprite2.x)&&(event.motion.x<positionsprite2.x + positionsprite2.w)&&(event.motion.y>positionsprite2.y)&&(event.motion.y<positionsprite2.y + positionsprite2.h))
{mouse=2;
charger_image("mp2.png",screen,sprite2,&positionsprite2);
}else {charger_image("mp.png",screen,sprite2,&positionsprite2);
}
if((event.motion.x>positionsprite3.x)&&(event.motion.x<positionsprite3.x + positionsprite3.w)&&(event.motion.y>positionsprite3.y)&&(event.motion.y<positionsprite3.y + positionsprite3.h))
{mouse=3;
charger_image("back2.png",screen,sprite3,&positionsprite3);
}else {charger_image("back.png",screen,sprite3,&positionsprite3);
}
break; 
case SDL_MOUSEBUTTONUP:
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 3)){
continuer=0;
}

if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 1)){
return 1;
}
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 2)){
return 2;
}
break; 
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{case SDLK_UP:
              keyboard--;
              break;
case SDLK_DOWN:  keyboard++;
 break;
case SDLK_RETURN: if(keyboard==3){
continuer = 0;
}
if(keyboard==1){
return 1; 
}
if(keyboard==2){
return 2;}
break;
}
if(keyboard>3){keyboard=1;}
if(keyboard<0){keyboard=3;}
if(keyboard==1){charger_image("sp2.png",screen,sprite1,&positionsprite1);
}else {charger_image("sp.png",screen,sprite1,&positionsprite1);
}
if(keyboard==2){charger_image("mp2.png",screen,sprite2,&positionsprite2);
}else {charger_image("mp.png",screen,sprite2,&positionsprite2);
}
if(keyboard==3){charger_image("back2.png",screen,sprite3,&positionsprite3);
}else {charger_image("back.png",screen,sprite3,&positionsprite3);
}

break;
}

}
SDL_FreeSurface(image);
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
SDL_FreeSurface(sprite3);
}
void menu3(SDL_Surface *screen,int *config,int *music){ SDL_Surface  
*image=NULL,*sprite1=NULL,*sprite2=NULL,*sprite3=NULL,*sprite4=NULL;
SDL_Rect positionecran,positionsprite1,positionsprite2,positionsprite3,positionsprite4;
//Fond 
positionecran.x=0;
positionecran.y=0;
//gamepad
positionsprite1.x=85;
positionsprite1.y=180;
positionsprite1.w=128;
positionsprite1.h=26;
//keyboard
positionsprite2.x=85;
positionsprite2.y=220;
positionsprite2.w=128;
positionsprite2.h=26;
//back
positionsprite3.x=85;
positionsprite3.y=300;
positionsprite3.w=128;
positionsprite3.h=26;
//sound
positionsprite4.x=85;
positionsprite4.y=260;
positionsprite4.w=128;
positionsprite4.h=26;
charger_image("bg.png",screen,image,&positionecran);  
charger_image("gamepad.png",screen,sprite1,&positionsprite1);
charger_image("keyboard.png",screen,sprite2,&positionsprite2);
charger_image("back.png",screen,sprite3,&positionsprite3);
charger_image("sound_off.png",screen,sprite4,&positionsprite4);

int continuer = 1;
int mouse=0;
int keyboard=0;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        break ;
case SDL_MOUSEMOTION:
if((event.motion.x>positionsprite1.x)&&(event.motion.x<positionsprite1.x + positionsprite1.w)&&(event.motion.y>positionsprite1.y)&&(event.motion.y<positionsprite1.y + positionsprite1.h))
{mouse=1;
charger_image("gamepad2.png",screen,sprite1,&positionsprite1);
}else {charger_image("gamepad.png",screen,sprite1,&positionsprite1);
}
if((event.motion.x>positionsprite2.x)&&(event.motion.x<positionsprite2.x + positionsprite2.w)&&(event.motion.y>positionsprite2.y)&&(event.motion.y<positionsprite2.y + positionsprite2.h))
{mouse=2;
charger_image("keyboard2.png",screen,sprite2,&positionsprite2);
}else {charger_image("keyboard.png",screen,sprite2,&positionsprite2);
}
if((event.motion.x>positionsprite3.x)&&(event.motion.x<positionsprite3.x + positionsprite3.w)&&(event.motion.y>positionsprite3.y)&&(event.motion.y<positionsprite3.y + positionsprite3.h))
{mouse=4;
charger_image("back2.png",screen,sprite3,&positionsprite3);
}else {charger_image("back.png",screen,sprite3,&positionsprite3);
}
if((event.motion.x>positionsprite4.x)&&(event.motion.x<positionsprite4.x + positionsprite4.w)&&(event.motion.y>positionsprite4.y)&&(event.motion.y<positionsprite4.y + positionsprite4.h))
{mouse=3;
switch(*music){
case 1 : charger_image("sound_off2.png",screen,sprite4,&positionsprite4); break; 
case -1 : charger_image("sound_on2.png",screen,sprite4,&positionsprite4);
break; }
}else {
switch(*music){
case 1:charger_image("sound_off.png",screen,sprite4,&positionsprite4);
break;
case -1: charger_image("sound_on.png",screen,sprite4,&positionsprite4);
break; 
}}
break; 
case SDL_MOUSEBUTTONUP:
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 4)){
continuer=0;
}
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 3)){
*(music)=-*(music);
switch(*music){
case -1: Mix_PauseMusic();
break; 
case 1: Mix_ResumeMusic();
break; 
}
}
break; 
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{case SDLK_UP:
              keyboard--;
              break;
case SDLK_DOWN:  keyboard++;
 break;
case SDLK_RETURN: if(keyboard==4){
continuer = 0;
}
if(keyboard==3){
*(music)=-*(music);
switch(*music){
case -1: Mix_PauseMusic();
break; 
case 1: Mix_ResumeMusic();
break; 
}
}

if(keyboard==1){*config=1;}
if(keyboard==2){*config=2;}
break;  }
if(keyboard>4){keyboard=1;}
if(keyboard<0){keyboard=4;}
if(keyboard==1){charger_image("gamepad2.png",screen,sprite1,&positionsprite1);
}else {charger_image("gamepad.png",screen,sprite1,&positionsprite1);
}

if(keyboard==2){
charger_image("keyboard2.png",screen,sprite2,&positionsprite2);
}else {charger_image("keyboard.png",screen,sprite2,&positionsprite2);
}

if(keyboard==3){
switch(*music){
case 1 : charger_image("sound_off2.png",screen,sprite4,&positionsprite4); break; 
case -1 : charger_image("sound_on2.png",screen,sprite4,&positionsprite4);
break; }
}else {
switch(*music){
case 1:charger_image("sound_off.png",screen,sprite4,&positionsprite4);
break;
case -1: charger_image("sound_on.png",screen,sprite4,&positionsprite4);
break; 
}
}
if(keyboard==4){
charger_image("back2.png",screen,sprite3,&positionsprite3);
}else {charger_image("back.png",screen,sprite3,&positionsprite3);
}

break;
}

}
SDL_FreeSurface(image);
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
SDL_FreeSurface(sprite3);
SDL_FreeSurface(sprite4);
}
void menu4(SDL_Surface *screen){ SDL_Surface  
*image=NULL,*sprite=NULL;
SDL_Rect positionecran,positionsprite;
    SDL_Event event;
  int continuer = 1;
 //Fond
    positionecran.x = 0;
    positionecran.y = 0;
//back
positionsprite.x=85;
positionsprite.y=380;
positionsprite.w=128;
positionsprite.h=26;
int mouse=0;
int keyboard=0;
charger_image("bg_credits1.png",screen,image,&positionecran); 
charger_image("back.png",screen,sprite,&positionsprite); 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        break ;
case SDL_MOUSEMOTION:
if((event.motion.x>positionsprite.x)&&(event.motion.x<positionsprite.x + positionsprite.w)&&(event.motion.y>positionsprite.y)&&(event.motion.y<positionsprite.y + positionsprite.h))
{mouse=1;
charger_image("back2.png",screen,sprite,&positionsprite);
}else {charger_image("back.png",screen,sprite,&positionsprite);
}break; 
case SDL_MOUSEBUTTONUP:
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 1)){
                continuer = 0;
}
break; 
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{case SDLK_UP:
              keyboard--;
              break;
case SDLK_DOWN:  keyboard++;
 break;
case SDLK_RETURN: if(keyboard==1){
continuer = 0;

}
break;  }
if(keyboard>1){keyboard=0;}
if(keyboard<0){keyboard=1;}
if(keyboard==1){charger_image("back2.png",screen,sprite,&positionsprite);
}else {charger_image("back.png",screen,sprite,&positionsprite);
}
break;
}

}
charger_image("bg.png",screen,image,&positionecran);
SDL_FreeSurface(image);
SDL_FreeSurface(sprite);
SDL_QUIT;
}

int menu1(){

    SDL_Surface *screen = NULL, *sprite = NULL, *sprite1 = NULL , *sprite2 = NULL , *ecran = NULL , *image = NULL ,*sprite3 = NULL , *sprite4=NULL;
    SDL_Rect positionecran,positionsprite,positionsprite1,positionsprite2,positionsprite3,positionsprite4;
int mouse;
int keyboard=0;
int choix=0;
 //Fond
    positionecran.x = 0;
    positionecran.y = 0;
//PLAY
    positionsprite.x = 85;
    positionsprite.y = 180;
positionsprite.w = 128;
 positionsprite.h = 26;
//options
    positionsprite1.x = 85;
    positionsprite1.y = 220;
positionsprite1.w = 128;
positionsprite1.h = 26;
//Credits
positionsprite3.x = 85;
    positionsprite3.y = 260;
positionsprite3.w = 128;
positionsprite3.h =26;
//STORY
positionsprite4.x = 85;
    positionsprite4.y = 300;
positionsprite4.w = 128;
positionsprite4.h =26;
//QUIT
positionsprite2.x = 85;
    positionsprite2.y = 340;
positionsprite2.w = 128;
positionsprite2.h =26;


    SDL_Init(SDL_INIT_VIDEO);

screen = SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("Torn Asunder", NULL);
charger_image("bg.png",screen,image,&positionecran);
charger_image("play.png",screen,sprite,&positionsprite);
charger_image("options.png",screen,sprite1,&positionsprite1);
charger_image("quit.png",screen,sprite2,&positionsprite2);
charger_image("credits.png",screen,sprite3,&positionsprite3);
charger_image("story.png",screen,sprite4,&positionsprite4);
/*if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           {
           printf("%s",Mix_GetError());
           }
           musique=Mix_LoadMUS("music.ogg");
           Mix_PlayMusic(musique, -1); */

  int continuer = 1;
//keyboard=1 or joystick=2 
int config=1;
//etat music on=1 off=-1
int music_on_off=1;
//game start 
int start_game=0;

    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        break ;
case SDL_MOUSEMOTION:
if((event.motion.x>positionsprite.x)&&(event.motion.x<positionsprite.x + positionsprite.w)&&(event.motion.y>positionsprite.y)&&(event.motion.y<positionsprite.y + positionsprite.h))
{mouse=1;
charger_image("play2.png",screen,sprite,&positionsprite);
}else {charger_image("play.png",screen,sprite,&positionsprite);
}
if((event.motion.x>positionsprite1.x)&&(event.motion.x<positionsprite1.x + positionsprite1.w)&&(event.motion.y>positionsprite1.y)&&(event.motion.y<positionsprite1.y + positionsprite1.h))
{mouse=2;
charger_image("option2.png",screen,sprite1,&positionsprite1);

}else {charger_image("options.png",screen,sprite1,&positionsprite1);
}

if((event.motion.x>positionsprite2.x)&&(event.motion.x<positionsprite2.x + positionsprite2.w)&&(event.motion.y>positionsprite2.y)&&(event.motion.y<positionsprite2.y + positionsprite2.h)){
mouse=3;
charger_image("quit3.png",screen,sprite2,&positionsprite2);

}else{
charger_image("quit.png",screen,sprite2,&positionsprite2);
}
if((event.motion.x>positionsprite3.x)&&(event.motion.x<positionsprite3.x + positionsprite3.w)&&(event.motion.y>positionsprite3.y)&&(event.motion.y<positionsprite3.y + positionsprite3.h))
{mouse=4;
charger_image("credits2.png",screen,sprite3,&positionsprite3);


}else{
charger_image("credits.png",screen,sprite3,&positionsprite3);
}
if((event.motion.x>positionsprite4.x)&&(event.motion.x<positionsprite4.x + positionsprite4.w)&&(event.motion.y>positionsprite4.y)&&(event.motion.y<positionsprite4.y + positionsprite4.h)){
mouse=5;
charger_image("story2.png",screen,sprite4,&positionsprite4);

}else{
charger_image("story.png",screen,sprite4,&positionsprite4);
}
break ;
case SDL_MOUSEBUTTONUP:
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 1))
{start_game=menu2(screen);
if(start_game==1||start_game==2){
continuer=0;
}
}
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 2))
{menu3(screen,&config,&music_on_off);
}
if((event.button.button == SDL_BUTTON_LEFT) && (mouse == 3))
{
continuer = 0;
break ;
}
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 4))
{menu4(screen);
}
break ;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{case SDLK_UP:
              keyboard--;
              break;
case SDLK_DOWN:  keyboard++;
 break;
case SDLK_RETURN: if(keyboard==5){
continuer = 0;
}
if(keyboard==1){
start_game=menu2(screen);
if(start_game==1||start_game==2){
continuer=0;
}
}
if(keyboard==2){
menu3(screen,&config,&music_on_off);
}
if(keyboard==3){
menu4(screen);
}
break;
}
if(keyboard>5){keyboard=1;}
if(keyboard<0){keyboard=5;}
if(keyboard==1){charger_image("play2.png",screen,sprite,&positionsprite);
}else {
charger_image("play.png",screen,sprite,&positionsprite);
}
if(keyboard==2){charger_image("option2.png",screen,sprite1,&positionsprite1);}else {
charger_image("options.png",screen,sprite1,&positionsprite1);}
if(keyboard==3){
charger_image("credits2.png",screen,sprite3,&positionsprite3);
}else{charger_image("credits.png",screen,sprite3,&positionsprite3);
}
if(keyboard==4){charger_image("story2.png",screen,sprite4,&positionsprite4);
}else{charger_image("story.png",screen,sprite4,&positionsprite4);
}
if(keyboard==5){charger_image("quit3.png",screen,sprite2,&positionsprite2);
}else{charger_image("quit.png",screen,sprite2,&positionsprite2);
}
break; 
}}
SDL_FreeSurface(image);
SDL_FreeSurface(screen);
SDL_FreeSurface(sprite);
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
SDL_FreeSurface(sprite3);
SDL_FreeSurface(sprite4);
Mix_FreeMusic(musique);
SDL_Quit();
return start_game;
}





SDL_Surface *initialiser_stage(stage *s,char chaine[])
{
  s->pos.x=0;
  s->pos.y=0;
  s->pos.w=s->background->w=4730;
  s->pos.h=s->background->h=430;
  s->on=0;
SDL_Surface *tmp=NULL,*image=NULL;
    tmp=IMG_Load(chaine);
    //SDL_SetColorKey(tmp,SDL_SRCCOLORKEY,SDL_MapRGB(tmp->format,255,255,255));
    image=SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    tmp=NULL;
    return image;
 
}




void afficher_background(SDL_Surface *bg,SDL_Rect *pos,SDL_Surface *screen)
{
SDL_BlitSurface(bg,pos,screen,NULL);
}



void initializeEnnemy(void)
   {

       /* Charge le sprite de notre héros */
        monstre.sprite = loadImage("graphics/walkright.png");
       monstre.sprite1 = loadImage("graphics/walkright.png");
       monstre.sprite2 = loadImage("graphics/walkleft.png");
       monstre.attright = loadImage("graphics/attackright.png");
       monstre.attleft = loadImage("graphics/attackleft.png");
      /* Coordonnées de démarrage de notre héros */
       monstre.x = 280;
       monstre.y = 220;
       monstre.direction=1;
       monstre.limite=0;

   }

 void drawEnnemy()
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = monstre.x;
    dest.y = monstre.y;
    dest.w = ENNEMY_WIDTH;
    dest.h = ENNEMY_HEIGHT;

    /* Rectangle source à blitter */
    SDL_Rect src;


    //Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
    //la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
    src.x = monstre.frameNumber * ENNEMY_WIDTH;
    src.y = 0;
    src.w = ENNEMY_WIDTH;
    src.h = ENNEMY_HEIGHT;

    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(monstre.sprite, &src, s.ecran, &dest);

}


   void drawImage(SDL_Surface *image, int x, int y)
  {
       SDL_Rect dest;

       /* Règle le rectangle à blitter selon la taille de l'image source */

       dest.x = x;
       dest.y = y;
       dest.w = image->w;
       dest.h = image->h;

       /* Blitte l'image entière sur l'écran aux coordonnées x et y */

       SDL_BlitSurface(image, NULL, s.ecran, &dest);
   }

   SDL_Surface *loadImage(char *name)
   {
       /* Charge une image temporaire avec SDL Image */

       SDL_Surface *temp = IMG_Load(name);
       

       /* Si elle n'est pas chargée on quitte avec une erreur */
      if (temp == NULL)
      {
           printf("Failed to load image %s\n", name);

          return NULL;
       }

       /* Ajoute la transparence à l'image temporaire en accord avec les defines TRANS_R, G, B */

       SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, 255, 255, 255)); 


       
       return temp;


   }



  
void drawanimatedEnnemy()
{
    
    /* Gestion du timer */
    
    // Si notre timer (un compte à rebours en fait) arrive à zéro


    if (monstre.frameTimer <= 0)
    {
        //On le réinitialise

        if (s.on == 0 ) monstre.frameTimer = TIME_BETWEEN_2_FRAMES;
        else monstre.frameTimer= 0 ;

        //Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante

        monstre.frameNumber++;
      
               if (monstre.x < p.position.x)
		{
			if (  ( (monstre.x-p.position.x)  > -80)&& (s.on==0)  ) {  monstre.sprite = monstre.attright ; }
                        if (   (monstre.x-p.position.x)  < -80) { 
                        monstre.sprite = monstre.sprite1 ;}
 
		}
		
		if (monstre.x  >= p.position.x)
		{
			if ( ( (monstre.x-p.position.x)  < 80) && (s.on==0)  ) monstre.sprite = monstre.attleft ; 
                       if (   (monstre.x-p.position.x)  > 80)  
                        monstre.sprite = monstre.sprite2 ;
		}
   
     if( (s.on==0) &&(monstre.x-p.position.x > 80 ) ) monstre.x-=  5 ;
     if( (s.on==0) &&(monstre.x-p.position.x < 80 ) ) monstre.x+=  5 ;    
      if( (s.on==1) &&(monstre.x-p.position.x > 80 ) ) monstre.x+=  10 ;
     if( (s.on==1) &&(monstre.x-p.position.x < 80 ) ) monstre.x-=  10 ;  
 if( (s.on==-1) &&(monstre.x-p.position.x > 80 ) ) monstre.x-=  10 ;
     if( (s.on==-1) &&(monstre.x-p.position.x < 80 ) ) monstre.x+=  10 ;   
     //printf("%d\n",s.on) ;   
		
	
		
		
        //Mais si on dépasse la frame max, il faut revenir à la première
        //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
        //par la longueur de notre héros : 480 / 40 = 12 frames
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11

        if(monstre.frameNumber >= monstre.sprite->w / ENNEMY_WIDTH)
            monstre.frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
        monstre.frameTimer--;

         //}
    //Ensuite, on peut passer la main à notre fonction
    drawEnnemy();


}


