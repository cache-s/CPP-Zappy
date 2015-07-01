/*
** eventHandler.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 30 18:06:41 2015 Jordan Chazottes
** Last update Tue Jun 30 18:15:06 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		eventHandler()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
    return (-1);
  return (0);
}
