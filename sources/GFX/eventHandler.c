/*
** eventHandler.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 14:40:17 2015 Jordan Chazottes
** Last update Tue Jun 16 14:51:04 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		eventHandler()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case (SDL_QUIT):
      return -1;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  return -1;
	default :
	  return 0;
	}
    default :
      return 0;
    }
}
