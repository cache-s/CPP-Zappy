/*
** cmdInfos.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sat Jul  4 19:10:39 2015 Jordan Chazottes
** Last update Mon Jul  6 18:19:40 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		set_gui_infos(t_gfx *s)
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
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

void		set_infos_bg(t_gfx *s)
{
  SDL_Surface	*bg;
  SDL_Rect	pos;

  bg = SDL_CreateRGBSurface(SDL_HWSURFACE, MAX_VIEW * 64, 49, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = 0;
  SDL_FillRect(bg, NULL, SDL_MapRGB(s->screen->format, 127, 127, 127));
  SDL_BlitSurface(bg, NULL, s->screen, &pos);
}

int		fill_infos(t_gfx *s)
{
  int		i;
  int		x;

  i = 0;
  x = 110;
  while (i < NB_ITEMS)
    {
      if (my_regex(itoa(s->map->blocks[s->bSelect.x][s->bSelect.y].items[i]), ".0123456789")
	  == EXIT_FAILURE)
	return (EXIT_FAILURE);
      printf("Items %d = %d\n", i, s->map->blocks[s->bSelect.x][s->bSelect.y].items[i]);
      if (write_text(s, itoa(s->map->blocks
			     [s->bSelect.x][s->bSelect.y].items[i++]),
		    x, 10) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      x += 75;
    }
  return (EXIT_SUCCESS);
}

int		draw_infos(t_gfx *s)
{
  set_infos_bg(s);
  if (s->bSelect.x != -1)
    {
      if (set_gui_infos(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (fill_infos(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
