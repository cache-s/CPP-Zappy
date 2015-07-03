/*
** initWindow.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 18 12:30:42 2015 Jordan Chazottes
** Last update Fri Jul  3 11:55:24 2015 Jordan Chazottes
*/

#include	"gfx.h"
#include	<pthread.h>

void		*poll_event(void* arg)
{
  SDL_Event	event;
  (void)arg;

  while (1)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
	exit (0);
      usleep(500);
    }
  return (0);
}

void		initWindow(t_gfx *s)
{
  /* pthread_t	thread1; */

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      printf("SDL Init failed: %s\n", SDL_GetError());
      return;
    }
  SDL_WM_SetCaption("Zappy", "Zappy");
  s->screen = SDL_SetVideoMode(s->width*64, s->height*64 + 150, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
  /* s->screen = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN); // PLEIN ECRAN FULLSCREEN */
  /* if (pthread_create(&thread1, NULL, &poll_event, (void*)s) != 0) */
  /*   return; */
}


