/*
** connect.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
**
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
**
** Started on  Wed Jun 17 17:53:24 2015 Martin Porrès
** Last update Thu Jun 25 18:23:28 2015 Martin Porrès
*/


#include		"client.h"
#include		"AI_c_connector.h"

int			connect_to_server(t_client *client)
{
  struct sockaddr_in	sin;
  int			ret;

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
  int			init;

  init = 0;
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
      	  return (my_error(ERR_SERVER));
      if (client->entire_cmd == 1)
	FD_SET(client->fd_socket, &fd_write);
      if (FD_ISSET(client->fd_socket, &fd_write))
	{
	  if (init)
	    AI_call(client->srv_cmd);
	  else
	    init_connection(client, init);
	  client->entire_cmd = 0;
	  free(client->srv_cmd);
	}
    }
  return (EXIT_SUCCESS);
}

int			init_connection(t_client *client)
{
  char			*tmp;
  int			is_tok;

  is_tok = 0;
  if (init == 0)
    if (strcmp("BIENVENUE\n", str) != 0)
      return (my_error(ERR_WELCOME));
    else
      {
	init++;
	if (write(client->fd_socket, client->team_name, strlen(client->team_name)) == -1)
	  return (my_error(ERR_WRITE));
      }
  else
    {
      if (init == 1)
	if ((tmp = strtok(client->srv_cmd, "\n")) == NULL)
	  return (my_error(ERR_WELCOME));
	else
	  {
	    is_tok++;
	    if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
	      return (my_error(ERR_WELCOME));
	    client->num_client = atoi(tmp);
	    init++;
	  }
      if (is_tok)
	{
	  if ((tmp = strtok(client->srv_cmd, " ")) == NULL)
	    return (EXIT_SUCCESS);
	}
      else
	if ((tmp = strtok(NULL, " ")) == NULL)
	  return (EXIT_SUCCESS);	  
      if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
	return (my_error(ERR_WELCOME));
      client->x = atoi(tmp);
      if ((tmp = strtok(NULL, "\n")) == NULL)
	return (my_error(ERR_WRITE));
      if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
	return (my_error(ERR_WELCOME));
      client->y = atoi(tmp);
      init++;
      // call ai for settings
      printf("Num client : %d\nX : %d\n Y : %d\n", client->num_client, client->x, client->y);
    }
}

int			server_read(t_client *client)
{
  char			*buffer;
  int			ret;

  if ((buffer = malloc(BUFF_SIZE)) == NULL)
    return (my_error(ERR_MALLOC));
  bzero(buffer, BUFF_SIZE);
  if ((ret = read(client->fd_socket, buffer, BUFF_SIZE - 1)) <= 0)
    return (my_error(ERR_READ));
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
