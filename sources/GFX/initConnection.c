/*
** initConnection.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 13:29:44 2015 Jordan Chazottes
** Last update Sat Jun 27 15:24:58 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		welcomeServ(t_gfx *s)
{
  if (strcmp(WELCOME, s->network.cmd) != 0)
    return (my_error(ERR_WELCOME));
  else
    {
      if (write(s->network.socket, GRAPHIC, strlen(GRAPHIC)) == -1)
	return (my_error(ERR_WRITE));
      if (s->network.cmd != NULL)
	free(s->network.cmd);
      s->network.cmd = NULL;
      s->network.init = 1;
    }
  return (EXIT_SUCCESS);
}

int		initConnection(t_gfx *s)
{
  printf("Init = %d\n", s->network.init);
  if (s->network.init == 0)
    {
      if (welcomeServ(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  if (s->network.init == 1)
    if (initMap(s, NULL, NULL, NULL) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
