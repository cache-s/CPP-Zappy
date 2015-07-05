/*
** eventHandler.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 30 18:06:41 2015 Jordan Chazottes
** Last update Sun Jul  5 13:18:57 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		getPSelected(t_gfx *s, int x, int y)
{
  t_player	*tmp;
  
  tmp = s->players;
  while (tmp != NULL)
    {
      if (x/64 == tmp->x && (y - 50)/64 == tmp->y)
	s->pSelect = tmp->id;
      tmp = tmp->next;
    }
}

void		getBSelected(t_gfx *s, int x, int y)
{
  s->bSelect.x = x/64;
  s->bSelect.y = (y - 50)/64;
}

void		resetSelected(t_gfx *s)
{
  s->pSelect = -1;
  s->bSelect.x = -1;
  s->bSelect.y = -1;
}

eEvent		eventHandler(t_gfx *s)
{
  SDL_Event	event;

  if (SDL_PollEvent(&event) == 1)
    {
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
	return (QUIT);
      if(event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (event.button.button == SDL_BUTTON_RIGHT)
	    resetSelected(s);
	  if (event.button.button == SDL_BUTTON_LEFT)
	    getPSelected(s, event.button.x, event.button.y);
	  if (event.button.button == SDL_BUTTON_MIDDLE)
	    getBSelected(s, event.button.x, event.button.y);
	}
      if (event.key.keysym.sym == SDLK_UP)
      	{
      	  s->yScroll--;
      	  if (s->yScroll < 0)
      	    s->yScroll = 0;
      	  return (UP);
      	}
      if (event.key.keysym.sym == SDLK_LEFT)
      	{
      	  s->xScroll--;
      	  if (s->xScroll < 0)
      	    s->xScroll = 0;
      	  return (LEFT);
      	}
      if (event.key.keysym.sym == SDLK_DOWN)
      	{
      	  s->yScroll++;
      	  if (s->yScroll > s->height)
      	    s->yScroll = s->height;
      	  return (DOWN);
      	}
      if (event.key.keysym.sym == SDLK_RIGHT)
      	{
      	  s->xScroll++;
      	  if (s->xScroll > s->width)
      	    s->xScroll = s->width;
      	  return (RIGHT);
      	}
    }
  return (0);
}
