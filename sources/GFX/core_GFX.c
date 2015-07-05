/*
** coreGFX.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:52:33 2015 Jordan Chazottes
** Last update Sun Jul  5 22:47:22 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		core_GFX(char *ip, int port)
{
  t_gfx		s;
  int		ret;

  init_struct(&s);
  TTF_Init();
  init_cmd_tab(&s);
  init_fct_tab(&s);
  init_draw_tab(&s);
  if (init_network(&s, ip, port) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (init_fonts(&s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  ret = gfx_loop(&s);
  close (s.network.socket);
  SDL_FreeSurface(s.screen);
  free_struct(&s);
  SDL_Quit();
  return (ret);
}
