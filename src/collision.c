#include "personnage.h"
#include "collision.h"


int check_collision (Personnage *p1, Personnage *p2)
{
	if((p1->pos.x >= p2->pos.x + p2->pos.w)      // trop � droite
	|| (p1->pos.x + p1->pos.w <= p2->pos.x) // trop � gauche
    || (p1->pos.y >= p2->pos.y + p2->pos.h) // trop en bas
	|| (p1->pos.y + p1->pos.h <= p2->pos.y))  // trop en haut
		return 1;
	else
		return 0;
 
}

//lire la couleur d'un pixel donn� par ses coordonn�es
SDL_Color GetPixel (SDL_Surface *pSurface, int x, int y)
{
 SDL_Color color;
 Uint32 col = 0;
//determiner position
 char *pPosition = (char*) pSurface->pixels;
//offset by y
 pPosition += (pSurface->pitch * y);
//offset by x
 pPosition += (pSurface->format->BytesPerPixel * x);
//copy pixel data
 memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
//convert color
 SDL_GetRGB (col, pSurface->format,  &color.r, &color.g, &color.b);

  return (color);
}

// collision parfaite avec le background (1:collision, 0:pas de collision)
int collision_parfaite (Background *background, Personnage * perso, Direction direction)
{

	 SDL_Color color[4];
	 SDL_Rect pPoint[4];

	//points a droite
	 pPoint[0].x = perso->pos.x;
	 pPoint[0].y = 0;
	//point en dessous
	 pPoint[1].x = 0;
	 pPoint[1].y = perso->pos.y;
	//points a gauche
	 pPoint[2].x = perso->pos.x;
	 pPoint[2].y = perso->pos.y + perso->pos.h;
	//point en dessus
	 pPoint[3].x = perso->pos.x + perso->pos.w;
	 pPoint[3].y = perso->pos.y;


	  color[0] = GetPixel (background->mask, pPoint[0].x, pPoint[0].y);
	  color[1] = GetPixel (background->mask, pPoint[1].x, pPoint[1].y);
	  color[2] = GetPixel (background->mask, pPoint[2].x, pPoint[2].y);
	  color[3] = GetPixel (background->mask, pPoint[3].x, pPoint[3].y);

	//collision a droite
	if(direction == RIGHT)
	{
		if (((color[0].r == 255) && (color[0].g == 255) && (color[0].b == 255)))
			return OBSTACLE;
		else if (((color[0].r == 255) && (color[0].g == 0) && (color[0].b == 0)))
			return COIN;
	}
	//collision en bas
	else if(direction == DOWN)
	{
		if (((color[0].r == 255) && (color[0].g == 255) && (color[0].b == 255)))
			return OBSTACLE;
		else if (((color[0].r == 255) && (color[0].g == 0) && (color[0].b == 0)))
			return COIN;
	}
	//collsion a gauche
	else if(direction == LEFT)
	{
		if (((color[0].r == 255) && (color[0].g == 255) && (color[0].b == 255)))
			return OBSTACLE;
		else if (((color[0].r == 255) && (color[0].g == 0) && (color[0].b == 0)))
			return COIN;
	}
	//collision en dessus
	else if(direction == UP)
	{
		if (((color[0].r == 255) && (color[0].g == 255) && (color[0].b == 255)))
			return OBSTACLE;
		else if (((color[0].r == 255) && (color[0].g == 0) && (color[0].b == 0)))
			return COIN;
	}
return 0;
}