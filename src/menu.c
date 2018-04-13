#include "menu.h"


VISION_MENUE VISION_MENUE_create(VISION_MENU_CONFIG * config)
{
	//
	VISION_MENUE menu;
	//
	menu.screen = config->screen;
	//
	menu.buttons_number = config->buttons_number;
	//
	menu.buttons_actions = config->buttons_actions;
	//
	menu.buttons = (SDL_Surface**)malloc(menu.buttons_number * sizeof(SDL_Surface*));
	menu.selected_buttons = (SDL_Surface**)malloc(menu.buttons_number * sizeof(SDL_Surface*));
	//
	menu.beep_sound = Mix_LoadWAV(config->beep_sound);
	menu.click_sound = Mix_LoadWAV(config->click_sound);
	menu.background_sound = Mix_LoadMUS(config->background_sound);
	//
	menu.background = IMG_Load(config->background_image);
	int i;
	for(i = 0; i < menu.buttons_number; i++)
	{
		menu.buttons[i] = IMG_Load(config->buttons_images[i]);
		menu.selected_buttons[i] = IMG_Load(config->selected_buttons_images[i]);
	}
	return menu;
}

void VISION_MENUE_print(VISION_MENUE * menu)
{
	///
	TTF_Font *police = NULL;
	SDL_Color couleurNoire = {0, 0, 0};

	police = TTF_OpenFont("fonts/angelina.ttf", 60);
	SDL_Surface* texte = TTF_RenderText_Blended(police, "Rise Of Pirates", couleurNoire);
	SDL_Rect positiontexte;
	positiontexte.x = 400 - texte->w/2;
	positiontexte.y = 20;


	TTF_CloseFont(police);
	//
	SDL_Rect position;
	position.x = 10;
	position.y = 10;
	int i;
	SDL_FillRect(menu->screen, 0, SDL_MapRGB(menu->screen->format, 0, 0, 0));
	SDL_BlitSurface(texte, NULL, menu->screen, &positiontexte);
	SDL_BlitSurface(menu->background, NULL, menu->screen, NULL);
	for(i = 0; i < menu->buttons_number; i++)
	{
		SDL_BlitSurface(menu->buttons[i], NULL, menu->screen, &position);
		position.y += (menu->buttons[i]->h + 20);
	}
	SDL_Flip(menu->screen);
	//
	int button_selected = 0;
	SDL_Event event;
	int play_menu =1;
	Mix_PlayMusic(menu->background_sound, -1);
	while(play_menu==1)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym == SDLK_UP)
				{
					Mix_PlayChannel(-1, menu->beep_sound, 0);
					button_selected--;
					if(button_selected < 0)
					{
						button_selected = (menu->buttons_number)-1;
					}
				}
				else if(event.key.keysym.sym == SDLK_DOWN)
				{
					Mix_PlayChannel(-1, menu->beep_sound, 0);
					button_selected++;
					if(button_selected >= menu->buttons_number)
					{
						button_selected = 0;
					}
				}
				else if(event.key.keysym.sym == SDLK_RETURN)
				{
					Mix_PlayChannel(-1, menu->click_sound, 0);
					menu->buttons_actions[button_selected].action(menu->buttons_actions[button_selected].contex, menu->screen);
				}
				break;
			}
			case SDL_MOUSEMOTION :
			{
				for(i = 0 ; i < menu->buttons_number; i++)
				{
					if(event.motion.y >= i * (menu->buttons[i]->h +20 )  &&
					   event.motion.y <= (i+1) * (menu->buttons[i]->h + 20) &&
					   button_selected != i )
					{
						Mix_PlayChannel(-1, menu->beep_sound, 0);
						button_selected = i;
						break;
					}
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					Mix_PlayChannel(-1, menu->click_sound, 0);
					menu->buttons_actions[button_selected].action(menu->buttons_actions[button_selected].contex, menu->screen);
				}
				else if(event.jball.ball == SDL_BUTTON_WHEELDOWN)
				{
					Mix_PlayChannel(-1, menu->beep_sound, 0);
					button_selected++;
					if(button_selected >= menu->buttons_number)
					{
						button_selected = 0;
					}
				}
				else if(event.jball.ball == SDL_BUTTON_WHEELUP)
				{
					Mix_PlayChannel(-1, menu->beep_sound, 0);
					button_selected--;
					if(button_selected < 0)
					{
						button_selected = menu->buttons_number-1;
					}
				}
				break;
			}
			case SDL_QUIT :
			{
				exit(0);
			}
		}
		position.x = 10;
		position.y = 10;
		SDL_FillRect(menu->screen, 0, SDL_MapRGB(menu->screen->format, 0, 0, 0));
		SDL_BlitSurface(menu->background, NULL, menu->screen, NULL);
		SDL_BlitSurface(texte, NULL, menu->screen, &positiontexte);
		for(i = 0; i < menu->buttons_number; i++)
		{
			if(button_selected == i)
			{
				SDL_BlitSurface(menu->selected_buttons[i], NULL, menu->screen, &position);
			}
			else
			{
				SDL_BlitSurface(menu->buttons[i], NULL, menu->screen, &position);
			}
			position.y += (menu->buttons[i]->h + 20);
		}
		SDL_Flip(menu->screen);
	}
}

void VISION_MENUE_free(VISION_MENUE * menu)
{
	//
	int i;
	//
	Mix_FreeChunk(menu->beep_sound);
	Mix_FreeChunk(menu->click_sound);
	Mix_FreeMusic(menu->background_sound);
	//
	SDL_FreeSurface(menu->background);
	//
	for(i = 0; i < menu->buttons_number; i++)
	{
		SDL_FreeSurface(menu->buttons[i]);
		SDL_FreeSurface(menu->selected_buttons[i]);
	}
	//
	free(menu->buttons);
	free(menu->selected_buttons);
}
