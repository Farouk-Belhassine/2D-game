#include "main.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    Input input;
    Monstre monstre;
    Enigme enigme ; 
    Mix_Music* soundtrack ;
int go = 1 ;
Uint32 t_prev=0 ; 
int alea = 0 ;
char image[50];
int solution=0;
int r=0;
int run = 1 ;
    Gestion jeu;    
    loadGame(&jeu); 
    hero he ;
    vie v[4];
    object o[5];
    init("GREY MATTER",&jeu);
    
    atexit(cleanup);
    jeu.screen= menu_principale(jeu.screen,&jeu.menuout);
     Mix_CloseAudio();
     init("GREY MATTER",&jeu);
     soundtrack = loadSound_infini("graphics/xxx.mp3") ;
      if (jeu.menuout==0) {
      initializehero(&he);
      initializeEnnemy(&monstre);
      initialiservie(v);
      initialiserobject(o);
     playSound_infini(soundtrack);
     
       while (jeu.menuout==0)
        {  if ( he.hvie == 0 ){ jeu.screen= menu_2(jeu.screen,&jeu.menuout,&he ,&monstre);
monstre.x=500;
he.x=50;
he.hvie=3;}
t_prev=SDL_GetTicks();
    input=getInput(input); 
    if (input.attack == 1 )crono(&jeu) ;
    drawhero(&he,&jeu);  
    dohero(&he,input,&jeu);   
    drawanimatedplayer(&he,&jeu);
     if (jeu.camera.x<=3500)  drawanimatedEnnemy(&monstre ,he ,&jeu);      
    jeu.screen=draw_vie (jeu.screen,v,he.hvie);
    dovie(&he, o,v,jeu.camera,monstre);
    
    draw_object (&jeu,o);
    if ( Collision_bounding_box2(&he,monstre,jeu.camera) == 1)  
    {
           if (monstre.x >= he.x )   monstre.x+=80 ; 
           else monstre.x-=80;
}    jeu.dt=SDL_GetTicks()-t_prev;   
    delay(frameLimit);
    SDL_Flip(jeu.screen);
    frameLimit = SDL_GetTicks() + 16;
    if (jeu.camera.x>=4000) jeu.menuout=1;
       drawanimatedplayer(&he,&jeu);
       
} 
reset(&he,&monstre,v,o);
SDL_FreeSurface(jeu.background);
SDL_FreeSurface(jeu.screen);
init("GREY MATTER",&jeu);
while(go == 1) 
{
run=1;
init_enigme(&enigme);
generate_afficher(jeu.screen,image,&enigme,&alea);
while(run==1){r=resolution(&go,&run);}

solution=solution_e(image);
afficher_resultat (jeu.screen,solution,r,&enigme); 
SDL_Delay(500);
  
} } 
else if (jeu.menuout== 2 )
{
 hero   he2 ; 
 partage p ;  
 initializehero(&he);
 initializehero2(&he2);
 loadpartage(&p);
  while (jeu.menuout == 2 ) 
     { input=getInput(input);
       drawpartage(&p,&jeu);
       drawhero(&he,&jeu);  
       dohero1(&he ,input, &jeu ,&p ); 
       drawanimatedplayer(&he,&jeu);
       drawhero(&he2,&jeu);  
       dohero2(&he2 ,input , &jeu ,&p ); 
       drawanimatedplayer(&he2,&jeu);
      }
}

/* Exit */
exit(0);

}

