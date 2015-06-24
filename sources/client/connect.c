/*
** connect.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
**
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
**
** Started on  Wed Jun 17 17:53:24 2015 Martin Porrès
** Last update Wed Jun 24 12:05:34 2015 Pierre Charie
*/


#include		"client.h"
#include		"AI_c_connector.h"

int			connect_to_server(t_client *client)
{
  struct sockaddr_in	sin;
  int			ret;

  AI_sayHello("Le jeu");
  if ((client->fd_socket = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto)) == -1)
    return (my_error(ERR_SOCKET));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(client->port);
  sin.sin_addr.s_addr = inet_addr(client->hostname);
  if (connect(client->fd_socket, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      close(client->fd_socket);
      return (my_error(ERR_CONNECT));
    }
  ret = client_loop(client);
  close(client->fd_socket);
  return (ret);
}

int			client_loop(t_client *client)
{
  fd_set		fd_read;
  fd_set		fd_write;

  FD_ZERO(&fd_read);
  FD_ZERO(&fd_write);
  client->srv_cmd = NULL;
  while (1)
    {
      FD_SET(client->fd_socket, &fd_read);
      if (select(client->fd_socket + 1, &fd_read, &fd_write, NULL, NULL) == -1)
	return (my_error(ERR_SELECT));
      if (FD_ISSET(client->fd_socket, &fd_read))
      	if (server_read(client) == EXIT_FAILURE)
      	  return (EXIT_FAILURE);
      if (client->entire_cmd == 1)
	FD_SET(client->fd_socket, &fd_write);
      if (FD_ISSET(client->fd_socket, &fd_write))
	{
	  // call ai
	  client->entire_cmd = 0;
	}
    }
  return (EXIT_SUCCESS);
}

int			server_read(t_client *client)
{
  char			*buffer;
  int			ret;

  if ((buffer = malloc(BUFF_SIZE)) == NULL)
    return (my_error(ERR_MALLOC));
  bzero(buffer, BUFF_SIZE);
  if ((ret = read(client->fd_socket, buffer, BUFF_SIZE - 1)) <= 0)
    return (EXIT_FAILURE);
  if (save_srv_cmd(client, buffer) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(buffer);
  if (ret == BUFF_SIZE - 1)
      client->entire_cmd = 0;
  else
      client->entire_cmd = 1;
  return (EXIT_SUCCESS);
}

int			save_srv_cmd(t_client *client, char *buffer)
{
  if (client->srv_cmd == NULL)
    {
      if ((client->srv_cmd = strdup(buffer)) == NULL)
	return (my_error(ERR_STRDUP));
    }
  else
    {
      if ((client->srv_cmd = realloc(client->srv_cmd, strlen(client->srv_cmd)
				     + strlen(buffer) + 1)) == NULL)
	return (my_error(ERR_REALLOC));
      if ((client->srv_cmd = strcat(client->srv_cmd, buffer)) == NULL)
	return (my_error(ERR_STRCAT));
    }
  return (EXIT_SUCCESS);
}
