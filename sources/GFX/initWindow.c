/*
** initWindow.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 18 12:30:42 2015 Jordan Chazottes
** Last update Thu Jun 18 12:38:32 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		initWindow(t_gfx *s)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      printf("SDL Init failed: %s\n", SDL_GetError());
      return;
    }
  SDL_WM_SetCaption("Zappy", "Zappy");
  s->screen = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN); // PLEIN ECRAN FULLSCREEN
}
