/*
** connect.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
**
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
**
** Started on  Wed Jun 17 17:53:24 2015 Martin Porrès
** Last update Sun Jul  5 13:50:57 2015 Pierre Charie
*/

#include		"client.h"
#include		"AI_c_connector.h"
#include		"colors.h"

int			connect_to_server(t_client *client)
{
  struct sockaddr_in	sin;
  int			ret;

  if ((client->fd_socket = socket(AF_INET, SOCK_STREAM,
				  getprotobyname("TCP")->p_proto)) == -1)
    return (my_error(ERR_SOCKET));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(client->port);
  sin.sin_addr.s_addr = inet_addr(client->hostname);
  if (connect(client->fd_socket, (const struct sockaddr *)&sin,
	      sizeof(sin)) == -1)
    {
      close(client->fd_socket);
      return (my_error(ERR_CONNECT));
    }
  ret = client_loop(client);
  close(client->fd_socket);
  free(client->team_name);
  free(client->hostname);
  return (ret);
}

int			client_loop(t_client *client)
{
  fd_set		fd_read;
  fd_set		fd_write;

  client->init = 0;
  FD_ZERO(&fd_write);
  client->srv_cmd = NULL;
  client->clt_cmd = NULL;
  while (1)
    {
      FD_ZERO(&fd_read);
      FD_SET(client->fd_socket, &fd_read);
      if (select(client->fd_socket + 1, &fd_read, &fd_write, NULL, NULL) == -1)
	return (my_error(ERR_SELECT));
      FD_ZERO(&fd_write);
      if (FD_ISSET(client->fd_socket, &fd_read))
	if (handle_cmd(client, &fd_write) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			handle_cmd(t_client *client, fd_set *fd_write)
{
  if (server_read(client) == EXIT_FAILURE)
    return (my_error(ERR_SERVER));
  if (client->entire_cmd == 1)
    {
      if (print_info(client->srv_cmd, 0) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (client->init < 3 && init_connection(client) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (client->init == 3)
	client->clt_cmd = AI_call(client->srv_cmd);
      if (print_info(client->clt_cmd, 1) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (write_cmd(client, fd_write) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			print_info(char *str, int mode)
{
  char			*tmp;

  (void) mode;
  if (str != NULL)
    {
      if ((tmp = strdup(str)) == NULL)
  	return (my_error(ERR_STRDUP));
      /* if (mode) */
      /* 	printf(BOLD RED "Sending message '%s' to server\n" END, */
      /* 	       strtok(tmp, "\n")); */
      /* else */
      /* 	printf(BOLD BLUE "Received message '%s' from server\n" END, */
      /* 	       strtok(tmp, "\n")); */
      free(tmp);
    }
  return (EXIT_SUCCESS);
}
