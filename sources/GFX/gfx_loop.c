/*
** gfx_loop.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 25 18:36:26 2015 Jordan Chazottes
** Last update Mon Jun 29 19:59:38 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		gfx_loop(t_gfx *s)
{
  s->network.cmd = NULL;
  s->network.init = 0;
  FD_ZERO(&s->network.fd_write);

  while (eventHandler() != -1)
    {
      FD_ZERO(&s->network.fd_read);
      FD_SET(s->network.socket, &s->network.fd_read);
      if (select(s->network.socket + 1, &s->network.fd_read, &s->network.fd_write, NULL, NULL) == -1)
	return (my_error(ERR_SELECT));
      FD_ZERO(&s->network.fd_write);
      if (FD_ISSET(s->network.socket, &s->network.fd_read))
	{
	  if (handleCmd(s) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  if (draw(s) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
