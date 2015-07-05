/*
** draw_food_linemate.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:53:57 2015 Jordan Chazottes
** Last update Sun Jul  5 18:54:19 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_food(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 0;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i - s->xScroll)*64;
  pos.y = ((pos.j - s->yScroll)*64) + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_linemate(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 16;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = ((pos.i - s->xScroll)*64) + 16;
  pos.y = ((pos.j - s->yScroll)*64) + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}
