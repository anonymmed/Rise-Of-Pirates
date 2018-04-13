#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef enum Type_s
{
	MAP, PLATFORM
}Type;

typedef struct Background_s
{
	SDL_Surface* mask;
	SDL_Surface* sprite;
	SDL_Rect pos;
	Type type;
}Background;

typedef struct Background_config_s
{
	char* mask;
	char* sprite;
	Type type;
}Background_config;
#include "personnage.h"

Background Init_Background(Background_config * conf);
void Afficher_Background(Background* b, Heros* h, SDL_Surface* screen);
void Scroll(Background* b, Heros* h, SDL_Surface* screen);

#endif 