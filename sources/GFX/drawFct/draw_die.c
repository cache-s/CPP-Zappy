/*
** draw_die.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:27:58 2015 Jordan Chazottes
** Last update Sun Jul  5 18:49:36 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_die(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Rect	 rect;

  rect.x = 535;
  rect.y = get_ori(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}
