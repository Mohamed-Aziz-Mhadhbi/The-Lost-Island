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
#include "credit.h"
#include "quit.h"

void intro_game_play();
void credit();
void help();
void Quit();

void menu()
{
    int x=0;
	
      
    SDL_Surface *imageHP[4];
    SDL_Surface *ecran;
    SDL_Surface *skip = NULL;
    SDL_Rect posSkip;

    SDL_Surface *fond;
    SDL_Surface *b1 ;
    SDL_Surface *b2 ;
    SDL_Surface *b3 ;
    SDL_Surface *b4 ;
    SDL_Surface *b5 ;
    SDL_Surface *b6 ;

    SDL_Rect posFond;
    SDL_Rect posB1;
    SDL_Rect posB2;
    SDL_Rect posB3;
    SDL_Rect posB4;
    SDL_Rect posB5;
    SDL_Rect posB6;
    SDL_Event event;

        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
   {
      printf("%s", Mix_GetError());
   }


   Mix_Music *musique ;

   musique=Mix_LoadMUS("music/musique.mp3");

   Mix_PlayMusic(musique, -1);



   Mix_AllocateChannels(6);

   Mix_Chunk *alarm;

   alarm = Mix_LoadWAV("music/selected.wav");



     //image Load
    fond= IMG_Load("menu/menu.png");
    b1 = IMG_Load("menu/boutton-01.png");
    b2 = IMG_Load("menu/boutton-02.png");
    b3 = IMG_Load("menu/boutton-03.png");
    b4 = IMG_Load("menu/boutton-04.png");
    b5 = IMG_Load("menu/boutton-05.png");
    b6 = IMG_Load("menu/boutton-06.png");



    //Screen Caption


    posFond.x=0;
    posFond.y=0;

    posB1.x=0;
    posB1.y=0;

    posB2.x=0;
    posB2.y=0;

    posB3.x=0;
    posB3.y=0;

    posB4.x=0;
    posB4.y=0;

    posB5.x=0;
    posB5.y=0;

    posB6.x=0;
    posB6.y=0;

    SDL_BlitSurface( fond ,NULL, fenetre, &posFond );
    SDL_Flip(fenetre);


    while(1)
    {
        while (SDL_PollEvent(&event))

        {
            if (event.type == SDL_QUIT)
            {
                Quit();
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 1) && (event.button.x <=1 ))&&((event.button.y >= 1) && (event.button.y <=1 )))
                    {
                        system("");
                    }
                    if (((event.button.x >=1 ) && (event.button.x <=1 ))&&((event.button.y >= 1) && (event.button.y <=1 )))
                    {
                        system("");
                    }
                    if (((event.button.x >= 1) && (event.button.x <= 1))&&((event.button.y >= 1) && (event.button.y <= 1)))
                    {
                        system("");
                    }
                }
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                    if( (event.button.x>309 && event.button.x<485 && event.button.y>249 && event.button.y<286) )
              {x = 1 ;}

              else if ( (event.button.x>309 && event.button.x<485 && event.button.y>302 && event.button.y<340) )
              {x = 2 ;}

            else if (  (event.button.x>309 && event.button.x<485 && event.button.y>357 && event.button.y<395) )
            {x = 3 ;}

            else if ( (event.button.x>309 && event.button.x<485 && event.button.y>409 && event.button.y<446) )
            {x = 4 ;}

            else if ( (event.button.x>309 && event.button.x<485 && event.button.y>462 && event.button.y<500) )
              {x = 5 ;}

              else if ( (event.button.x>309 && event.button.x<485 && event.button.y>515 && event.button.y<553) )
              {x = 6 ;}
              else
              {x=0;}

            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    switch (x)
                    {
                    case 1:
                        Mix_PlayChannel(1, alarm, 0);
			SDL_BlitSurface(fond, NULL,fenetre , &posFond);
                            SDL_BlitSurface(b1, NULL,fenetre , &posB1);

			ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

                       int framecinema;
                       char imgname[50];
                       for (framecinema=0; framecinema<4; framecinema++)
                         {
                        sprintf(imgname,"bd/%d.png",framecinema+1);
                        imageHP[framecinema]=IMG_Load(imgname);
                        SDL_BlitSurface(imageHP[framecinema],NULL,ecran,NULL);
                        SDL_Flip(ecran);
                        SDL_FreeSurface(imageHP[framecinema]);
                        SDL_Delay (1500);
                      }
                      SDL_Delay (1000);
                       Map();
                             SDL_Flip(fenetre);

                
                        break;
                    case 2:
                        //Action
                        Mix_PlayChannel(1, alarm, 0);
                        break;
                    case 3:
			Mix_PlayChannel(1, alarm, 0);
                        credit();
                        
                        break;
                        case 4:
                        //Action
                        Mix_PlayChannel(1, alarm, 0);
                        break;
                    case 5:
			Mix_PlayChannel(1, alarm, 0);
                        help();
                        
                        break;
                    case 6:
		        Mix_PlayChannel(1, alarm, 0);
                        Quit();
                        
                        break;
                    }
                }
            }
            if (event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_DOWN)
                {    
                    if(x<=6)
                        x=x+1;
		if(x==7) 
                x=1;
               }
                if(event.key.keysym.sym == SDLK_UP)
                {   
                    if(x>0)
                        x=x-1;
			if(x==0) 
                x=6;
                }
                else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                {
                    switch (x)
                    {
                    case 1:
                        Mix_PlayChannel(1, alarm, 0);
			SDL_BlitSurface(fond, NULL,fenetre , &posFond);
                            SDL_BlitSurface(b1, NULL,fenetre , &posB1);

			ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

                       int framecinema;
                       char imgname[50];
                       for (framecinema=0; framecinema<4; framecinema++)
                         {
                        sprintf(imgname,"bd/%d.png",framecinema+1);
                        imageHP[framecinema]=IMG_Load(imgname);
                        SDL_BlitSurface(imageHP[framecinema],NULL,ecran,NULL);
                        SDL_Flip(ecran);
                        SDL_FreeSurface(imageHP[framecinema]);
                        SDL_Delay (1500);
                      }
       
                       Map();
                             SDL_Flip(fenetre);

                        
                        break;
                    case 2:
                       // Action
                        Mix_PlayChannel(1, alarm, 0);
                        break;
                    case 3:
                        Mix_PlayChannel(1, alarm, 0);
                        credit();
                        
                        break;
                        case 4:
                        //Action
                        Mix_PlayChannel(1, alarm, 0);
                        break;
                    case 5:
	                Mix_PlayChannel(1, alarm, 0);
                        help();
                        
                        break;
                    case 6:
			Mix_PlayChannel(1, alarm, 0);
                        Quit();
                        
                        break;

                    }
                }
              }

	switch (x)
	      {


        case 1:
        {
           SDL_BlitSurface(fond, NULL, fenetre, &posFond);
           SDL_BlitSurface(b1, NULL, fenetre, &posB1);





            SDL_Flip(fenetre);

            
            break;
          }

        case 2:
        {
            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
            SDL_BlitSurface(b2, NULL, fenetre, &posB2);





            SDL_Flip(fenetre);
            
          break;
      }

        case 3:
        {
            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
            SDL_BlitSurface(b3, NULL, fenetre, &posB3);





            SDL_Flip(fenetre);
            
          break;
        }

        case 4:
        {
             SDL_BlitSurface(fond, NULL, fenetre, &posFond);
             SDL_BlitSurface(b4, NULL, fenetre, &posB4);





           SDL_Flip(fenetre);
           
          break;
        }

        case 5:
        {
            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
            SDL_BlitSurface(b5, NULL, fenetre, &posB5);





            SDL_Flip(fenetre);
           
            break;
        }
        case 6:
        {
          SDL_BlitSurface(fond, NULL, fenetre, &posFond);
          SDL_BlitSurface(b6, NULL, fenetre, &posB6);


          SDL_Flip(fenetre);
          
        }
        }

      }

              SDL_Flip (fenetre);
        }
        Mix_FreeMusic(musique);
        Mix_CloseAudio();

        SDL_BlitSurface( fond ,NULL, fenetre, & posFond);
       
        SDL_Flip(fenetre);

    }
