#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
void radar(SDL_Rect joueur1,SDL_Rect joueur2, SDL_Surface *ecran,SDL_Surface *map)
{

	SDL_Surface *boutton_joueur1=NULL;
	SDL_Surface *boutton_joueur2=NULL;
	SDL_Rect pos_map;
	//SDL_Rect echelle;
	SDL_Rect pos_boutton_joueur1;
	SDL_Rect pos_boutton_joueur2;
	map=IMG_Load("newradar.png");
	boutton_joueur1=IMG_Load("Red.png");	
	boutton_joueur2=IMG_Load("PosGreen.png");
	pos_map.x=0;
	pos_map.y=0;
	
	//echelle.x=0.30;
	//echelle.y=0.34;
	pos_boutton_joueur1.x=joueur1.x*0.3;
	pos_boutton_joueur1.y=150;//ou joueur1.y*0.3ou+
	pos_boutton_joueur2.x=joueur2.x*0.3;
	pos_boutton_joueur2.y=150;//ou joueur2.y*0.3ou +
	
	SDL_BlitSurface(map,NULL,ecran,&pos_map);
	SDL_BlitSurface(boutton_joueur1,NULL,ecran,&pos_boutton_joueur1);
	SDL_BlitSurface(boutton_joueur2,NULL,ecran,&pos_boutton_joueur2);
	//SDL_Flip(ecran);
	SDL_FreeSurface(boutton_joueur1);
	SDL_FreeSurface(boutton_joueur2);
}
int main()
{
	SDL_Surface *ecran=NULL ;
	SDL_Surface *image=NULL;
	SDL_Surface *joueur1=NULL;
	SDL_Surface *joueur2=NULL;
	SDL_Surface *map=NULL;
	SDL_Event event;
	SDL_Rect pos_joueur1;
	SDL_Rect pos_joueur2;
	SDL_Rect positionimage;
	int continuer=1,s;
	SDL_Init(SDL_INIT_VIDEO);
	ecran=SDL_SetVideoMode(1200,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	image=IMG_Load("fond.jpg");
	joueur1=IMG_Load("zozor.bmp");
	joueur2=IMG_Load("zozor.bmp");
	pos_joueur1.x=0;
	pos_joueur1.y=300;
	pos_joueur2.x=550;
	pos_joueur2.y=350;
	positionimage.x=0;
	positionimage.y=0;
	/*SDL_BlitSurface(image,NULL,ecran,&positionimage);
	SDL_Flip(ecran);*/
	//radar(pos_joueur1,pos_joueur2,ecran,map);
	SDL_EnableKeyRepeat(10, 10);
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer=0;
			break;
			case SDL_KEYDOWN:
            			switch (event.key.keysym.sym)
            			{
                			case SDLK_ESCAPE:
                    			continuer = 0;
                    			break;
					case SDLK_UP:
					pos_joueur1.y--;
					break;
					case SDLK_DOWN:
					pos_joueur1.y++;
					break;
					case SDLK_LEFT:
					pos_joueur1.x--;
					break;
					case SDLK_RIGHT:
					pos_joueur1.x++;
					break;
            			}
			break;
			default:;
		}
		/*SDL_FreeSurface(boutton_joueur1);
		SDL_FreeSurface(boutton_joueur2);*/
		SDL_BlitSurface(joueur1,NULL,ecran,&pos_joueur1);
		SDL_BlitSurface(joueur2,NULL,ecran,&pos_joueur2);
		radar(pos_joueur1,pos_joueur2,ecran,map);
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(image);
	SDL_FreeSurface(joueur1);
	SDL_FreeSurface(joueur2);
	SDL_FreeSurface(map);
	SDL_FreeSurface(ecran);
	return 0;
}
