/*
** eventHandler.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 30 18:06:41 2015 Jordan Chazottes
** Last update Wed Jul  1 15:10:44 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		eventHandler()
{
  SDL_Event	event;

  if (SDL_PollEvent(&event) == 1)
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
      return (-1);
  return (0);
}
