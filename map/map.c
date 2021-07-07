#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
#include "map.h"
#include "stage1.h"

void Map (Acteurs* acteurs , Boutons* boutons, Hero* hero)
{
    
    int J = 1;

    int i = 1 ;
    int choix = 1 ;



    acteurs->fond = NULL;
    boutons->b1 = NULL;
    boutons->b2 = NULL;
    boutons->b3 = NULL;
    boutons->b4 = NULL;  

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

    

    acteurs->fond = IMG_Load("images/map/map.jpg");
    boutons->b1 = IMG_Load("images/map/level-01.png");
    boutons->b2 = IMG_Load("images/map/level-02.png");
    boutons->b3 = IMG_Load("images/map/level-03.png");
    boutons->b4 = IMG_Load("images/map/return-boutton.png");
    
    
     


    acteurs->posFond.x=0;
    acteurs->posFond.y=0;

    boutons->posB1.x=0;
    boutons->posB1.y=0;

    boutons->posB2.x=0;
    boutons->posB2.y=0;

    boutons->posB3.x=0;
    boutons->posB3.y=0;

    boutons->posB4.x=0;
    boutons->posB4.y=0;

    

    SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
    SDL_Flip(acteurs->screen);

    while ( J != 0 )
    {
        SDL_WaitEvent(&acteurs->event);

         
      switch(acteurs->event.type)
      {
          case SDL_QUIT: exit_barre4 (acteurs ,  boutons, hero);   
             
            case SDL_KEYDOWN :
            switch(acteurs->event.key.keysym.sym)
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
                        menu (acteurs ,  boutons, hero); 
            
                        break;
                    case SDLK_RETURN:
                        switch (i)
                        {
                        case 1 :
                            SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
                            SDL_BlitSurface(boutons->b1, NULL, acteurs->screen, &boutons->posB1);
                           
                            Stage1(acteurs ,  boutons, hero);
                            SDL_Flip(acteurs->screen);
                            break;
                        case 2:
                            SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
                            SDL_BlitSurface(boutons->b2, NULL, acteurs->screen, &boutons->posB2);
                           
                            Stage2(acteurs ,  boutons, hero);
                            SDL_Flip(acteurs->screen);
                             break;
                        case 3:
                            SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
                            SDL_BlitSurface(boutons->b3, NULL, acteurs->screen, &boutons->posB3);
                           
                            Stage3(acteurs ,  boutons, hero);
                            SDL_Flip(acteurs->screen);
                             break;
                        case 4:
                             menu (acteurs ,  boutons, hero);
                             break;
                        
                        }
                    break; 
                    }
                break;

            case SDL_MOUSEMOTION :
          {
                if( (acteurs->event.button.x>245 && acteurs->event.button.x<289 && acteurs->event.button.y>107 && acteurs->event.button.y<154) )
              {choix = 1 ;}
        
              else if ( (acteurs->event.button.x>541 && acteurs->event.button.x<583 && acteurs->event.button.y>268 && acteurs->event.button.y<327) )
              {choix = 2 ;}

            else if (  (acteurs->event.button.x>265 && acteurs->event.button.x<297 && acteurs->event.button.y>385 && acteurs->event.button.y<426) )
            {choix = 3 ;}

            else if (  (acteurs->event.button.x>57 && acteurs->event.button.x<117 && acteurs->event.button.y>505 && acteurs->event.button.y<544) )
            {choix = 4 ;}

           
              else {choix=0;}
             
              
          }break ;
          
          case SDL_MOUSEBUTTONUP :
            {
              if( (acteurs->event.button.x>245 && acteurs->event.button.x<289 && acteurs->event.button.y>107 && acteurs->event.button.y<154) )
            {   
              Stage1(acteurs ,  boutons, hero);  
            }
            else if ( (acteurs->event.button.x>541 && acteurs->event.button.x<583 && acteurs->event.button.y>268 && acteurs->event.button.y<327) )
              {Stage2(acteurs ,  boutons, hero);  
              }

           else if (  (acteurs->event.button.x>265 && acteurs->event.button.x<297 && acteurs->event.button.y>385 && acteurs->event.button.y<426) )
            {Stage3(acteurs ,  boutons, hero); 
            }

            else if (  (acteurs->event.button.x>57 && acteurs->event.button.x<117 && acteurs->event.button.y>505 && acteurs->event.button.y<544) )
            {
             menu (acteurs ,  boutons, hero); 
            }
            
        }break ;
        
        } 

   switch (choix)
      {
       
        
        case 1:
        {
           SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
            SDL_BlitSurface(boutons->b1, NULL, acteurs->screen, &boutons->posB1);
                            
           
            
            
 
            SDL_Flip(acteurs->screen);

            Mix_PlayChannel(1, alarm, 0);
            break;
          }

        case 2:
        {
             SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
            SDL_BlitSurface(boutons->b2, NULL, acteurs->screen, &boutons->posB2);
                            
           
            
            
 
            SDL_Flip(acteurs->screen);

            Mix_PlayChannel(1, alarm, 0);
          break;
      }

        case 3:
        { 
             SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
            SDL_BlitSurface(boutons->b3, NULL, acteurs->screen, &boutons->posB3);
                            
           
            
            
 
            SDL_Flip(acteurs->screen);

            Mix_PlayChannel(1, alarm, 0);
          break;
        }
        case 4:
        { 
            SDL_BlitSurface(acteurs->fond, NULL, acteurs->screen, &acteurs->posFond);
            SDL_BlitSurface(boutons->b4, NULL, acteurs->screen, &boutons->posB4);
                            
           
            
            
 
            SDL_Flip(acteurs->screen);

            Mix_PlayChannel(1, alarm, 0);
          break;
        }

        
        }
        SDL_Flip (acteurs->screen);
    }
    SDL_Flip (acteurs->screen);
    //Liberation des surface
    
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
     
    SDL_FreeSurface(boutons->b1);
    SDL_FreeSurface(boutons->b2);
    SDL_FreeSurface(boutons->b3);
    SDL_FreeSurface(boutons->b4);

    SDL_FreeSurface(acteurs->fond);
    //LIB
}
