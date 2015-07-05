/*
** draw_incant.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:26:17 2015 Jordan Chazottes
** Last update Sun Jul  5 22:38:32 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_incant(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Surface	*iImg;
  SDL_Rect	rect;

  if ((iImg = SDL_LoadBMP("assets/sprites/crystals.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(iImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(iImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  rect.x = 35;
  rect.y = get_ori(p->ori);
  rect.w = 34;
  rect.h = 66;
  apply_surface(pos, s, img, &rect);
  rect.x = 53 * (p->level - 1);
  rect.y = 0;
  rect.w = 53;
  rect.h = 87;
  pos.y -= 30;
  apply_surface(pos, s, iImg, &rect);
  return (EXIT_SUCCESS);
}
