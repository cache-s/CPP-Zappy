/*
** draw_players2.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:45:13 2015 Jordan Chazottes
** Last update Sun Jul  5 18:51:26 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_p6(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset6.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p7(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset7.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int			draw_p8(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset8.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}
