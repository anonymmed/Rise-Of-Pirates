#ifndef COLLISON_H_
#define COLLISON_H_

#include "personnage.h"

typedef enum Collision_e
{
	NO, COIN, OBSTACLE, TRAP
}Collision;

int check_collision (Personnage *p1, Personnage *p2);
SDL_Color GetPixel (SDL_Surface *pSurface, int x, int y);
int collision_parfaite (Background *background, Personnage * perso, Direction direction);

#endif