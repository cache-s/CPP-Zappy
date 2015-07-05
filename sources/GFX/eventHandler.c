/*
** eventHandler.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 30 18:06:41 2015 Jordan Chazottes
** Last update Sun Jul  5 17:21:16 2015 Jordan Chazottes
*/

#include	"gfx.h"

eEvent		getPSelected(t_gfx *s, int x, int y)
{
  t_player	*tmp;
  
  tmp = s->players;
  while (tmp != NULL)
    {
      if (x/64 == tmp->x && (y - 50)/64 == tmp->y)
	s->pSelect = tmp->id;
      tmp = tmp->next;
    }
  return (DEFAULT);
}

eEvent		getBSelected(t_gfx *s, int x, int y)
{
  s->bSelect.x = x/64;
  s->bSelect.y = (y - 50)/64;
  return (DEFAULT);
}

eEvent		resetSelected(t_gfx *s)
{
  s->pSelect = -1;
  s->bSelect.x = -1;
  s->bSelect.y = -1;
  return (DEFAULT);
}

eEvent		moveScroll(t_gfx *s, int x, int y)
{
  s->xScroll += x;
  s->yScroll += y;
  if (s->xScroll < 0)
    s->xScroll = 0;
  if (s->xScroll > (s->width - MAX_VIEW))
    s->xScroll = (s->width - MAX_VIEW);
  if (s->yScroll < 0)
    s->yScroll = 0;
  if (s->yScroll > (s->height - MAX_VIEW))
    s->yScroll = (s->height - MAX_VIEW);
  return (DEFAULT);
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
	    return (resetSelected(s));
	  if (event.button.button == SDL_BUTTON_LEFT)
	    return (getPSelected(s, event.button.x, event.button.y));
	  if (event.button.button == SDL_BUTTON_MIDDLE)
	    return (getBSelected(s, event.button.x, event.button.y));
	}
      if (event.key.keysym.sym == SDLK_UP)
	return (moveScroll(s, 0, -1));
      if (event.key.keysym.sym == SDLK_LEFT)
	return (moveScroll(s, -1, 0));
      if (event.key.keysym.sym == SDLK_DOWN)
	return (moveScroll(s, 0, 1));
      if (event.key.keysym.sym == SDLK_RIGHT)
	return (moveScroll(s, 1, 0));
    }
  return (DEFAULT);
}
