/*
** coreGFX.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:52:33 2015 Jordan Chazottes
** Last update Sun Jul  5 19:42:48 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		coreGFX(char *ip, int port)
{
  t_gfx		s;
  int		ret;

  initStruct(&s);
  TTF_Init();
  initCmdTab(&s);
  initFctTab(&s);
  initDrawTab(&s);
  if (initNetwork(&s, ip, port) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (initFonts(&s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  ret = gfx_loop(&s);
  close (s.network.socket);
  SDL_FreeSurface(s.screen);
  freeStruct(&s);
  SDL_Quit();
  return (ret);
}
