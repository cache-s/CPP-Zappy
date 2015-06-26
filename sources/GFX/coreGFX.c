/*
** coreGFX.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:52:33 2015 Jordan Chazottes
** Last update Thu Jun 25 18:32:22 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		coreGFX(char *ip, int port)
{
  t_gfx		s;
  int		ret;

  initStruct(&s);
  if (initNetwork(&s, ip, port) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /* initWindow(&s); */
  ret = gfx_loop(&s);
  close (s.network.socket);
  return (ret);  
}
