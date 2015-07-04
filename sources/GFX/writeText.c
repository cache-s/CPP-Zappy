/*
** writeText.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jul  3 17:16:36 2015 Jordan Chazottes
** Last update Fri Jul  3 17:17:24 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		 writeText(t_gfx *s, char *msg, int x, int y)
{
  SDL_Color	color;
  SDL_Rect	pos;
  SDL_Surface	*txt;

  color.r = 255;
  color.g = 165;
  color.b = 0;
  pos.x = x;
  pos.y = y;
  if ((txt = TTF_RenderText_Blended(s->font, msg, color)) == NULL)
    return (EXIT_FAILURE);
  SDL_BlitSurface(txt, NULL, s->screen, &pos);
  return (EXIT_SUCCESS);
}
