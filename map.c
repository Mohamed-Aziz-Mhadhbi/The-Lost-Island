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
#include "quit.h"
#include "stage_1.h"

void menu();
void Quit();
void stage_1();

void Map ()
{
   SDL_Event event;
    int J = 1;

    int i = 1 ;
    int choix = 1 ;



    SDL_Surface *fond = NULL;
    SDL_Surface *b1 = NULL;
    SDL_Surface *b2 = NULL;
    SDL_Surface *b3 = NULL;
    SDL_Surface *b4 = NULL;

   SDL_Rect posFond;
   SDL_Rect posB1;
   SDL_Rect posB2;
   SDL_Rect posB3;
   SDL_Rect posB4;


    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }


   Mix_Music *musique ;

   musique=Mix_LoadMUS("music/musique.mp3");

   Mix_PlayMusic(musique, -1);



   Mix_AllocateChannels(5);

   Mix_Chunk *alarm;

   alarm = Mix_LoadWAV("music/selected.wav");



    fond = IMG_Load("map/map.jpg");
    b1 = IMG_Load("map/level-01.png");
    b2 = IMG_Load("map/level-02.png");
    b3 = IMG_Load("map/level-03.png");
    b4 = IMG_Load("map/return.png");





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



    SDL_BlitSurface(fond, NULL, fenetre, &posFond);
    SDL_Flip(fenetre);

    while ( J != 0 )
    {
        SDL_WaitEvent(&event);


      switch(event.type)
      {
          case SDL_QUIT: 
		Quit();
                

            case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                         choix--;
                         Mix_PlayChannel(1, alarm, 0);
                      if(choix<1){choix=4;}
            break;

            case SDLK_DOWN:
                       choix++;
                       Mix_PlayChannel(1, alarm, 0);
                       if(choix>4){choix=1;}
                        break;
            case SDLK_ESCAPE:
                        menu ();

                        break;
                    case SDLK_RETURN:
                        switch (i)
                        {
			
                        case 1 :
                            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
                            SDL_BlitSurface(b1, NULL, fenetre, &posB1);

                            stage_1();
                            SDL_Flip(fenetre);
                            break;
                        case 2:
                            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
                            SDL_BlitSurface(b2, NULL, fenetre, &posB2);

                            //Stage2(acteurs ,  boutons, hero);
                            SDL_Flip(fenetre);
                             break;
                        case 3:
                            SDL_BlitSurface(fond, NULL, fenetre, &posFond);
                            SDL_BlitSurface(b3, NULL, fenetre, &posB3);

                            //Stage3(acteurs ,  boutons, hero);
                            SDL_Flip(fenetre);
                             break;
                        case 4:
                             menu ();
                             break;

                        }
                    break;
                    }
                break;

            case SDL_MOUSEMOTION :
          {
                if( (event.button.x>273 && event.button.x<322 && event.button.y>178 && event.button.y<223) )
              {choix = 1 ;}

              else if ( (event.button.x>189 && event.button.x<238 && event.button.y>327 && event.button.y<373) )
              {choix = 2 ;}

            else if (  (event.button.x>562 && event.button.x<610 && event.button.y>361 && event.button.y<409) )
            {choix = 3 ;}

            else if (  (event.button.x>57 && event.button.x<117 && event.button.y>505 && event.button.y<544) )
            {choix = 4 ;}


              else {choix=0;}


          }break ;

          case SDL_MOUSEBUTTONUP :
            {
              if( (event.button.x>273 && event.button.x<322 && event.button.y>178 && event.button.y<223) )
            {
              stage_1();
            }
            else if ( (event.button.x>189 && event.button.x<238 && event.button.y>327 && event.button.y<373) )
              {//Stage2(acteurs ,  boutons, hero);
              }

           else if (  (event.button.x>562 && event.button.x<610 && event.button.y>361 && event.button.y<409) )
            {//Stage3(acteurs ,  boutons, hero);
            }

            else if (  (event.button.x>57 && event.button.x<117 && event.button.y>505 && event.button.y<544) )
            {
             menu ();
            }

        }break ;

        }

   switch (choix)
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


        }
        SDL_Flip (fenetre);
    }
    SDL_Flip (fenetre);
    //Liberation des surface

    Mix_FreeMusic(musique);
    Mix_CloseAudio();

    SDL_FreeSurface(b1);
    SDL_FreeSurface(b2);
    SDL_FreeSurface(b3);
    SDL_FreeSurface(b4);

    SDL_FreeSurface(fond);
    //LIB
}

