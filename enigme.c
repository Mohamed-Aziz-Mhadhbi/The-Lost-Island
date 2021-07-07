
#include "enigme.h"
#include <math.h>

int enigme (Acteurs *acteurs , Hero* hero)

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


    SDL_Surface  *texte = NULL, *fond = NULL, *rp =NULL, *background = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL, *police1 = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    int continuer = 1;

    printf("3\n" );

  //  SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    printf("4\n" );


  //  acteurs->screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  //  SDL_WM_SetCaption("GENERATION ALEATOIRE DE L ENIGME", NULL);
    printf("fdsdfsdf\n" );

//background = IMG_Load("background.png");
    fond = IMG_Load("enigme.png");
    police = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 20);
    police1 = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 15);


printf("5\n" );

    texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
    rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);

    while (continuer)

    {
        //SDL_FillRect(acteurs->screen, NULL, SDL_MapRGB(acteurs->screen->format, 255, 255, 255));


        position.x = 0;

        position.y = 0;
      //  SDL_BlitSurface(background, NULL, acteurs->screen, &position);

        SDL_BlitSurface(fond, NULL, acteurs->screen, &position);


        position.x = 190;

        position.y = 252;

        SDL_BlitSurface(texte, NULL, acteurs->screen, &position);
        position.x = 217;

        position.y = 370;

        SDL_BlitSurface(rp, NULL, acteurs->screen, &position);

        SDL_Flip(acteurs->screen);
        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;
                case SDL_MOUSEBUTTONDOWN :
                if( (event.button.x>216 && event.button.x<288 && event.button.y>374 && event.button.y<391) )
             { if (r==2) {
               A= 1 ; continuer = 0 ; return A; break; }
               else {A= 1 ; continuer = 0;return A; break;}
             }
             else if ( (event.button.x>321 && event.button.x<394 && event.button.y>374 && event.button.y<391) )
             {if (r==4) {
               A= 1 ; continuer = 0;return A; break; }
               else {A= 1 ; continuer = 0;return A; break;}
             }
             else if ( (event.button.x>448 && event.button.x<533 && event.button.y>374 && event.button.y<393) )
             {if (r==1 || r==3) {
               A= 1 ; continuer = 0;return A; break; }
               else {A= 1 ; continuer = 0;return A; break;}}
        }

    }

printf("%d\n",A );
    TTF_CloseFont(police);

    TTF_Quit();


    SDL_FreeSurface(texte);

    SDL_Quit();


    return EXIT_SUCCESS;

}
int enigme1 (Acteurs *acteurs , Hero* hero)
{  int A, B, C;
  double D,x,x1,r1,r2;
      char chaine[256]="";
      char chainer[256]="";
      char chainerr[256]="";
      char chainerrr[256]="";
      char chainerrrr[256]="";
      SDL_Surface  *texte = NULL, *fond = NULL, *rp =NULL ,*rp1 =NULL,*rp2 =NULL,*rp3 =NULL, *background = NULL;
      SDL_Rect position;
      SDL_Event event;
      TTF_Font *police = NULL, *police1 = NULL;
      SDL_Color couleurNoire = {0, 0, 0};
      srand(time(NULL));
      int continuer = 1;
      printf("3\n" );
    //  SDL_Init(SDL_INIT_VIDEO);
      TTF_Init();
      printf("4\n" );
    //  acteurs->screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    //  SDL_WM_SetCaption("GENERATION ALEATOIRE DE L ENIGME", NULL);
      printf("fdsdfsdf\n" );
  //background = IMG_Load("background.png");
      fond = IMG_Load("enigme.png");
      police = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 20);
      police1 = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 15);
      A=rand()%90+1;
      B=rand()%100+1;
      C=rand()%30+1;
      r1=rand()%30+1;
      r2=rand()%30+1;
      sprintf(chaine,"%d x² + %d x +%d",A,B,C);
      sprintf(chainerrr,"%.4f",r1);
      sprintf(chainerrrr,"%.4f",r2);


  printf("5\n" );
  /* Calcul des solutions réelles d'une équation du second degré */

  /* Calcul du discriminant b^2-4ac */
  D = pow(B,2) - 4.0*A*C;
  /* Distinction des différents cas */
  if (A==0 && B==0 && C==0) /* 0x = 0 */
  		printf("Tout réel est une solution de cette équation.\n");
  else if (A==0 && B==0)  /* Contradiction: c # 0 et c = 0 */
  		printf("Cette équation ne possède pas de solutions.\n");
  else if (A==0) /* bx + c = 0 */
     {
      printf("La solution de cette équation du premier degré est :\n");
      printf(" x = %.4f\n", (double)C/B);
      x=(double)C/B;
      sprintf(chainer,"%.4f",x);
     }
  else if (D<0)  /* b^2-4ac < 0 */
      printf("Cette équation n'a pas de solutions réelles.\n");
  else if (D==0) /* b^2-4ac = 0 */
     {
      printf("Cette équation a une seule solution réelle :\n");
      printf(" x =  %.4f\n", (double)-B/(2*A));
      x=(double)-B/(2*A);
      sprintf(chainer,"%.4f",x);
     }
  else /* b^2-4ac > 0 */
     {
      printf("Les solutions réelles de cette équation sont :\n");
      printf(" x1 = %.4f\n", (-B+sqrt(D))/(2*A));
      printf(" x2 = %.4f\n", (-B-sqrt(D))/(2*A));
      x=(-B+sqrt(D))/(2*A);
      x1= (-B-sqrt(D))/(2*A);
      sprintf(chainer,"%.4f",x);
      sprintf(chainerr,"%.4f",x1);

    //  strcat sprintf
     }
      texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
      rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);
      rp1 = TTF_RenderText_Blended(police1,chainerr, couleurNoire);
      rp2 = TTF_RenderText_Blended(police1,chainerrr, couleurNoire);
      rp3 = TTF_RenderText_Blended(police1,chainerrrr, couleurNoire);

      while (continuer)

      {
      //    SDL_FillRect(acteurs->screen, NULL, SDL_MapRGB(acteurs->screen->format, 255, 255, 255));


          position.x = 0;

          position.y = 0;
        //  SDL_BlitSurface(background, NULL, acteurs->screen, &position);

          SDL_BlitSurface(fond, NULL, acteurs->screen, &position);


          position.x = 190;

          position.y = 252;

          SDL_BlitSurface(texte, NULL, acteurs->screen, &position);
          position.x = 217;

          position.y = 370;

          SDL_BlitSurface(rp, NULL, acteurs->screen, &position);
          position.x = 217;

          position.y = 385;

          SDL_BlitSurface(rp1, NULL, acteurs->screen, &position);
          position.x = 321;

          position.y = 370;

          SDL_BlitSurface(rp2, NULL, acteurs->screen, &position);
          position.x = 448;

          position.y = 370;

          SDL_BlitSurface(rp3, NULL, acteurs->screen, &position);

          SDL_Flip(acteurs->screen);
          SDL_WaitEvent(&event);

          switch(event.type)

          {

              case SDL_QUIT:

                  continuer = 0;

                  break;
                  case SDL_MOUSEBUTTONDOWN :
                  if( (event.button.x>216 && event.button.x<288 && event.button.y>374 && event.button.y<391) )
               {A= 1 ; continuer = 0;return A; break;}
               else if ( (event.button.x>321 && event.button.x<394 && event.button.y>374 && event.button.y<391) )
               {A = 0 ; continuer = 0; return A;break;}
               else if ( (event.button.x>448 && event.button.x<533 && event.button.y>374 && event.button.y<393) )
               {A = 0 ; continuer = 0 ;return A;break;}
          }

      }
      TTF_CloseFont(police);

      TTF_Quit();


      SDL_FreeSurface(texte);
}
int engimme(Acteurs *acteurs , Hero* hero)
{


int eng,r ;
srand(time(NULL));
r=rand()%2+1;
printf("vsddfd %d\n",r );
if (r==1)
{
  eng = enigme(&acteurs ,& hero);
  return eng ;

}
else {
eng = enigme1(&acteurs ,&hero);
return eng ;
}
}
