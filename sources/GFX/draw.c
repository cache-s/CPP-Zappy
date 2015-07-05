/*
** draw.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 14:11:10 2015 Jordan Chazottes
** Last update Sun Jul  5 21:33:54 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		drawItems(t_gfx *s, SDL_Surface *img)
{
  t_pos		pos;
  int		i;

  pos.i = s->xScroll - 1;
  while (++pos.i < s->width && pos.i < (s->yScroll + MAX_VIEW))
    {
      pos.j = s->yScroll - 1;
      while (++pos.j < s->height && pos.j < (s->yScroll + MAX_VIEW))
	{
	  i = -1;
	  while (++i < NB_ITEMS)
	    {
	      if (s->map->blocks[pos.i][pos.j].items[i] > 0)
		s->drawItem[i](s, img, pos);
	    }
	}
    }
  return (EXIT_SUCCESS);
}

int		drawFloor(t_gfx *s)
{
  t_pos		pos;
  SDL_Rect	rect;
  SDL_Surface	*img;

  pos.i = s->xScroll - 1;
  if ((img = SDL_LoadBMP("assets/sprites/grass.bmp")) == NULL)
    return (EXIT_FAILURE);
  rect.x = rect.y = 0;
  rect.w = rect.h = 64;
  while (++pos.i < s->width && pos.i < (s->xScroll + MAX_VIEW))
    {
      pos.j = s->yScroll - 1;
      while (++pos.j < s->height && pos.j < (s->yScroll + MAX_VIEW))
	{
	  pos.x = (pos.i - s->xScroll)*64;
	  pos.y = (pos.j - s->yScroll)*64 + 50;
	  applySurface(pos, s, img, &rect);
	}
    }
  SDL_FreeSurface(img);
  return (EXIT_SUCCESS);
}

int		drawPlayers(t_gfx *s)
{
  t_player	*tmp;
  t_pos		pos;

  if (s->players != NULL)
    {
      tmp = s->players;
      while (tmp != NULL && tmp->x < s->width &&
	     tmp->y < s->height && tmp->x < (s->xScroll + MAX_VIEW)
	     && tmp->y < (s->yScroll + MAX_VIEW))
	{
	  pos.x = (tmp->x - s->xScroll)*64;
	  pos.y = ((tmp->y - s->yScroll)*64) + 50;
	  s->drawPlayer[tmp->level - 1](s, pos, tmp);
	  tmp = tmp->next;
	}
    }
  return (EXIT_SUCCESS);
}

int		draw(t_gfx *s)
{
  SDL_Surface	*resImg;

  if ((resImg = SDL_LoadBMP("assets/sprites/resources.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(resImg, SDL_SRCCOLORKEY,
		      SDL_MapRGB(resImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  if (drawFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawItems(s, resImg) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawInfos(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawInventory(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawPlayers(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  SDL_FreeSurface(resImg);
  SDL_Flip(s->screen);
  s->network.entire_cmd = 0;
  s->camChange = 0;
  return (EXIT_SUCCESS);
}
