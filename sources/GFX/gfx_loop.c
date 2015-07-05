/*
** gfx_loop.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 25 18:36:26 2015 Jordan Chazottes
** Last update Sun Jul  5 21:31:11 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		gfx_loop(t_gfx *s)
{
  struct timeval	tv;

  s->network.cmd = NULL;
  s->network.init = 0;
  FD_ZERO(&s->network.fd_write);
  while (eventHandler(s) != -1)
    {
      tv.tv_usec = 500;
      tv.tv_sec = 0;
      FD_ZERO(&s->network.fd_read);
      FD_SET(s->network.socket, &s->network.fd_read);
      if (select(s->network.socket + 1, &s->network.fd_read,
		 &s->network.fd_write, NULL, &tv) == -1)
	return (my_error(ERR_SELECT));
      FD_ZERO(&s->network.fd_write);
      if (FD_ISSET(s->network.socket, &s->network.fd_read))
	if (handleCmd(s) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
      if ((s->network.entire_cmd == 1 && s->network.init == 2)
	  || (s->camChange == 1 && s->network.init))
	if (draw(s) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
