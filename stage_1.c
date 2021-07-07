#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "stage_1.h"
#include "enigme.h"


/*________________________________________________________________________________________*/



void initialisation(Acteurs* acteurs)
{

	SDL_Surface* tmp1, *tmp2;
	tmp1 = SDL_LoadBMP("mapc.bmp");
	acteurs->backg_collision = SDL_DisplayFormat(tmp1);
	SDL_FreeSurface(tmp1);

	tmp2 = SDL_LoadBMP("map.bmp");
	acteurs->backg = SDL_DisplayFormat(tmp2);
	SDL_FreeSurface(tmp2);
	acteurs->camera.x = 0;
	acteurs->camera.y = 0;
	acteurs->camera.w = SCREEN_WIDTH;
	acteurs->camera.h = SCREEN_HEIGHT;

}
/*________________________________________________________________________________________*/
/*---fonction d initialisation de l hero---*/
void initializeHero(Hero* hero)
{
	SDL_Surface* tmp  , *tmp1  ;

	tmp = SDL_LoadBMP("jump_Right.bmp");
	hero->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));



	tmp1 = SDL_LoadBMP("v.bmp");
	hero->life_bar = SDL_DisplayFormat(tmp1);
	SDL_FreeSurface(tmp1);
	SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));


	//Indique l'état et la direction de notre héros
	hero->direction = RIGHT;
	hero->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	hero->frame_timer = TIME_BETWEEN_2_FRAMES;
	hero->frame_number = 0;

	/* Coordonnées de démarrage de notre héros */
	hero->x = 0 ;
	hero->y = 0 ;

	hero->x_life_bar = 14 ;
	hero->y_life_bar = 9 ;
	hero->w_life_bar = LIFE_BAR_WIDTH ;
	hero->h_life_bar = LIFE_BAR_HEIGHT ;

	hero->YSAUT = 60;

	hero->jump = NON;
	hero->ground = NON;
	hero->vies = 3 ;

}



/*________________________________________________________________________________________*/



/*---fontion pour afficher l'hero ---*//////////////////////////

void drawHero(Hero hero , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero.x - acteurs->camera.x;
dest.y = hero.y ;
/*SDL_Rect dest_life_bar ;
dest_life_bar.x = hero.x_life_bar - acteurs->camera.x;
dest_life_bar.y = hero.y_life_bar ;
dest_life_bar.w = LIFE_BAR_WIDTH ;
dest_life_bar.h = LIFE_BAR_HEIGHT  ;*/
int eng, x ;
SDL_Rect frame;
frame.x = hero.frame_number*PLAYER_WIDTH;
frame.y = 0;
frame.w = PLAYER_WIDTH;
frame.h = PLAYER_HEIGHT;


/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs->backg, &acteurs->camera, acteurs->screen, NULL);
SDL_BlitSurface(hero.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(hero.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero.sprite->format, 255, 255, 255));


/*SDL_BlitSurface(hero.life_bar , &frame , acteurs->screen , &dest_life_bar) ;
SDL_SetColorKey(hero.life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero.life_bar->format, 255, 255, 255));*/



}
/*__________________________________________________________________________
int enigme ( Acteurs *acteurs , Hero* hero)

{   char nom[6];
    int r=0,A=0;
    srand(time(NULL));

    FILE* fichier=NULL;
    FILE* fichierr=NULL;
    r=rand()%4+1;


    char chaine[256]="";
    char chainer[256]="";
    printf("1\n" );


    fichier=fopen("1.txt", "r");
    fichierr=fopen("1a.txt", "r");


int i =0;
while (fgets (chaine, 265, fichier ) != NULL && fgets (chainer, 1000, fichierr ) !=NULL)
{
  i++;
  if (i==r) {
break;
  }
}



printf("2\n" );


    SDL_Surface *texte = NULL, *fond = NULL, *rp =NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL, *police1 = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    int continuer = 1;
    printf("3\n" );
    TTF_Init();
    printf("4\n" );


  //  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
//    SDL_WM_SetCaption("GENERATION ALEATOIRE DE L ENIGME", NULL);
//    printf("fdsdfsdf\n" );

//background = IMG_Load("background.png");
    fond = IMG_Load("enigme.png");
    police = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 20);
    police1 = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 15);


printf("5\n" );

    texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
    rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);

    while (continuer)

    {
        SDL_FillRect( acteurs->screen, NULL, SDL_MapRGB(acteurs->screen->format, 255, 255, 255));


        position.x = 0;

        position.y = 0;
      //  SDL_BlitSurface(background, NULL, ecran, &position);

        SDL_BlitSurface(fond, NULL,  acteurs->screen, &position);


        position.x = 190;

        position.y = 252;

        SDL_BlitSurface(texte, NULL,  acteurs->screen, &position);
        position.x = 217;

        position.y = 370;

        SDL_BlitSurface(rp, NULL,  acteurs->screen, &position);

     SDL_Flip( acteurs->screen);
        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;
                case SDL_MOUSEBUTTONDOWN :
                if( (event.button.x>216 && event.button.x<288 && event.button.y>374 && event.button.y<391) )
             {A= 1 ; continuer = 0; return 1; ; break;}
             else if ( (event.button.x>321 && event.button.x<394 && event.button.y>374 && event.button.y<391) )
             {A = 0 ; continuer = 0; return 0; break;}
             else if ( (event.button.x>448 && event.button.x<533 && event.button.y>374 && event.button.y<393) )
             {A = 0 ; continuer = 0 ; return 0;break;}
        }

    }

printf("%d\n",A );
    TTF_CloseFont(police);

    TTF_Quit();


    SDL_FreeSurface(texte);

    SDL_Quit();


    return EXIT_SUCCESS;

}
*/
/*________________________________________________________________________________________*/



/*---fonction de deplacement de l hero---*/

void updatePlayer(Hero* hero , Acteurs* acteurs)
{
	int eng ;
	int resultat_de_collision_droite = 0,
	resultat_de_collision_gauche =0 ,
	resultat_de_collision_bas =0 ;

	hero->PLAYER_SPEED=12 ;



	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE)
		{



			if (acteurs->event.key.keysym.sym == SDLK_SPACE )
			{

			hero->PLAYER_SPEED += PLAYER_ACCELERATION ;

			}
			if(hero->etat == IMMOBILE || hero->etat == WALK_LEFT)
			{
				hero->etat = WALK_RIGHT;
			}
			if(hero->direction == LEFT)
				{
					hero->direction = RIGHT ;
				}
			hero->sprite = SDL_LoadBMP("run_Right.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));


			hero->x += hero->PLAYER_SPEED;
			//hero->x_life_bar += hero->PLAYER_SPEED;
			update_points_de_collision(hero) ;

			resultat_de_collision_droite = verification_collision_player_map_droite( acteurs , hero) ;

			if(resultat_de_collision_droite== Collision_droite)
			{

			hero->x -= hero->PLAYER_SPEED ;

			update_points_de_collision(hero) ;

			}

			if (hero->x + PLAYER_WIDTH >= Backg_W)
				{
					hero->x = Backg_W - PLAYER_WIDTH ;
				}




		}


		else if(acteurs->event.key.keysym.sym == SDLK_LEFT )
		{

			if(hero->etat == IMMOBILE || hero->etat == WALK_RIGHT)
			{
				hero->etat = WALK_LEFT;
			}
			if(hero->direction == RIGHT)
				{
					hero->direction = LEFT ;
				}
			hero->sprite = SDL_LoadBMP("run_Left.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x -= hero->PLAYER_SPEED ;

			update_points_de_collision(hero) ;

			resultat_de_collision_gauche = verification_collision_player_map_gauche( acteurs , hero) ;

			if(resultat_de_collision_gauche==Collision_gauche)
			{

			hero->x += hero->PLAYER_SPEED ;
			update_points_de_collision(hero) ;

			}


            if (hero->x < 0)
				{
					hero->x = 0 ;
				}
		}
	}
    if(acteurs->event.key.keysym.sym == SDLK_UP)
	{
		herojump(hero);
	}
    if(acteurs->event.type == SDL_KEYUP)
	{
		if(hero->etat != IMMOBILE)
		{
			hero->etat = IMMOBILE;
		}
	}

	resultat_de_collision_bas = verification_collision_player_map_bas(acteurs , hero);
	update_points_de_collision(hero);
	if(resultat_de_collision_bas == Collision_bas)
	{
		hero->ground = OUI;
		hero->YSAUT = 0;
	}
	if(resultat_de_collision_bas != Collision_bas && hero->jump == NON)
		hero->YSAUT = 10;

	if(hero->jump == OUI && hero->YSAUT < 0 )
		hero->YSAUT += GRAVITY;
	else
		hero->jump = NON;
	hero->y += hero->YSAUT;

}

void herojump(Hero* hero)
{
	if(hero->jump == NON && hero->ground == OUI)
	{
		hero->jump = OUI;
		hero->ground = NON;
		hero->YSAUT = -40;
		hero->y -= 13;
	}
}


/*________________________________________________________________________________________*/


//fonction pour annimer l'hero

void animationhero(Hero* hero, Acteurs acteurs)
{
	if(acteurs.event.type == SDL_KEYDOWN)
	{
		if(acteurs.event.key.keysym.sym == SDLK_LEFT || acteurs.event.key.keysym.sym == SDLK_RIGHT || acteurs.event.key.keysym.sym == SDLK_SPACE)
		{
			if(hero->frame_timer <= 0)
			{
				hero->frame_number++;
			if(hero->frame_number > MAXF-1)
				hero->frame_number = 0;
			}
		else
		hero->frame_timer--;

		}
	}

	if(acteurs.event.type == SDL_KEYUP)
	{
		if(hero->direction == RIGHT)
		{
			hero->frame_number = 0;
		}
		else if(hero->direction == LEFT)
		{
			hero->frame_number = MAXF-1;

		}
	}
}



/*________________________________________________________________________________________*/




/*---fonction pour faire le scrolling---*/

void centerScrollingOnPlayer(Hero *hero, Acteurs* acteurs)
{
	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE )
	{
		if((hero->x + PLAYER_WIDTH/2) > SCREEN_WIDTH/2)
			{
				hero->x_life_bar += hero->PLAYER_SPEED; ////*****
				acteurs->camera.x += hero->PLAYER_SPEED;
			}
		if(acteurs->camera.x > Backg_W - SCREEN_WIDTH)
			{
				hero->x_life_bar = Backg_W - SCREEN_WIDTH; ////*****
				acteurs->camera.x = Backg_W - SCREEN_WIDTH;
			}
	}
	else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
	{
				hero->x_life_bar -= hero->PLAYER_SPEED; ////*****
				acteurs->camera.x -= hero->PLAYER_SPEED;

		if((hero->x + PLAYER_WIDTH/2) > (Backg_W - SCREEN_WIDTH/2))
		{
			hero->x_life_bar = Backg_W - SCREEN_WIDTH; ////*****
			acteurs->camera.x = Backg_W - SCREEN_WIDTH;
		}

		if(acteurs->camera.x < 0)
			{
				acteurs->camera.x = 0;
			}
	}
	}
}





/*________________________________________________________________________________________*/


SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y)
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;

}

/*________________________________________________________________________________________*/


//pour mettre a jour les points de collision ! on 12 points de collision !!!


void update_points_de_collision(Hero* hero)
{

  //points a droite de l'hero

	hero->x1=hero->x + PLAYER_WIDTH ;
	hero->y1=hero->y ;

	hero->x2=  hero->x + PLAYER_WIDTH;
	hero->y2= hero->y + 100  ;


	hero->x3=hero->x + PLAYER_WIDTH ;
	hero->y3= hero->y + PLAYER_HEIGHT - 25 ;


	hero->x4=hero->x + PLAYER_WIDTH ;
	hero->y4= hero->y + 50  ;


	hero->x5=hero->x + PLAYER_WIDTH ;
	hero->y5= hero->y + 150  ;

	//points a gauche de l'hero

	hero->x6=  hero->x ;
	hero->y6=  hero->y ;

	hero->x7=  hero->x ;
	hero->y7=  hero->y + 100 ;

	hero->x8= hero->x  ;
	hero->y8=  hero->y + PLAYER_HEIGHT - 25;

	hero->x9=  hero->x ;
	hero->y9=  hero->y + 50 ;

	hero->x10=  hero->x ;
	hero->y10=  hero->y + 150 ;

	//points au milieu de l'hero

	hero->x11=  hero->x + 50 ;
	hero->y11=  hero->y ;

	hero->x12=  hero->x + 50 ;
	hero->y12=  hero->y + PLAYER_HEIGHT ;


}


/*________________________________________________________________________________________*/

//fonction de verification de collision entre le bachground du premier stage et l'hero ! cette fonction retourne 1 en cas de collision sinon 0


int verification_collision_player_map_droite(Acteurs* acteurs , Hero* hero)
{

SDL_Color color1 , color2 , color3 , color4 , color5 ;

int coll = 0;

color1=GetPixel (acteurs->backg_collision , hero->x1 , hero->y1) ;
color2=GetPixel (acteurs->backg_collision , hero->x2 , hero->y2) ;
color3=GetPixel (acteurs->backg_collision , hero->x3 , hero->y3) ;
color4=GetPixel (acteurs->backg_collision , hero->x4 , hero->y4) ;
color5=GetPixel (acteurs->backg_collision , hero->x5 , hero->y5) ;


if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255))
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) || ((color4.r==255)  &&  (color4.g==255)  &&  (color4.b==255))
	|| ((color5.r==255)  &&  (color5.g==255)  &&  (color5.b==255) ))
{
	coll = Collision_droite;
}

return coll;
}

int verification_collision_player_map_gauche(Acteurs* acteurs , Hero* hero)
{

SDL_Color color6 , color7 , color8 , color9 , color10 ;

int coll = 0;

color6=GetPixel (acteurs->backg_collision , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->backg_collision , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->backg_collision , hero->x8 , hero->y8) ;
color9=GetPixel (acteurs->backg_collision , hero->x9 , hero->y9) ;
color10=GetPixel (acteurs->backg_collision , hero->x10 , hero->y10) ;

if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) )
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) ) || ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) )
	 || ((color9.r==255)  &&  (color9.g==255)  &&  (color9.b==255) ) || ((color10.r==255)  &&  (color10.g==255)  &&  (color10.b==255)))
{
	coll = Collision_gauche;
}

return coll;
}

int verification_collision_player_map_top(Acteurs* acteurs , Hero* hero)
{

SDL_Color  color11  ;

int coll = 0;

color11=GetPixel (acteurs->backg_collision , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ))
{
	coll = Collision_top;
}

return coll;
}

int verification_collision_player_map_bas(Acteurs* acteurs , Hero* hero)
{

SDL_Color  color12 ;

int coll = 0;


color12=GetPixel (acteurs->backg_collision , hero->x12 , hero->y12) ;

if(((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
	coll = Collision_bas;
}

return coll;
}


/*________________________________________________________________________________________*/


/*---fonction d initialisation de l enemy---*/

void initializeEnemy(Enemy* enemy)
{
	SDL_Surface* tmp , *tmp2 , *tmp3  , *tmp4 , *tmp5 , *tmp6 , *tmp7 , *tmp8 ;

	tmp = SDL_LoadBMP("e1.bmp");
	enemy->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(enemy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite->format, 255, 255, 255));


	tmp2 = SDL_LoadBMP("e2.bmp");
	enemy->sprite2 = SDL_DisplayFormat(tmp2);
	SDL_FreeSurface(tmp2);
	SDL_SetColorKey(enemy->sprite2 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite2->format, 255, 255, 255));



	tmp3 = SDL_LoadBMP("e3.bmp");
	enemy->sprite3 = SDL_DisplayFormat(tmp3);
	SDL_FreeSurface(tmp3);
	SDL_SetColorKey(enemy->sprite3 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite3->format, 255, 255, 255));


    tmp4 = SDL_LoadBMP("e4.bmp");
	enemy->sprite4 = SDL_DisplayFormat(tmp4);
	SDL_FreeSurface(tmp4);
	SDL_SetColorKey(enemy->sprite4 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite4->format, 255, 255, 255));


	tmp5 = SDL_LoadBMP("e5.bmp");
	enemy->sprite5 = SDL_DisplayFormat(tmp5);
	SDL_FreeSurface(tmp5);
	SDL_SetColorKey(enemy->sprite5 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite5->format, 255, 255, 255));


	tmp6 = SDL_LoadBMP("e6.bmp");
	enemy->sprite6 = SDL_DisplayFormat(tmp6);
	SDL_FreeSurface(tmp6);
	SDL_SetColorKey(enemy->sprite6 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite6->format, 255, 255, 255));


	tmp7 = SDL_LoadBMP("e7.bmp");
	enemy->sprite7 = SDL_DisplayFormat(tmp7);
	SDL_FreeSurface(tmp7);
	SDL_SetColorKey(enemy->sprite7 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite7->format, 255, 255, 255));


	tmp8 = SDL_LoadBMP("e8.bmp");
	enemy->sprite8 = SDL_DisplayFormat(tmp8);
	SDL_FreeSurface(tmp8);
	SDL_SetColorKey(enemy->sprite8 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite8->format, 255, 255, 255));




	//Indique l'état et la direction de notre enemy
	enemy->direction = RIGHT;
	enemy->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	enemy->frame_timer = TIME_BETWEEN_2_FRAMES;
	enemy->frame_number = 0;

	/* Coordonnées de démarrage de notre enemies */
	enemy->x = 1516 ;
	enemy->y = 450 ;

	enemy->x2 = 3816 ;
	enemy->y2 = 450 ;

	enemy->x3 = 6000 ;
	enemy->y3 = 450 ;

    enemy->x4 = 7100 ;
	enemy->y4 = 450 ;

	enemy->x5 = 2000 ;
	enemy->y5 = 420 ;
	enemy->w5 = 208 ;
	enemy->h5 = 83 ;

	enemy->x6 = 5292 ;
	enemy->y6 = 420 ;
	enemy->w6 = 400 ;
	enemy->h6 = 80 ;

	enemy->x7 = 3470 ;
	enemy->y7 = 480 ;
	enemy->w7 = 200 ;
	enemy->h7 = 80 ;

	enemy->x8 = 4933 ;
	enemy->y8 = 480 ;
	enemy->w8 = 430 ;
	enemy->h8 = 80;





}


/*________________________________________________________________________________________*/



/*---fontion pour afficher l'enemy ---*//////////////////////////

void drawEnemy(Enemy enemy , Acteurs *acteurs)
{

 /*Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x - acteurs->camera.x;
dest.y = enemy.y ;

SDL_Rect frame;
frame.x = enemy.frame_number * ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite->format, 255, 255, 255));
SDL_Delay(15);

}


/*________________________________________________________________________________________*/


void drawEnemy2(Enemy enemy , Acteurs *acteurs)
{


SDL_Rect dest;
dest.x = enemy.x2 - acteurs->camera.x;
dest.y = enemy.y2 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;



SDL_BlitSurface(enemy.sprite2 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite2 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite2->format, 255, 255, 255));
SDL_Delay(15);

}


/*________________________________________________________________________________________*/


void drawEnemy3(Enemy enemy , Acteurs *acteurs)
{


SDL_Rect dest;
dest.x = enemy.x3 - acteurs->camera.x;
dest.y = enemy.y3 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;



SDL_BlitSurface(enemy.sprite3 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite3 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite3->format, 255, 255, 255));
SDL_Delay(15);

}


/*________________________________________________________________________________________*/

void drawEnemy4(Enemy enemy , Acteurs *acteurs)
{


SDL_Rect dest;
dest.x = enemy.x4 - acteurs->camera.x;
dest.y = enemy.y4 ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;



SDL_BlitSurface(enemy.sprite4 , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite4 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite4->format, 255, 255, 255));
SDL_Delay(15);

}


/*________________________________________________________________________________________*/




void animationEnemy(Enemy* enemy, Acteurs acteurs)
{
			if(enemy->frame_timer <= 0)
			{
				enemy->frame_number++;
			if(enemy->frame_number >MAXF_ENEMY-1)
				enemy->frame_number = 0;
			}
		else
		enemy->frame_timer--;
}



/*________________________________________________________________________________________*/


void intelligence_artificielle(Enemy *enemy, Acteurs acteurs , Hero* hero)
{

int d, d2 , d3 , d4 ,dh ,  resultat_collision_enemy1 , resultat_collision_enemy2 ,
resultat_collision_enemy3 , resultat_collision_enemy4  , resultat_collision_enemy5 ,
resultat_collision_enemy6 , resultat_collision_enemy7 , resultat_collision_enemy8;
SDL_Surface *tmp1 ;





  	/*	d = enemy->x - hero->x - PLAYER_WIDTH;
  		d2 = enemy->x2 - hero->x - PLAYER_WIDTH;
		d3 = enemy->x3 - hero->x - PLAYER_WIDTH;
		d4 = enemy->x4 - hero->x - PLAYER_WIDTH;
*/

  		resultat_collision_enemy1 = collision_player_enemy1(hero , enemy);
  		resultat_collision_enemy2 = collision_player_enemy2(hero , enemy);
  		resultat_collision_enemy3 = collision_player_enemy3(hero , enemy);
  		resultat_collision_enemy4 = collision_player_enemy4(hero , enemy);
  		resultat_collision_enemy5 = collision_player_enemy5(hero , enemy);
  		resultat_collision_enemy6 = collision_player_enemy6(hero , enemy);
  		resultat_collision_enemy7 = collision_player_enemy7(hero , enemy);
  		resultat_collision_enemy8 = collision_player_enemy8(hero , enemy);

			d = hero->x-(enemy->x+ENEMY_Width);
			dh = hero->y-(enemy->y+ENEMY_Height);
			  		d2 = hero->x-(enemy->x2+ENEMY_Width);
					d3 = hero->x-(enemy->x3+ENEMY_Width);
					d4 = hero->x-(enemy->x4+ENEMY_Width);





	/*	if(d<500 && d> -200)
		{
     if(d<500)
		 {
			enemy->x -= 4 ;
			animationEnemy(enemy,  acteurs);
		}
else if (d> -200) {
	enemy->x += 4 ;
	animationEnemy(enemy,  acteurs);
}

	}
*/
if(d>10 && d<200)
		{
			enemy->x += 4 ;
			//enemy->y -=hero->y;
			animationEnemy(enemy,  acteurs);
		//	animationEnemy2(enemy,  acteurs);

		}
		else if ( d > -500 && d< -200 /*&& dh<-10*/)
		{
			enemy->x -=4;
			//enemy->y -=hero->y;
			animationEnemy(enemy, acteurs);
		}
		else if( resultat_collision_enemy1==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
	initializeEnemy(enemy) ;
			drawEnemy(*enemy , &acteurs) ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}






//enemy number 2 :

if(d2>10 && d2<200)
		{
			enemy->x2 += 10 ;
			//enemy->y -=hero->y;
			animationEnemy(enemy,  acteurs);
		//	animationEnemy2(enemy,  acteurs);

		}
		else if ( d2 > -500 && d2< -200 /*&& dh<-10*/)
		{
			enemy->x2 -=10;
			//enemy->y -=hero->y;
			animationEnemy(enemy, acteurs);
		}
		else if( resultat_collision_enemy2==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy2(*enemy , &acteurs) ;


			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}



		}




//enemy number 3 :

if(d3>10 && d3<200)
		{
			enemy->x3 += 10 ;
			//enemy->y -=hero->y;
			animationEnemy(enemy,  acteurs);
		//	animationEnemy2(enemy,  acteurs);

		}
		else if ( d3 > -500 && d3< -200 /*&& dh<-10*/)
		{
			enemy->x3 -=10;
			//enemy->y -=hero->y;
			animationEnemy(enemy, acteurs);
		}
		else if( resultat_collision_enemy3==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy3(*enemy , &acteurs) ;


			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}



		}




//enemy number 4 :

if(d4>10 && d4<200)
		{
			enemy->x4 += 10 ;
			//enemy->y -=hero->y;
			animationEnemy(enemy,  acteurs);
		//	animationEnemy2(enemy,  acteurs);

		}
		else if ( d4 > -600 && d4< -50 /*&& dh<-10*/)
		{
			enemy->x4 -=10;
			//enemy->y -=hero->y;
			animationEnemy(enemy, acteurs);
		}
		else if( resultat_collision_enemy4==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			initializeEnemy(enemy) ;
			drawEnemy4(*enemy , &acteurs) ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}





//enemy number 5 :

	/*	if( resultat_collision_enemy5==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			//initializeEnemy(enemy) ;
			//drawEnemy4(*enemy , &acteurs) ;
			hero->x = 613 ;
			hero->y = 50 ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}
*/



//enemy number 6 :

		if( resultat_collision_enemy6==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			//initializeEnemy(enemy) ;
			//drawEnemy4(*enemy , &acteurs) ;
			hero->x = 2163 ;
			hero->y = 50 ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}





//enemy number 7 :

		if( resultat_collision_enemy7==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			//initializeEnemy(enemy) ;
			//drawEnemy4(*enemy , &acteurs) ;
			hero->x = 3326 ;
			hero->y = 87 ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}







//enemy number 8 :

		if( resultat_collision_enemy8==1 )
		{
			printf("hero a perdu une vie a cause d un ennemie \n");
			hero->vies-- ;
			printf("vie hero == %d \n",hero->vies );
			//initializeEnemy(enemy) ;
			//drawEnemy4(*enemy , &acteurs) ;
			hero->x = 5140 ;
			hero->y = 40 ;

			if (hero->vies == 2)
			{
				tmp1 = SDL_LoadBMP("v1.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


			if (hero->vies == 1)
			{
				tmp1 = SDL_LoadBMP("v2.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}

			if (hero->vies == 0)
			{
				tmp1 = SDL_LoadBMP("v3.bmp");
				hero->life_bar = SDL_DisplayFormat(tmp1);
				SDL_FreeSurface(tmp1);
				SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

			}


		}





}


/*________________________________________________________________________________________*/


int collision_player_enemy1(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


int collision_player_enemy2(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y2 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x2 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y2)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x2)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/

int collision_player_enemy3(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y3 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x3 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y3)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x3)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/

int collision_player_enemy4(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y4 + ENEMY_Height)
                return 0;
        if(hero->x >= enemy->x4 + ENEMY_Width)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y4)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x4)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


void draw_life_bar(Hero *hero  , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero->x_life_bar - acteurs->camera.x;
dest.y = hero->y_life_bar ;


/*SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;*/

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(hero->life_bar , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));

}


/*________________________________________________________________________________________*/

void drawEnemy5_fixe(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x5 - acteurs->camera.x;
dest.y = enemy.y5 ;



/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite5 , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite5 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite5->format, 255, 255, 255));
//SDL_Delay(15);

}



/*________________________________________________________________________________________*/


int collision_player_enemy5(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y5 + enemy->h5)
                return 0;
        if(hero->x >= enemy->x5 + enemy->w5)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y5)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x5)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


void drawEnemy6_fixe(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x6 - acteurs->camera.x;
dest.y = enemy.y6 ;



/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite6 , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite6 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite6->format, 255, 255, 255));
//SDL_Delay(15);

}



/*________________________________________________________________________________________*/


int collision_player_enemy6(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y6 + enemy->h6)
                return 0;
        if(hero->x >= enemy->x6 + enemy->w6)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y6)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x6)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


void drawEnemy7_fixe(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x7 - acteurs->camera.x;
dest.y = enemy.y7 ;



/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite7 , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite7 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite7->format, 255, 255, 255));
//SDL_Delay(15);

}



/*________________________________________________________________________________________*/


int collision_player_enemy7(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y7 + enemy->h7)
                return 0;
        if(hero->x >= enemy->x7 + enemy->w7)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y7)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x7)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/


void drawEnemy8_fixe(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x8 - acteurs->camera.x;
dest.y = enemy.y8 ;



/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite8 , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite8 , SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite8->format, 255, 255, 255));
//SDL_Delay(15);

}



/*________________________________________________________________________________________*/


int collision_player_enemy8(Hero *hero , Enemy *enemy)
{
        if(hero->y >= enemy->y8 + enemy->h8)
                return 0;
        if(hero->x >= enemy->x8 + enemy->w8)
                return 0;
        if(hero->y + PLAYER_HEIGHT <= enemy->y8)
                return 0;
        if(hero->x + PLAYER_WIDTH <= enemy->x8)
                return 0;
        return 1;
}


/*________________________________________________________________________________________*/

void stage_1()
{

  Uint32 start ;
  const int FPS= 30;
int score=0;

  Acteurs acteurs;
  Boutons boutons;
  Hero hero ;
  Enemy enemy ;




 //SDL_ShowCursor(SDL_DISABLE);

/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "THE MYSTERIOUS ISLAND", NULL );

    initializeHero(&hero);
    initializeEnemy(&enemy);
    initialisation(&acteurs);
    update_points_de_collision(&hero);


    drawHero(hero, &acteurs);
    drawEnemy(enemy , &acteurs);
    draw_life_bar(&hero  , &acteurs);



int carryon = 1;
while(carryon)
{


	    start=SDL_GetTicks();


	    if (hero.vies == 0)
	    {

	    carryon=0 ;

	    }
int eng =0;
		intelligence_artificielle(&enemy,acteurs ,&hero);

		SDL_PollEvent(&acteurs.event);

		animationhero(&hero, acteurs);

		updatePlayer(&hero , &acteurs) ;

		centerScrollingOnPlayer(&hero, &acteurs);
		printf("%d\n",hero.x );
		drawHero(hero , &acteurs) ;
		drawEnemy(enemy , &acteurs) ;

		drawEnemy2(enemy , &acteurs) ;

		drawEnemy3(enemy , &acteurs) ;

		drawEnemy4( enemy ,  &acteurs) ;

		drawEnemy5_fixe(enemy , &acteurs);

		drawEnemy6_fixe(enemy , &acteurs);

		drawEnemy7_fixe(enemy , &acteurs);

		drawEnemy8_fixe(enemy , &acteurs);
		      draw_life_bar(&hero  , &acteurs);
					if (hero.x >= 800 && hero.x<810 || hero.x >= 1600 && hero.x<1610 || hero.x >= 2400 && hero.x<2410)
							{
								eng =enigme(&acteurs ,&hero);
 if(eng == 1)
 {
	 score +=50;
 }
 else score -=20;
								printf("qdqdqdqdqddazdqdqdqdqsdqdqdadq %d\n",eng );

hero.x+=PLAYER_ACCELERATION;
							}
		SDL_Flip(acteurs.screen);
	switch(acteurs.event.type)
	{
		case SDL_QUIT:
             carryon = 0;
    	case SDL_KEYDOWN:
			if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
				{
					carryon= 0;
				}
			break;

	}

/*if ( 1000/FPS > SDL_GetTicks()-start )
		{
			SDL_Delay( 1000/FPS - (SDL_GetTicks()-start)) ;
		}*/

}



printf("score %d\n",score );
    //LIB
	SDL_Quit();


}
