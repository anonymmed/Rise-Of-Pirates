#ifndef MENU_H_
#define MENU_H_

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


//
typedef void (*VISION_MENUE_ACTION_DELEGATE)(void* contex, SDL_Surface * screen);

//
typedef struct vision_menu_action_s
{
	void * contex;							//
	VISION_MENUE_ACTION_DELEGATE action;	//
}VISION_MENUE_ACTION;

//
typedef struct vision_menu_config_s
{
	int						buttons_number;				//
	char *					beep_sound;					//
	char *					click_sound;				//
	char *					background_sound;			//
	char *					background_image;			//
	char **					buttons_images;				//
	char **					selected_buttons_images;	//
	SDL_Surface *			screen;						//
	VISION_MENUE_ACTION *	buttons_actions;			//
}VISION_MENU_CONFIG;

//
typedef struct vision_menu_s
{
	int						buttons_number;		//
	Mix_Chunk *				beep_sound;			//
	Mix_Chunk *				click_sound;		//
	Mix_Music *				background_sound;	//
	SDL_Surface **			buttons;			//
	SDL_Surface **			selected_buttons;	//
	SDL_Surface *			screen;				//
	SDL_Surface *			background;			//
	VISION_MENUE_ACTION *	buttons_actions;	//
}VISION_MENUE;

//
VISION_MENUE VISION_MENUE_create(VISION_MENU_CONFIG * config);
//
void 		 VISION_MENUE_print(VISION_MENUE * menu);
//
void 		 VISION_MENUE_free(VISION_MENUE * menu);

#endif // MENU_H_
