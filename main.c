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
#include "help.h"


void menu();
void intro_game_play();
void Map ();
void help();

int main(int argc,char** argv)
{

    SDL_Init( SDL_INIT_VIDEO );

    fenetre = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF/*|SDL_NOFRAME*/);
    SDL_WM_SetCaption("THE LOST ISLAND", NULL);
    menu();
    return 0;
}
