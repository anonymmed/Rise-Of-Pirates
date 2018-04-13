#include "menu.h"
#include "principal_menu_configuration.h"
#include "personnage.h"
#include "collision.h"
#include "background.h"

static void action1(void* contex, SDL_Surface * screen)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
	Heros_config heros_config;
	heros_config.player = REVENGER;

    char * posistions[8];
	posistions[0] = "img/personnages/revenger/1.png";
    posistions[1] = "img/personnages/revenger/2.png";
    posistions[2] = "img/personnages/revenger/3.png";
    posistions[3] = "img/personnages/revenger/4.png";
    posistions[4] = "img/personnages/revenger/5.png";
    posistions[5] = "img/personnages/revenger/6.png";
    posistions[6] = "img/personnages/revenger/7.png";
    posistions[7] = "img/personnages/revenger/8.png";
    heros_config.position = posistions;
	Heros heros = Init_Heros(&heros_config);
	Background_config background_config;
	background_config.type = PLATFORM;
	background_config.sprite = "img/stages/volcano/mask.png";
	background_config.mask   = "img/stages/volcano/mask.png";
	Background background = Init_Background(&background_config);

	int quit = 0;
    int i = 0;
	SDL_Event event;
    Afficher_Personnage(&heros.personnage, screen);
	Afficher_Background(&background, &heros,  screen);
	while(!quit)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN :
			{
				deplacer_clavier(&background, &heros, event.key.keysym.sym,screen);
                Animer_personnage(&heros.personnage, &i);
				break;
			}
            Afficher_Personnage(&heros.personnage, screen);
			Afficher_Background(&background, &heros,  screen);
		}
	}
}

static void action2(void* contex, SDL_Surface * screen)
{
	printf("action2\n");
}

static void action3(void* contex, SDL_Surface * screen)
{
	printf("action3\n");
}

static void action4(void* contex, SDL_Surface * screen)
{
	printf("action4\n");
}

static void action5(void* contex, SDL_Surface * screen)
{
	Mix_Music * goodbye = Mix_LoadMUS("sound/menu/goodbye.mp3");
	Mix_PlayMusic(goodbye, 1);
	SDL_Delay(1000);
	SDL_Quit();
	exit(0);
}

int main()
{
	//
	SDL_Init(SDL_INIT_EVERYTHING);
	//
	IMG_Init(IMG_INIT_PNG);
	//
	TTF_Init();
	//
	SDL_Surface * screen = SDL_SetVideoMode(800, 600, 32,  SDL_HWSURFACE);
	//
	SDL_WM_SetCaption("My Game Menu Test", NULL);
	//
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	//
	VISION_MENU_CONFIG config;
	//
	config.screen = screen;
	//
	ACTIONS_DEFINITION
	//
	SOUND_CONFIGURATION
	//
	BUTTONS_IMAGES_DEFINITION
	//
	VISION_MENUE menu = VISION_MENUE_create(&config);
	//
	VISION_MENUE_print(&menu);
	//
	VISION_MENUE_free(&menu);
	//
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	return 0;
}
