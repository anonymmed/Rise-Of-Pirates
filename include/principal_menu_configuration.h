#ifndef PRINCIPAL_MENU_CONFIGURATION_H_
#define PRINCIPAL_MENU_CONFIGURATION_H_

#include "menu.h"
														
	
#define BUTTONS_NUMBER 5

#define ACTIONS_DEFINITION							\
	VISION_MENUE_ACTION actions[BUTTONS_NUMBER];	\
	actions[0].action = action1;					\
	actions[0].contex = NULL;						\
	actions[1].action = action2;					\
	actions[1].contex = NULL;						\
	actions[2].action = action3;					\
	actions[2].contex = NULL;						\
	actions[3].action = action4;					\
	actions[3].contex = NULL;						\
	actions[4].action = action5;					\
	actions[4].contex = NULL;						\
	config.buttons_actions = actions;				\

#define BUTTONS_IMAGES_DEFINITION						\
	config.background_image = "img/menu/background.jpg";\
	char * imgs[BUTTONS_NUMBER];						\
	imgs[0] = "img/menu/NewGame.png";					\
	imgs[1] = "img/menu/Continue.png";					\
	imgs[2] = "img/menu/Help.png";						\
	imgs[3] = "img/menu/Options.png";					\
	imgs[4] = "img/menu/Exit.png";						\
	char * s_imgs[BUTTONS_NUMBER];						\
	s_imgs[0] = "img/menu/NewGame_selected.png";		\
	s_imgs[1] = "img/menu/Continue_selected.png";		\
	s_imgs[2] = "img/menu/Help_selected.png";			\
	s_imgs[3] = "img/menu/Options_selected.png";		\
	s_imgs[4] = "img/menu/Exit_selected.png";			\
	config.buttons_images  = imgs;						\
	config.selected_buttons_images = s_imgs;			\
	config.buttons_number  = BUTTONS_NUMBER;			\

#define SOUND_CONFIGURATION									\
	config.beep_sound = "sound/menu/beep.wav";				\
	config.click_sound = "sound/menu/click.wav";			\
	config.background_sound = "sound/menu/background.mp3";	\

#endif // PRINCIPAL_MENU_CONFIGURATION_H_
