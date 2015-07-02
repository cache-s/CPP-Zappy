/*
** initNetwork.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 23 13:04:16 2015 Jordan Chazottes
** Last update Tue Jun 30 17:05:57 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		initNetwork(t_gfx *s, char *ip, int port)
{
  struct sockaddr_in    sin;

  if ((s->network.socket = socket(AF_INET, SOCK_STREAM,
				  getprotobyname("TCP")->p_proto)) == -1)
    return (my_error(ERR_SOCKET));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip);
  if (connect(s->network.socket, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    return (my_error_close(ERR_CONNECT, s->network.socket));
  return (EXIT_SUCCESS);
}
