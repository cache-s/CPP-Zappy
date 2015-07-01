/*
** coreGFX.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:52:33 2015 Jordan Chazottes
** Last update Tue Jun 30 18:39:58 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		coreGFX(char *ip, int port)
{
  t_gfx		s;
  int		ret;

  initStruct(&s);
  initCmdTab(&s);
  initFctTab(&s);
  initDrawTab(&s);
  initSprites(&s);
  if (initNetwork(&s, ip, port) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  initWindow(&s);
  ret = gfx_loop(&s);
  close (s.network.socket);
  return (ret);  
}
