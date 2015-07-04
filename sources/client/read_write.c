/*
** read_write.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Sat Jul  4 21:16:28 2015 Martin Porrès
** Last update Sat Jul  4 21:28:52 2015 Martin Porrès
*/

#include	"client.h"

int		write_cmd(t_client *client, fd_set *fd_write)
{
  if (client->srv_cmd != NULL && strcmp(client->srv_cmd, "") != 0)
    free(client->srv_cmd);
  client->srv_cmd = NULL;
  if (client->clt_cmd == NULL)
    return (EXIT_SUCCESS);
  FD_SET(client->fd_socket, fd_write);
  if (FD_ISSET(client->fd_socket, fd_write))
    {
      if (write(client->fd_socket, client->clt_cmd,
		strlen(client->clt_cmd)) == -1)
	return (my_error(ERR_CLOSE));
      if (write(client->fd_socket, "\n", 1) == -1)
	return (my_error(ERR_CLOSE));
    }
  return (EXIT_SUCCESS);
}

int		server_read(t_client *client)
{
  char		*buffer;
  int		ret;

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

int		save_srv_cmd(t_client *client, char *buffer)
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
