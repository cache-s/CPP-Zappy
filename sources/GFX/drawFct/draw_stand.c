/*
** draw_stand.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:25:04 2015 Jordan Chazottes
** Last update Sun Jul  5 22:37:19 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_stand(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Rect	rect;

  rect.x = 35;
  rect.y = get_ori(p->ori);
  rect.w = 34;
  rect.h = 66;
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}
