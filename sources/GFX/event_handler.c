/*
** eventHandler.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 30 18:06:41 2015 Jordan Chazottes
** Last update Sun Jul  5 23:11:57 2015 Jordan Chazottes
*/

#include	"gfx.h"

eEvent		get_P_selected(t_gfx *s, int x, int y)
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

eEvent		get_B_selected(t_gfx *s, int x, int y)
{
  s->bSelect.x = x/64;
  s->bSelect.y = (y - 50)/64;
  return (DEFAULT);
}

eEvent		reset_selected(t_gfx *s)
{
  s->pSelect = -1;
  s->bSelect.x = -1;
  s->bSelect.y = -1;
  return (DEFAULT);
}

eEvent		move_scroll(t_gfx *s, int x, int y)
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
  s->camChange = 1;
  return (DEFAULT);
}

eEvent		event_handler(t_gfx *s)
{
  SDL_Event	event;

  if (SDL_PollEvent(&event) == 1)
    {
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
	return (QUIT);
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (event.button.button == SDL_BUTTON_RIGHT)
	    return (reset_selected(s));
	  if (event.button.button == SDL_BUTTON_LEFT)
	    return (get_P_selected(s, event.button.x, event.button.y));
	  if (event.button.button == SDL_BUTTON_MIDDLE)
	    return (get_B_selected(s, event.button.x, event.button.y));
	  s->camChange = 1;
	}
      if (event.key.keysym.sym == SDLK_UP)
	return (move_scroll(s, 0, -1));
      if (event.key.keysym.sym == SDLK_LEFT)
	return (move_scroll(s, -1, 0));
      if (event.key.keysym.sym == SDLK_DOWN)
	return (move_scroll(s, 0, 1));
      if (event.key.keysym.sym == SDLK_RIGHT)
	return (move_scroll(s, 1, 0));
    }
  return (DEFAULT);
}
