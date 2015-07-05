/*
** draw_players.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:40:53 2015 Jordan Chazottes
** Last update Sun Jul  5 18:53:20 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		draw_p1(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset1.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p2(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset2.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p3(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset3.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p4(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset4.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p5(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset5.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY,
SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[get_act(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}
