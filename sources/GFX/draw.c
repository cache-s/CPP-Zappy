/*
** draw.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 14:11:10 2015 Jordan Chazottes
** Last update Mon Jun 29 14:37:02 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		applySurface(int x, int y, SDL_Surface *src, SDL_Surface *dest, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, clip, dest, &offset);
}

int		drawFloor(t_gfx *s)
{
  int		i;
  int		j;
  SDL_Rect	clip[1];
  SDL_Surface	*bg;

  i = 0;
  bg = IMG_Load("assets/sprites/grass.bmp");
  clip[0].x = 0;
  clip[0].y = 0;
  clip[0].w = 64;
  clip[0].h = 64;
  while (i < s->width)
    {
      j = 0;
      while (j < s->height)
	{
	  applySurface(i*64, j*64, bg, s->screen, &clip[0]);
	  ++j;
	}
      ++i;
    }
  SDL_Flip(s->screen);
  return (EXIT_SUCCESS);
}

int		draw(t_gfx *s)
{
  if (drawFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
