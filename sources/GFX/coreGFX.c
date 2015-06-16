/*
** coreGFX.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:52:33 2015 Jordan Chazottes
** Last update Tue Jun 16 14:47:08 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		coreGFX(void) // change ip / port
{
  t_gfx		s;

  initStruct(&s);
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      printf("SDL_Init failed: %s\n", SDL_GetError());
      return;
    }
  SDL_WM_SetCaption("Zappy", "Zappy");
  s.screen = SDL_SetVideoMode(s.width, s.height, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
  while (eventHandler() != -1)
    {
      //onfédestrucs
    }
}
