/*
** draw_broadcast.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:22:49 2015 Jordan Chazottes
** Last update Sun Jul  5 18:48:05 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_broadcast(t_gfx *s, t_pos pos, SDL_Surface *i, t_player *p)
{
  SDL_Rect	rect;
  SDL_Surface	*bImg;

  if ((bImg = SDL_LoadBMP("assets/sprites/broadcast.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(bImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(bImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  rect.x = 35;
  rect.y = get_ori(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, i, &rect);
  rect.x = rect.y = 0;
  rect.w = rect.h = 48;
  pos.y -= 20;
  applySurface(pos, s, bImg, &rect);
  return (EXIT_SUCCESS);
}
