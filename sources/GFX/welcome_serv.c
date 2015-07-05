/*
** welcomeServ.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 13:29:44 2015 Jordan Chazottes
** Last update Sun Jul  5 22:49:01 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		welcome_serv(t_gfx *s)
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
