/*
** draw.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 14:11:10 2015 Jordan Chazottes
** Last update Fri Jul  3 16:07:48 2015 Jordan Chazottes
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

int		writeText(t_gfx *s, char *msg, int x, int y)
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

int		fillInv(t_gfx *s, t_player *p)
{
  int		x;
  int		y;

  x = s->width * 64;
  y = s->height * 64;
  writeText(s, p->team, x - 320, y + 40);
  writeText(s, strcat(strdup("lvl "), itoa(p->level)), x - 320, y + 70);
  writeText(s, itoa(p->items[0]), x - 210, y + 70);
  writeText(s, itoa(p->items[1]), x - 270, y + 95);
  writeText(s, itoa(p->items[2]), x - 210, y + 95);
  writeText(s, itoa(p->items[3]), x - 140, y + 95);
  writeText(s, itoa(p->items[4]), x - 270, y + 120);
  writeText(s, itoa(p->items[5]), x - 210, y + 120);

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
