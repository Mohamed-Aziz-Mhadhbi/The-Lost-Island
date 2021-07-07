#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "fonctions.h"
#include "quit.h"


void menu();
void Quit();

void credit ()
{
   SDL_Event event;

    int i = 1 ;
    int x = 1 ;



    SDL_Surface *fond = NULL;
    SDL_Surface *b1 = NULL;

   SDL_Rect posFond;
   SDL_Rect posB1;



   Mix_AllocateChannels(2);

   Mix_Chunk *alarm;

   alarm = Mix_LoadWAV("music/selected.wav");



    fond = IMG_Load("credit/credit-01.png");
    b1 = IMG_Load("credit/credit-02.png");






    posFond.x=0;
    posFond.y=0;


    posB1.x=0;
    posB1.y=0;



    SDL_BlitSurface(fond, NULL, fenetre, &posFond);
    SDL_Flip(fenetre);

    while ( 1 )
    {
        while (SDL_PollEvent(&event))

      {

          if(event.type == SDL_QUIT)
		Quit();

            else if(event.type == SDLK_ESCAPE)
                        menu ();

                    else if(SDL_WaitEvent(&event))
                   {
                 if(((event.type == SDLK_RETURN)||(event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                       { 
                    
                            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
                            SDL_BlitSurface(b1, NULL, fenetre, &posB1);
                            SDL_Flip(fenetre);	
                            SDL_Delay(300);
			    menu ();
                            SDL_Flip(fenetre);	    
                    }
                }

            if (event.type == SDL_MOUSEMOTION )
          {
                if( (event.button.x>346 && event.button.x<452 && event.button.y>485 && event.button.y<538) )
              {x = 1 ;}
              else {x=0;}

          }

           if(event.type == SDL_MOUSEBUTTONDOWN )
            {
              if( (event.button.x>346 && event.button.x<452 && event.button.y>485 && event.button.y<538) )
            {

   
               menu();
            }

        }
        

        switch (x)
         {
         case 0:
          {
         SDL_BlitSurface(fond,NULL,fenetre ,&posFond);
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

        }
        
        SDL_Flip (fenetre);
    }
    }
    SDL_Flip (fenetre);
    //Liberation des surface

    Mix_CloseAudio();

    SDL_FreeSurface(b1);

    SDL_FreeSurface(fond);
    //LIB
}
