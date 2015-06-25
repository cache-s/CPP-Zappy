/*
** initNetwork.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 23 13:04:16 2015 Jordan Chazottes
** Last update Thu Jun 25 18:27:05 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		initNetwork(t_gfx *s, char *ip, int port)
{
  struct sockaddr_in    sin;

  if ((s->network.socket = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto)) == -1)
    return (my_error(ERR_SOCKET));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip);
  printf(BOLD GREEN "Connecting to server\n" END);
  if (connect(s->network.socket, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    return (my_error_close(ERR_CONNECT, s->network.socket));
  return (EXIT_SUCCESS);
}

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
	  //call serv
	  s->network.entire_cmd = 0;
	}
    }
  return (EXIT_SUCCESS);
}

int		server_read(t_gfx *s)
{
  char		*buffer;
  int		ret;

  if ((buffer =  malloc(BUFF_SIZE)) == NULL)
    return (my_error(ERR_MALLOC));
  bzero(buffer, BUFF_SIZE);
  if ((ret = read(s->network.socket, buffer, BUFF_SIZE - 1)) <= 0)
    return (EXIT_FAILURE);
  if (save_srv_cmd(s, buffer) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(buffer);
  if (ret == BUFF_SIZE - 1)
    s->network.entire_cmd = 0;
  else
    {
      s->network.entire_cmd = 1;
      printf("Server msg : %s", s->network.cmd);
    }
  return (EXIT_SUCCESS);
}

int                     save_srv_cmd(t_gfx *s, char *buffer)
{
  if (s->network.cmd == NULL)
    {
      if ((s->network.cmd = strdup(buffer)) == NULL)
	return (my_error(ERR_STRDUP));
    }
  else
    {
      if ((s->network.cmd = realloc(s->network.cmd, strlen(s->network.cmd)
				     + strlen(buffer) + 1)) == NULL)
	return (my_error(ERR_REALLOC));
      if ((s->network.cmd = strcat(s->network.cmd, buffer)) == NULL)
	return (my_error(ERR_STRCAT));
    }
  return (EXIT_SUCCESS);
}
