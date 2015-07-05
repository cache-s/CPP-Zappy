/*
** cmdInfos.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sat Jul  4 19:10:39 2015 Jordan Chazottes
** Last update Sun Jul  5 19:56:22 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		setGuiInfos(t_gfx *s)
{
  SDL_Surface	*img;
  SDL_Rect	rect;
  t_pos		pos;

  rect.x = 0;
  rect.y = 15;
  rect.w = 556;
  rect.h = 50;
  pos.x = pos.i = 42;
  pos.y = pos.j = 0;
  if ((img = SDL_LoadBMP("assets/sprites/block_infos.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(img, SDL_SRCCOLORKEY,
		      SDL_MapRGB(img->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

void		setInfosBg(t_gfx *s)
{
  SDL_Surface	*bg;
  SDL_Rect	pos;

  bg = SDL_CreateRGBSurface(SDL_HWSURFACE, MAX_VIEW * 64, 49, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = 0;
  SDL_FillRect(bg, NULL, SDL_MapRGB(s->screen->format, 127, 127, 127));
  SDL_BlitSurface(bg, NULL, s->screen, &pos);
}

int		fillInfos(t_gfx *s)
{
  int		i;
  int		x;

  i = 0;
  x = 110;
  while (i < NB_ITEMS)
    {
      if (writeText(s, itoa(
			    s->map->blocks[s->bSelect.x][s->bSelect.y].items[i++]),
		    x, 10) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      x += 75;
    }
  return (EXIT_SUCCESS);
}

int		drawInfos(t_gfx *s)
{
  setInfosBg(s);
  if (s->bSelect.x != -1)
    {
      if (setGuiInfos(s) == EXIT_FAILURE)
  	return (EXIT_FAILURE);
      if (fillInfos(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
