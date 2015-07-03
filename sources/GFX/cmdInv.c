/*
** cmdInv.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jul  3 17:20:25 2015 Jordan Chazottes
** Last update Fri Jul  3 17:24:34 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		setGuiInv(t_gfx *s)
{
  SDL_Surface	*img;
  SDL_Rect	rect;
  t_pos		pos;

  rect.x = rect.y = 0;
  rect.w = 334;
  rect.h = 166;
  pos.x = pos.i = s->width * 64 - 334;
  pos.y = pos.j = s->height * 64 - 20;
  if ((img = SDL_LoadBMP("assets/sprites/player_infos.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

void		setBgInv(t_gfx *s)
{
  SDL_Surface	*bg;
  SDL_Rect	 pos;

  bg = SDL_CreateRGBSurface(SDL_HWSURFACE, s->width*64, 150, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = s->height * 64 + 1;
  SDL_FillRect(bg, NULL, SDL_MapRGB(s->screen->format, 127, 127, 127));
  SDL_BlitSurface(bg, NULL, s->screen, &pos);
}

int		fillInv(t_gfx *s, t_player *p)
{
  int		x;
  int		y;

  x = s->width * 64;
  y = s->height * 64;
  if (writeText(s, p->team, x - 320, y + 40) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, strcat(strdup("lvl "),
			  itoa(p->level)), x - 320, y + 70) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, itoa(p->items[0]), x - 210, y + 70) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, itoa(p->items[1]), x - 270, y + 95) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, itoa(p->items[2]), x - 210, y + 95) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, itoa(p->items[3]), x - 140, y + 95) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, itoa(p->items[4]), x - 270, y + 120) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (writeText(s, itoa(p->items[5]), x - 210, y + 120) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		drawInventory(t_gfx *s)
{
  t_player	*tmp;

  setBgInv(s);

  if (s->pSelect != -1)
    {
      if (setGuiInv(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      tmp = s->players;
      while (tmp != NULL && tmp->id != s->pSelect)
	tmp = tmp->next;
      if (tmp != NULL)
	fillInv(s, tmp);
    }
  return (EXIT_SUCCESS);
}
