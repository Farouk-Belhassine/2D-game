
#include "enigme.h"

void init_enigme(Enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}

 void generate_afficher (SDL_Surface * screen , char image [],Enigme *e,int *alea)
{ 
	

 *alea = 1+ rand()%3;

 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);

 SDL_BlitSurface(e->img,NULL, screen,&(e->p)) ;
  SDL_Flip( screen) ;
}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.png")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =3;	
 	}
 	return solution;
 }

int resolution (int * go ,int * run  )
{
	SDL_Event event ;
        int r=0 ;
        SDL_WaitEvent(&event);
	
	switch(event.type)
	{
		  case SDL_QUIT:
			        (*go) = 0 ;
                                (*run)=0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
                          (*run)=0;
			   break ;
			   case  SDLK_z :
			   r= 2;
                           (*run)=0;
			   break;
			   case SDLK_e: 
			   r=3 ;
                            (*run)=0;
			   break;
                           default: break;
			    }
       break ;

                 
	
}
  return r ;
}
 
 void afficher_resultat (SDL_Surface * screen,int s,int r,Enigme *en)
 {
 
 	if (r==s)
 	{
 		en->img=IMG_Load("b.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->img=IMG_Load("f.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
                SDL_Flip(screen);

 	}
 }
