
#include "personnage.h"
#include "collision.h"
void Animer_personnage(Personnage * p, int * i)
{
    if(*i>4)
    {
		*i = 0;
	}
    p->sprite = p->position[*i];
    (*i)++;
}

void Afficher_Personnage(Personnage * p, SDL_Surface* screen)
{
	SDL_BlitSurface(p->sprite, NULL, screen , &p->pos);
	SDL_Flip(screen);
}

void deplacer_clavier(Background* background, Heros* heros, SDLKey key, SDL_Surface* screen)
{
    
	switch(key)
	{
		case SDLK_UP:
		{
			//if(collision_parfaite(background, &heros->personnage, UP) != OBSTACLE)
			//{
				Deplacer_Personnage(&heros->personnage, UP);
			//}
			break;
		}
		case SDLK_DOWN:
		{
			//if(collision_parfaite(background, &heros->personnage, DOWN) != OBSTACLE)
			//{
				Deplacer_Personnage(&heros->personnage, DOWN);
			//}
			break;
		}
		case SDLK_RIGHT:
		{
			//if(collision_parfaite(background, &heros->personnage, RIGHT) != OBSTACLE)
			//{
				Deplacer_Personnage(&heros->personnage, RIGHT);
			//}
			break;
		}
		case SDLK_LEFT:
		{
			//if(collision_parfaite(background, &heros->personnage, LEFT) != OBSTACLE)
			//{
				Deplacer_Personnage(&heros->personnage, LEFT);
			//}
			break;
		}
	}
}

void Deplacer_Personnage(Personnage* p, Direction direction)
{
    switch(direction)
    {
        case LEFT : 
        {
            (p->pos.x)++;
            break;
        }
        case RIGHT : 
        {
            (p->pos.x)--;
            break;
        }
        case UP : 
        {
            (p->pos.y)++;
            break;
        }
        case DOWN : 
        {
            (p->pos.y)--;
            break;
        }
    }
}

Heros Init_Heros(Heros_config* conf)
{
    int i;
    Heros h;
    for(i = 0; i < 8; i++)
    {
        h.personnage.position[i] = IMG_Load(conf->position[i]);
    }
    h.personnage.sprite = h.personnage.position[0];
    h.personnage.pos.x = 250;
    h.personnage.pos.y = 300;
    h.personnage.sante = 100;
    h.personnage.power = 30;
    return h;
}
