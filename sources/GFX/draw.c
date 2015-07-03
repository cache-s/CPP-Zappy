/*
** draw.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 14:11:10 2015 Jordan Chazottes
** Last update Fri Jul  3 14:20:43 2015 Jordan Chazottes
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

  pos.i = s->map->dispX;
  while (pos.i < s->width)// && pos.i < (s->map->dispX + MAX_VIEW))
    {
      pos.j = s->map->dispY - 1;
      while (++pos.j < s->height)// && pos.j < (s->map->dispY + MAX_VIEW))
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

  pos.i = s->map->dispX - 1;
  if ((img = SDL_LoadBMP("assets/sprites/grass.bmp")) == NULL)
    return (EXIT_FAILURE);
  rect[0].x = rect[0].y = 0;
  rect[0].w = rect[0].h = 64;

  while (++pos.i < s->width) // && pos.i < (s->map->dispX + MAX_VIEW))
    {
      pos.j = s->map->dispY - 1;
      while (++pos.j < s->height) // && pos.j < (s->map->dispY + MAX_VIEW))
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
  SDL_Rect	pos;

  bg = SDL_CreateRGBSurface(SDL_HWSURFACE, s->width*64, 150, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = s->height * 64 + 1;
  SDL_FillRect(bg, NULL, SDL_MapRGB(s->screen->format, 127, 127, 127));
  SDL_BlitSurface(bg, NULL, s->screen, &pos);
}

int		fillInv(t_gfx *s, t_player *tmp)
{
  SDL_Surface	*msg;
  SDL_Color	color;
  SDL_Rect	pos;
  TTF_Font	*font;

  font = TTF_OpenFont("assets/fonts/pump.ttf", 20);
  color.r = 255;
  color.g = 165;
  color.b = 0;
  if ((msg = TTF_RenderText_Blended(font, itoa(tmp->items[0]), color)) == NULL)
    return (EXIT_FAILURE);
  pos.x = pos.y = 0;
  SDL_BlitSurface(msg, NULL, s->screen, &pos);
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

int		draw(t_gfx *s)
{
  SDL_Surface	*resImg;

  if ((resImg = SDL_LoadBMP("assets/sprites/resources.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(resImg, SDL_SRCCOLORKEY, SDL_MapRGB(resImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  if (drawFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawItems(s, resImg) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawPlayers(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (drawInventory(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  SDL_FreeSurface(resImg);
  SDL_Flip(s->screen);
  return (EXIT_SUCCESS);
}
