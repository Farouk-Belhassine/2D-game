#include "draw.h"

void crono(Gestion *s){
char temps[20]={0};
TTF_Font *police = NULL;
SDL_Color couleurNoire = {255,255,255};
SDL_Surface *texte = NULL;
SDL_Rect textposition;
textposition.x=900;
textposition.y=20;
police = TTF_OpenFont("GODOFWAR.TTF",30);
unsigned int currentTime=SDL_GetTicks();
currentTime=(currentTime/1000) ;
sprintf(temps,"time : %d Sec",currentTime); 
texte = TTF_RenderText_Blended(police,temps,couleurNoire);
SDL_BlitSurface(texte, NULL,s->screen, &textposition);SDL_Flip(s->screen);
SDL_FreeSurface(texte);
TTF_CloseFont(police);
 
}
SDL_Surface* drawImage(SDL_Surface *image,SDL_Surface *screen, int x, int y)
{
    SDL_Rect dest;
    
    /* Règle le rectangle à blitter selon la taille de l'image source */

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;
   
    /* Blitte l'image entière sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(image,NULL, screen, &dest);
    //SDL_Flip(screen);
return screen;
}

void drawpartage(partage * p , Gestion* jeu  )
{
   
    SDL_BlitSurface(p->background,&p->pos1, jeu->screen, &p->camera1);
    SDL_BlitSurface(p->background,&p->pos2, jeu->screen, &p->camera2);
    SDL_Flip(jeu->screen);

}




SDL_Surface *loadImage(char *name)
{
    /* Charge une image temporaire avec SDL Image */
    SDL_Surface *temp = IMG_Load(name);
    SDL_Surface *image;

    /* Si elle n'est pas chargée on quitte avec une erreur */
    if (temp == NULL)
    {
        printf("Failed to load image %s\n", name);

        return NULL;
    }

    /* Ajoute la transparence à l'image temporaire en accord avec les defines TRANS_R, G, B */

    SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, 0, 0, 0));


    /* Convertit l'image au format de l'écran (screen) pour un blit plus rapide */

    image = SDL_DisplayFormat(temp);

    /* Libère l'image temporaire */
    SDL_FreeSurface(temp);

    if (image == NULL)
    {
        printf("Failed to convert image %s to native format\n", name);

        return NULL;
    }

    /* Retourne l'image au format de l'écran pour accélérer son blit */

    return image;


}

SDL_Surface *loadImageN(char *name)
{


    SDL_Surface *image = IMG_Load(name);


    /* Si elle n'est pas chargée on quitte avec une erreur */
    if (image == NULL)
    {
        printf("Failed to load image %s\n", name);

        return NULL;
    }

    /* Ajoute la transparence à l'image en accord avec les defines TRANS_R, G, B */

    SDL_SetColorKey(image, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(image->format, 255, 255, 255));

    return image;


}
SDL_Surface* draw_menu (Menu menu , SDL_Surface* screen ) 
{    screen=drawImage(menu.background,screen, 0, 0);
    screen=drawImage(menu.rectangle,screen,menu.pos_rectangle.x,menu.pos_rectangle.y);
    screen=drawImage(menu.texte[0],screen, 10, 240);
    screen=drawImage(menu.texte[1],screen, 10, 300);
    screen=drawImage(menu.texte[2],screen,10, 360);
    screen=drawImage(menu.texte[3],screen, 10, 420);
     screen=drawImage(menu.texte[5],screen, 10, 180);
    screen=drawImage(menu.texte[4],screen, 20, 650);
    SDL_Flip(screen);
    return screen;
}
SDL_Surface* draw_menu2 (Menu menu , SDL_Surface* screen ) 
{    screen=drawImage(menu.background,screen, 0, 0);
    screen=drawImage(menu.rectangle,screen,menu.pos_rectangle.x,menu.pos_rectangle.y);
    screen=drawImage(menu.texte[0],screen, 10, 240);
    screen=drawImage(menu.texte[3],screen, 10, 300);
    
    SDL_Flip(screen);
    return screen;
}
void delay(unsigned int frameLimit)
{

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}


