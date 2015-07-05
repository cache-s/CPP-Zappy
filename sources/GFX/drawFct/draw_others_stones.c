/*
** draw_others_stones.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:55:47 2015 Jordan Chazottes
** Last update Sun Jul  5 22:37:43 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_deraumere(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 32;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = ((pos.i - s->xScroll)*64) + 32;
  pos.y = ((pos.j - s->yScroll)*64) + 50;
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_sibur(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 48;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = ((pos.i - s->xScroll)*64) + 48;
  pos.y = ((pos.j - s->yScroll)*64) + 50;
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_mendiane(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 64;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i - s->xScroll)*64;
  pos.y = ((pos.j - s->yScroll)*64) + 16 + 50;
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_phiras(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 80;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = ((pos.i - s->xScroll)*64) + 16;
  pos.y = ((pos.j - s->yScroll)*64) + 16 + 50;
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_thystame(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 96;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = ((pos.i - s->xScroll)*64) + 32;
  pos.y = ((pos.j - s->yScroll)*64) + 16 + 50;
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}
