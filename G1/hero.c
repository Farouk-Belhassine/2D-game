#include "hero.h"

void initializehero(hero *he)
{

    /* Charge le sprite de notre héros */
    he->sprite = loadImageN("graphics/wll.png");

    /* Coordonnées de démarrage de notre héros */
    he->x = 50;
    he->y = 580;
    he->d=0;
    he->frameNumber=1;
    he->a=0;
    he->v=0.5;
    he->hvie=3;


}
void initializehero2(hero *he)
{

    /* Charge le sprite de notre héros */
    he->sprite = loadImageN("graphics/wll.png");

    /* Coordonnées de démarrage de notre héros */
    he->x = 680;
    he->y = 580;
    he->d=0;
    he->a=0;
    he->v=2;
    he->frameNumber=1;
    he->hvie=3;


}
/* SDL_Surface *drawhero(hero *he,SDL_Surface *screen)
{
    
    SDL_Rect dest;

    dest.x = he->x;
    dest.y = he->y;
    dest.w = 50;
    dest.h = 60;


    

    SDL_BlitSurface(he->sprite,NULL, screen, &dest);
return screen ; 

}*/
  
void dohero( hero *he , Input input, Gestion *jeu)
{
    jeu->on=0;
    he->d=0;

  
    
        if (input.jump  == 1)
    {
                
		he->y-=2*10;
                he->x+=2*6;
    }
    if ((input.jump  == 0)&&(input.up == 0))
    {
               if ( he->y <  580 )
                 { 
		he->y+=2 *10;
                he->x+=2 *6; }
                else he->y = 580 ;
    }

    if (input.up == 1)
    {
        he->y -= 1;
       
    }

    if (input.down == 1)
    {
        he->y += 1;
         
       
    }

    if (input.left == 1)
    {
                
		if(jeu->camera.x<=0||he->x>390) { he->x-=he->v * jeu->dt; he->d=-1;}
		else { jeu->camera.x-=he->v * jeu->dt; jeu->on=-1 ;he->d=-1; }
    }

    if (input.right == 1)
    {
               
             
               
               
		if((jeu->camera.x >= 3410 ) || (he->x < 390) ){  he->x+=he->v * jeu->dt; he->d=1; }
		else  { jeu->camera.x+= he->v * jeu->dt; jeu->on=1 ; he->d=1; }
    }
   
 SDL_BlitSurface(jeu->background,&jeu->camera, jeu->screen, &jeu->pos_background);
}

void dohero1( hero *he , Input input, Gestion *jeu , partage *  p )
{
    
    he->d=0;

  
    
    
    if (input.up == 1)
    {
        he->y -= 1;
       
    }

    if (input.down == 1)
    {
        he->y += 1;
         
       
    }

    if (input.left == 1)
    {
                
		if(p->pos1.x<=0||he->x>320) { he->x-=4; he->d=-1;}
		else { p->pos1.x-=3;  jeu->on = -1 ; he->d = -1 ; }
    }

    if (input.right == 1)
    {
               
             
               
               
		if((p->pos1.x >= 3410 ) || (he->x < 320) ){  he->x+=4; he->d=1; }
		else  { p->pos1.x+=3; jeu->on = 1 ;  he->d = 1 ;  }
    }
   

}
void dohero2( hero *he , Input input, Gestion *jeu , partage *  p )
{
    
    he->d=0;

    
    
    

    if (input.jump  == 1)
    {
                
		if(p->pos2.x<=0||he->x>960) { he->x-=4; he->d=-1;}
		else { p->pos2.x-=3;  jeu->on = -1 ; he->d = -1 ; }
    }

    if (input.attack == 1)
    {
               
             
               
               
		if((p->pos2.x >= 3410 ) || (he->x < 960) ){  he->x+=4; he->d=1; }
		else  { p->pos2.x+=3; jeu->on = 1 ;  he->d = 1 ;  }
    }
   

}
 void drawhero(hero * he , Gestion *jeu)
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = he->x;
    dest.y = he->y;
    dest.w = 55;
    dest.h = 96;

    /* Rectangle source à blitter */
    SDL_Rect src;


    //Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
    //la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
    src.x = he->frameNumber * 55;
    src.y = 0;
    src.w = 55;
    src.h = 96;

    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(he->sprite, &src, jeu->screen, &dest);
    SDL_Flip(jeu->screen);
}

