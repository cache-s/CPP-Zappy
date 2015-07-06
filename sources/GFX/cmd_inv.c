/*
** cmdInv.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jul  3 17:20:25 2015 Jordan Chazottes
** Last update Mon Jul  6 18:29:05 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		set_gui_inv(t_gfx *s)
{
  SDL_Surface	*img;
  SDL_Rect	rect;
  t_pos		pos;

  rect.x = rect.y = 0;
  rect.w = 334;
  rect.h = 166;
  pos.x = pos.i = MAX_VIEW * 64 - 334;
  pos.y = pos.j = MAX_VIEW * 64 - 20 + 50;
  if ((img = SDL_LoadBMP("assets/sprites/player_infos.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(img, SDL_SRCCOLORKEY,
		      SDL_MapRGB(img->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  apply_surface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

void		set_bg_inv(t_gfx *s)
{
  SDL_Surface	*bg;
  SDL_Rect	 pos;

  bg = SDL_CreateRGBSurface(SDL_HWSURFACE, MAX_VIEW * 64, 150, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = MAX_VIEW * 64 + 1 + 50;
  SDL_FillRect(bg, NULL, SDL_MapRGB(s->screen->format, 127, 127, 127));
  SDL_BlitSurface(bg, NULL, s->screen, &pos);
}

int		fill_inv(t_gfx *s, t_player *p)
{
  int		x;
  int		y;
  char		*level;

  if ((level = malloc(7 * sizeof(level))) == NULL)
    return (EXIT_FAILURE);
  if ((level = strcat(strdup("lvl "), itoa(p->level))) == NULL)
    return (EXIT_FAILURE);
  x = MAX_VIEW * 64;
  y = MAX_VIEW * 64 - 50;
  if (write_text(s, p->team, x - 320, y + 140) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, level, x - 320, y + 170) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, itoa(p->items[0]), x - 210, y + 170) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, itoa(p->items[1]), x - 270, y + 195) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, itoa(p->items[2]), x - 210, y + 195) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, itoa(p->items[3]), x - 140, y + 195) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, itoa(p->items[4]), x - 270, y + 220) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_text(s, itoa(p->items[5]), x - 210, y + 220) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		draw_inventory(t_gfx *s)
{
  t_player	*tmp;

  set_bg_inv(s);
  if (s->pSelect != -1)
    {
      if (set_gui_inv(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      tmp = s->players;
      while (tmp != NULL && tmp->id != s->pSelect)
	tmp = tmp->next;
      if (tmp != NULL)
	if (fill_inv(s, tmp) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
