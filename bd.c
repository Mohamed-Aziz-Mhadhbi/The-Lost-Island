#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "map.h"
#include "bd.h"
#include "menu.h"
#include "fonctions.h"



                       void intro_game_play()
			{
			    SDL_Event event;

			    SDL_Surface *imageHP[5];
                            SDL_Surface *ecran = NULL ;
                            SDL_Surface *skip = NULL;
                            SDL_Rect posSkip;


                           int framecinema;
                           char imgname[100];
                           for (framecinema=0; framecinema<5; framecinema++)
                             {
                            sprintf(imgname,"bd/%d.png",framecinema+1);
                            imageHP[framecinema]=IMG_Load(imgname);
                            SDL_BlitSurface(imageHP[framecinema],NULL,ecran,NULL);
                            SDL_Flip(ecran);
                            SDL_FreeSurface(imageHP[framecinema]);
                            SDL_Delay (1500);
                          }
                  while(1)
	          {
		  while (SDL_PollEvent(&event))

                    {
			    if (event.type == SDL_QUIT)
			    {
		        exit(0);
		            }
		    if(event.type == SDL_MOUSEMOTION)
		    {
		       if (((event.button.x >= 368) && (event.button.x <= 436))&&((event.button.y >= 278) && (event.button.y <= 314)))
		            {
		                  skip = IMG_Load("bd/skip.png");
		                  posSkip.x=0;
		                  posSkip.y=0;
		                  SDL_BlitSurface(skip, NULL, fenetre, &posSkip);
		    if(event.type == SDL_MOUSEBUTTONDOWN)
		    {
		        if (event.button.button == SDL_BUTTON_LEFT)
		        {
		            if (((event.button.x >= 368) && (event.button.x <= 436))&&((event.button.y >= 278) && (event.button.y <= 314)))
		            {
				 Map();
                                 SDL_Flip(fenetre);

		            }
		        }
		    }
		   }
		  }
		}

	    }
      SDL_Flip(fenetre);
    }
