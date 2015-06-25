/*
** gfx_loop.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 25 18:36:26 2015 Jordan Chazottes
** Last update Thu Jun 25 19:01:01 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		gfx_loop(t_gfx *s)
{
  FD_ZERO(&s->network.fd_read);
  FD_ZERO(&s->network.fd_write);
  s->network.cmd = NULL;
  while (eventHandler() != -1)
    {
      FD_SET(s->network.socket, &s->network.fd_read);
      if (select(s->network.socket + 1, &s->network.fd_read, &s->network.fd_write, NULL, NULL) == -1)
	return (my_error(ERR_SELECT));
      if (FD_ISSET(s->network.socket, &s->network.fd_read))
	if (server_read(s) == EXIT_FAILURE)
	  return (my_error(ERR_SERVER));
      if (s->network.entire_cmd == 1)
        FD_SET(s->network.socket, &s->network.fd_write);
      if (FD_ISSET(s->network.socket, &s->network.fd_write))
        {
	  if (strcmp(s->network.cmd, "BIENVENUE\n") == 0)
	    {
	      printf("Bienvenue");
	      if (my_write(s->network.socket, "GRAPHIC\n") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	    }
	  s->network.entire_cmd = 0;
        }
    }
  return (EXIT_SUCCESS);
}
