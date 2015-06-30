/*
** draw.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 14:11:10 2015 Jordan Chazottes
** Last update Tue Jun 30 12:52:55 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		applySurface(t_pos pos, t_gfx *s, SDL_Surface *src, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = pos.x;
  offset.y = pos.y;
  SDL_BlitSurface(src, clip, s->screen, &offset);
}

/* printf("checking item %i on block %d %d = %d\n", i, pos.i, pos.j, s->map->blocks[pos.i][pos.j].items[i]); */

int		drawItems(t_gfx *s, SDL_Surface *img)
{
  t_pos		pos;
  int		i;

  pos.i = 0;
  while (pos.i < s->width)
    {
      pos.j = 0;
      while (pos.j < s->height)
	{
	  i = 0;
	  while (i < NB_ITEMS)
	    {
	      if (s->map->blocks[pos.i][pos.j].items[i] > 0)
		s->draw[i](s, img, pos);
	      i++;
	    }
	  pos.j++;
	}
      pos.i++;
    }
  return (EXIT_SUCCESS);
}

int		drawFloor(t_gfx *s)
{
  t_pos		pos;

  pos.i = 0;
  while (pos.i < s->width)
    {
      pos.j = 0;
      while (pos.j < s->height)
	{
	  pos.x = pos.i*64;
	  pos.y = pos.j*64;
	  applySurface(pos, s, s->floor->img, &s->floor->pos[0]);
	  pos.j++;
	}
      pos.i++;
    }
  return (EXIT_SUCCESS);
}

int		draw(t_gfx *s)
{
  SDL_Surface	*resImg;
  /* SDL_Surface	*pImg; */

  resImg = SDL_LoadBMP("assets/sprites/resources.bmp");
  /* pImg = SDL_LoadBMP("assets/sprites/mage_charset1.bmp"); */
  if (SDL_SetColorKey(resImg, SDL_SRCCOLORKEY, SDL_MapRGB(resImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  if (drawFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawItems(s, resImg) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /* if (drawPlayers(s, pImg) == EXIT_FAILURE) */
  /*   return (EXIT_FAILURE); */
  SDL_Flip(s->screen);
  return (EXIT_SUCCESS);
}
