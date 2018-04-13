#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef enum Direction_s
{
	STOP, RIGHT, LEFT, UP, DOWN
}Direction;

typedef enum Player_s
{
	BANDITOU, SERA, REVENGER, CASTRO, SPIDROU
}Player;

typedef struct Personnage_s
{
	SDL_Surface* sprite;
	SDL_Surface* position[8];
	SDL_Rect pos;
	Direction direction;
	int sante;
	int power;
}Personnage;

typedef struct Heros_s
{
	Player player;
	Personnage personnage;
	int score;
	int vie ;
}Heros;

typedef struct Heros_config_s
{
	Player player;
    char ** position;
}Heros_config;

#include "background.h"

Heros Init_Heros(Heros_config* conf);
void Deplacer_Personnage(Personnage* p, Direction direction);
void deplacer_clavier(Background* background, Heros* heros, SDLKey key, SDL_Surface* screen);
void Afficher_Personnage(Personnage * p, SDL_Surface* screen);
void Animer_personnage(Personnage * p, int * i);


#endif
