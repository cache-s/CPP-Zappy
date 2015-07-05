/*
** draw_fork.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:30:12 2015 Jordan Chazottes
** Last update Sun Jul  5 22:37:55 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_fork(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Surface	*fImg;
  SDL_Rect	rect;

  if ((fImg = SDL_LoadBMP("assets/sprites/fork.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(fImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(fImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  SDL_SetAlpha(fImg, SDL_SRCALPHA, 128);
  rect.x = 35;
  rect.y = get_ori(p->ori);
  rect.w = 34;
  rect.h = 66;
  apply_surface(pos, s, img, &rect);
  rect.x = rect.y = 0;
  rect.w = rect.h = 100;
  pos.x -= 35;
  pos.y -= 10;
  apply_surface(pos, s, fImg, &rect);
  return (EXIT_SUCCESS);
}
