#include "menu.h"
SDL_Surface* menu_principale(SDL_Surface* screen , int *menuout )
{    
    Menu menu ;
    int go = 1; 
    int souris = 11;
    initmenu(&menu);
    loadMenu(&menu);   
    SDL_Event event;
    menu.click_sound = loadSound("graphics/cursor.wav") ;
    menu.soundtrack = loadSound_infini("graphics/music.mp3") ;    
    screen=draw_menu(menu,screen);
    playSound_infini(menu.soundtrack);
    while (go==1)
{   SDL_WaitEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        exit(0);
        break;
    case SDL_MOUSEMOTION:
if((event.motion.x>0)&&(event.motion.x<(menu.rectangle->w-50))&&(event.motion.y>MENUPOS_Y0)&&(event.motion.y<(MENUPOS_Y0+menu.rectangle->h)))
{   souris=0;
    menu.pos_rectangle.y = MENUPOS_Y0;
    menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
    menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
    menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
    menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
    menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.noir);
    screen=draw_menu(menu,screen);
    
}

else if((event.motion.x>0)&&(event.motion.x<(menu.rectangle->w-50))&&(event.motion.y>MENUPOS_Y1)&&(event.motion.y<(MENUPOS_Y1+menu.rectangle->h)))
{   souris=1;
    menu.pos_rectangle.y = MENUPOS_Y1;
    menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.noir);
    menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
    menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
    menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
   menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
    screen=draw_menu(menu,screen);
}

else if((event.motion.x>0)&&(event.motion.x<(menu.rectangle->w-50))&&(event.motion.y>MENUPOS_Y2)&&(event.motion.y<(MENUPOS_Y2+menu.rectangle->h)))
{   souris=2;
    menu.pos_rectangle.y = MENUPOS_Y2;
    menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
    menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.noir);
    menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
    menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
    menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
    screen=draw_menu(menu,screen);
}

else if((event.motion.x>0)&&(event.motion.x<(menu.rectangle->w-50))&&(event.motion.y>MENUPOS_Y3)&&(event.motion.y<(MENUPOS_Y3+menu.rectangle->h)))
{   souris=3;
    menu.pos_rectangle.y = MENUPOS_Y3;
    menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
    menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
    menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.noir);
    menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
    menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
    screen=draw_menu(menu,screen);
    
}
else if((event.motion.x>0)&&(event.motion.x<(menu.rectangle->w-50))&&(event.motion.y>MENUPOS_Y4)&&(event.motion.y<(MENUPOS_Y4+menu.rectangle->h)))
{   souris=44;
    menu.pos_rectangle.y = MENUPOS_Y4;
    menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
    menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
    menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
    menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.noir);
    menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
    screen=draw_menu(menu,screen);
    
}

else if((event.motion.x>0)&&(event.motion.x<(menu.rectangle->w-50))&&(event.motion.y>600)&&(event.motion.y<720))
{
  menu.texte[4] = TTF_RenderText_Blended(menu.police2, "Kridiss Ahmed / Turky Amine / belhassine farouk / mezrani moetaz / hasni salim / ben mohamed louay ", menu.blanc);
  screen=draw_menu(menu,screen);
  SDL_Delay(10);
}
else {menu.texte[4] = TTF_RenderText_Blended(menu.police1, "TEAM", menu.blanc);
screen=draw_menu(menu,screen);}
//else SDL_Delay(1);
break ;
 
case SDL_MOUSEBUTTONUP:

if((event.button.button == SDL_BUTTON_LEFT)&&(souris == 0))
{
    menu.menuout=2;
    go=0;
    playSound(menu.click_sound);
    SDL_Delay(200);
    
}
if((event.button.button == SDL_BUTTON_LEFT)&&(souris == 1))
{ playSound(menu.click_sound);
   menu.menuout=0;
    go=0;
}
if((event.button.button == SDL_BUTTON_LEFT) && (souris == 2))
{playSound(menu.click_sound);
}
if((event.button.button == SDL_BUTTON_LEFT)&&(souris == 3))
{ playSound(menu.click_sound);
   SDL_Delay(500);
    exit(0);
}
  break;  

    case  SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            switch(menu.pos_rectangle.y)
            {
            case MENUPOS_Y0 :
                menu.pos_rectangle.y = MENUPOS_Y4;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.noir);
menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
               screen=draw_menu(menu,screen);
                break;
            case MENUPOS_Y1 :
                menu.pos_rectangle.y = MENUPOS_Y0;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
 menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.noir);
               screen=draw_menu(menu,screen);
                break;
            case MENUPOS_Y2 :
                menu.pos_rectangle.y = MENUPOS_Y1;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.noir);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
  menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
             screen=draw_menu(menu,screen);
                break;
            case MENUPOS_Y3 :
                menu.pos_rectangle.y = MENUPOS_Y2;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.noir);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
   menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
               screen=draw_menu(menu,screen);
                break;
case MENUPOS_Y4 :
                menu.pos_rectangle.y = MENUPOS_Y3;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.noir);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
   menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
               screen=draw_menu(menu,screen);
                break;
            }
            break;
        case SDLK_DOWN:
            switch(menu.pos_rectangle.y)
            {
            case MENUPOS_Y0 :
                menu.pos_rectangle.y = MENUPOS_Y1;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.noir);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
   menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
            screen=draw_menu(menu,screen);
                break;
            case MENUPOS_Y1 :
                menu.pos_rectangle.y = MENUPOS_Y2;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.noir);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
 menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
              screen=draw_menu(menu,screen);
                break;
            case MENUPOS_Y2 :
                menu.pos_rectangle.y = MENUPOS_Y3;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.noir);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
            screen=draw_menu(menu,screen);
                break;
            case MENUPOS_Y3 :
                menu.pos_rectangle.y = MENUPOS_Y4;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.noir);
menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.blanc);
           screen=draw_menu(menu,screen);
                break;
 case MENUPOS_Y4 :
                menu.pos_rectangle.y = MENUPOS_Y0;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[1] = TTF_RenderText_Blended(menu.police1, "LOAD GAME", menu.blanc);
                menu.texte[2] = TTF_RenderText_Blended(menu.police1, "SETTING", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "QUIT", menu.blanc);
menu.texte[5] = TTF_RenderText_Blended(menu.police1, "MULTIJOUEUR", menu.noir);
           screen=draw_menu(menu,screen);
                break;
            }
            break;






        case SDLK_RETURN:
            switch(menu.pos_rectangle.y)
            {
            case MENUPOS_Y0 :
                menu.menuout=2;
                go=0;
                break;
            case MENUPOS_Y1 :  menu.menuout=0; go=0;
                break;
            case MENUPOS_Y2 :
                break; 
            case MENUPOS_Y3 : exit(0); 
                break;
            }
        
        break;
        case SDLK_ESCAPE:
                        exit(0);
                    break;
        default : 
        break;
}
break;

    }
   
    
}
    cleanup_menu(&menu);
    (*menuout)=menu.menuout;
    return screen ;
}
SDL_Surface* menu_2(SDL_Surface* screen , int *menuout , hero * he  , Monstre *monstre )
{    
    Menu menu ;
    int go = 1; 
    //int souris = 11;
    initmenu(&menu);
    loadMenu(&menu);   
    SDL_Event event;
     
    screen=draw_menu2(menu,screen);
    //playSound_infini(menu.soundtrack);
    while (go==1)
{   SDL_WaitEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        exit(0);
        break;
    


    case  SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            switch(menu.pos_rectangle.y)
            {
            case MENUPOS_Y1 :
                menu.pos_rectangle.y = MENUPOS_Y2;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "Quit", menu.noir);
               

               screen=draw_menu2(menu,screen);
                break;
            case MENUPOS_Y2 :
                menu.pos_rectangle.y = MENUPOS_Y1;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.noir);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "Quit", menu.blanc);
               screen=draw_menu2(menu,screen);
                break;
            
            }
            break;
        case SDLK_DOWN:
            switch(menu.pos_rectangle.y)
            {
            case MENUPOS_Y1 :
                menu.pos_rectangle.y = MENUPOS_Y2;
                menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.blanc);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "Quit", menu.noir);
            screen=draw_menu2(menu,screen);
                break;
            case MENUPOS_Y2 :
                menu.pos_rectangle.y = MENUPOS_Y1;
               menu.texte[0] = TTF_RenderText_Blended(menu.police1, "NEW GAME", menu.noir);
                menu.texte[3] = TTF_RenderText_Blended(menu.police1, "Quit", menu.blanc);
              screen=draw_menu2(menu,screen);
                break;
            
            }
            break;






        case SDLK_RETURN:
            switch(menu.pos_rectangle.y)
            {
            case MENUPOS_Y1 :
              // initializehero(he);
//initializeEnnemy(monstre) ; 
                menu.menuout=0;
                go=0;
                break;
            case MENUPOS_Y2 :  exit(0); go=0;
                break;
          
            }
        
        break;
        case SDLK_ESCAPE:
                        exit(0);
                    break;
        default : 
        break;
}
break;

    }
   
    
}
    //cleanup_menu(&menu);
    (*menuout)=menu.menuout;
    return screen ;
}


