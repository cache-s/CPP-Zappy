/*
** draw.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 14:11:10 2015 Jordan Chazottes
** Last update Wed Jul  1 15:35:27 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		applySurface(t_pos pos, t_gfx *s, SDL_Surface *src, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = pos.x;
  offset.y = pos.y;
  SDL_BlitSurface(src, clip, s->screen, &offset);
}

int		drawItems(t_gfx *s, SDL_Surface *img)
{
  t_pos		pos;
  int		i;

  pos.i = 0;
  while (pos.i < s->width)
    {
      pos.j = -1;
      while (++pos.j < s->height)
	{
	  i = -1;
	  while (++i < NB_ITEMS)
	    if (s->map->blocks[pos.i][pos.j].items[i] > 0)
	      s->drawItem[i](s, img, pos);
	}
      pos.i++;
    }
  return (EXIT_SUCCESS);
}

int		drawFloor(t_gfx *s)
{
  t_pos		pos;
  SDL_Rect	rect[1];
  SDL_Surface	*img;

  pos.i = -1;
  if ((img = SDL_LoadBMP("assets/sprites/grass.bmp")) == NULL)
    return (EXIT_FAILURE);
  rect[0].x = rect[0].y = 0;
  rect[0].w = rect[0].h = 64;
  while (++pos.i < s->width)
    {
      pos.j = -1;
      while (++pos.j < s->height)
	{
	  pos.x = pos.i*64;
	  pos.y = pos.j*64;
	  applySurface(pos, s, img, &rect[0]);
	}
    }
  SDL_FreeSurface(img);
  return (EXIT_SUCCESS);
}

int		drawPlayers(t_gfx *s)
{
  t_player	*tmp;
  t_pos		pos;

  tmp = s->players;
  while (tmp != NULL)
    {
      pos.x = tmp->x*64;
      pos.y = tmp->y*64;
      s->drawPlayer[tmp->level - 1](s, pos, tmp->ori);
      tmp = tmp->next;
    }
  free(tmp);
  return (EXIT_SUCCESS);
}

int		draw(t_gfx *s)
{
  SDL_Surface	*resImg;

  resImg = SDL_LoadBMP("assets/sprites/resources.bmp");
  if (SDL_SetColorKey(resImg, SDL_SRCCOLORKEY, SDL_MapRGB(resImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  if (drawFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawItems(s, resImg) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawPlayers(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  SDL_FreeSurface(resImg);
  SDL_Flip(s->screen);
  return (EXIT_SUCCESS);
}
