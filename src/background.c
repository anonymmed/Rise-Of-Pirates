#include "background.h"
#include "personnage.h"
void Scroll(Background* b, Heros* h, SDL_Surface* screen)
{
	if(h->personnage.pos.x > screen->clip_rect.w/2)
	{
		(b->pos.x)++;
	}
	else if(h->personnage.pos.x < screen->clip_rect.w/2)
	{
		(b->pos.x)--;
	}
	else if(h->personnage.pos.y > b->pos.h/2 && b->pos.y <= b->pos.h / 2 + b->sprite->clip_rect.h && b->type == MAP)
	{
		(b->pos.y)++;
	}
	else if(h->personnage.pos.y < b->pos.h/2 && b->pos.y >= 0 && b->type == MAP)
	{
		(b->pos.y)--;
	}
}

void Afficher_Background(Background* b, Heros* h, SDL_Surface* screen)
{
	Scroll(b, h, screen);
	SDL_BlitSurface(b->sprite, &b->pos, screen ,NULL);
	SDL_Flip(screen);
}

Background Init_Background(Background_config * conf)
{
	Background b;
    b.mask = IMG_Load(conf->mask);
    b.sprite = IMG_Load(conf->sprite);
    b.type = conf->type;
    b.pos.x = 0;
    b.pos.y = 0;
    return b;
}
