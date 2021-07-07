#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "fonctions.h"
#include "map.h"
#include "quit.h"

void Quit();
void Map();
void menu();

void help ()
{
   SDL_Event event;

    int i = 1 ;
    int x = 0 ;



    SDL_Surface *fond = NULL;
    SDL_Surface *b1 = NULL;
    SDL_Surface *b2 = NULL;

   SDL_Rect posFond;
   SDL_Rect posB1;
   SDL_Rect posB2;





   Mix_AllocateChannels(2);

   Mix_Chunk *alarm;

   alarm = Mix_LoadWAV("music/selected.wav");



    fond = IMG_Load("help/fond.png");
    b1 = IMG_Load("help/backclick.png");
    b2 = IMG_Load("help/loadgameclick.png");





    posFond.x=0;
    posFond.y=0;


    posB1.x=0;
    posB1.y=0;

    posB2.x=0;
    posB2.y=0;



    SDL_BlitSurface(fond, NULL, fenetre, &posFond);
    SDL_Flip(fenetre);

    while ( 1 )
    {
        SDL_WaitEvent(&event);


      switch(event.type)
      {
          case SDL_QUIT:
		Quit();

            case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                         x--;
                         Mix_PlayChannel(1, alarm, 0);
                      if(x<1){x=2;}
            break;

            case SDLK_RIGHT:
                       x++;
                       Mix_PlayChannel(1, alarm, 0);
                       if(x>2){x=1;}
                        break;
            case SDLK_ESCAPE:
                        menu ();

                        break;
                    case SDLK_RETURN:
                        switch (x)
                        {
                        case 1 :
                            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
                            SDL_BlitSurface(b1, NULL, fenetre, &posB1);
			    menu ();

                            SDL_Flip(fenetre);
                            break;
                        case 2:
                            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
                            SDL_BlitSurface(b2, NULL, fenetre, &posB2);
                            SDL_Flip(fenetre);
				
			    Map();
                            
                            SDL_Flip(fenetre);
                             break;



                        }
                    break;
                    }
                break;

            case SDL_MOUSEMOTION :
          {
                if( (event.button.x>191 && event.button.x<342 && event.button.y>473 && event.button.y<521) )
              {x = 1 ;}

              else if ( (event.button.x>466 && event.button.x<625 && event.button.y>473 && event.button.y<521) )
              {x = 2 ;}

              else {x=0;}


          }break ;

          case SDL_MOUSEBUTTONDOWN :
            {
              if( (event.button.x>191 && event.button.x<342 && event.button.y>473 && event.button.y<521) )
            {
               menu();
            }
            else if ( (event.button.x>466 && event.button.x<625 && event.button.y>473 && event.button.y<521) )
              {
		SDL_Flip(fenetre);                
		Map();
                
              }

        }break ;

        }

   switch (x)
      {

        case 0:
        {
           SDL_BlitSurface(fond, NULL, fenetre, &posFond);





            SDL_Flip(fenetre);
            break;
          }
        case 1:
        {
           SDL_BlitSurface(fond, NULL, fenetre, &posFond);
            SDL_BlitSurface(b1, NULL, fenetre, &posB1);





            SDL_Flip(fenetre);

            Mix_PlayChannel(1, alarm, 0);
            break;
          }

        case 2:
        {
             SDL_BlitSurface(fond, NULL, fenetre, &posFond);
            SDL_BlitSurface(b2, NULL, fenetre, &posB2);





            SDL_Flip(fenetre);

            Mix_PlayChannel(1, alarm, 0);
          break;
      }


        }
        SDL_Flip (fenetre);
    }
    SDL_Flip (fenetre);
    //Liberation des surface

    Mix_CloseAudio();

    SDL_FreeSurface(b1);
    SDL_FreeSurface(b2);

    SDL_FreeSurface(fond);
    //LIB
}
