/*
** server.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Wed Mar 11 11:09:32 2015 Mathieu Bourmaud
** Last update Tue Jun 30 20:11:53 2015 Martin Porrès
*/

#include		"serveur.h"

void			empty_fds(t_serv *serv)
{
  t_client		*tmp;

  tmp = serv->client;
  FD_ZERO(&serv->readfds);
  FD_ZERO(&serv->writefds);
  FD_SET(serv->socket, &serv->readfds);
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, &serv->readfds);
      if (tmp->need_write)
	FD_SET(tmp->fd, &serv->writefds);
      tmp = tmp->next;
    }
  tmp = serv->gfx;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, &serv->readfds);
      if (tmp->need_write)
	FD_SET(tmp->fd, &serv->writefds);
      tmp = tmp->next;
    }
}

int			check_cmd_before_fill(char *cmd, t_client *tmp, t_serv *serv, int *end)
{
  char			*cpy;

  cpy = strdup(cmd);
  cpy = strtok(cpy, "\n");
  printf(BOLD BLUE "Received message '%s' from %d\n" END, cpy, tmp->fd);
  if (cmd == NULL || strcmp(cmd, "") == 0 || strlen(cmd) == 1)
    {
      printf(BOLD RED "Sending message '%s' to %d\n" END, "ko", tmp->fd);
      return (EXIT_FAILURE);
    }
  if (tmp->is_full == 1)
    {
      printf(BOLD RED "Sending message '%s' to %d\n" END, "ko", tmp->fd);
      if (my_write(tmp->fd, "ko") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_FAILURE);
    }
  if (count_char(cmd, '\n') >= 1)
    {
      cmd = strtok(cmd, "\n");
      *end = 1;
    }
  if (call_cmds(serv, cmd) == 42)
    {
      printf(BOLD RED "Sending message '%s' to %d\n" END, "ko", tmp->fd);
      if (my_write(tmp->fd, "ko") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			fill_cmd(char *cmd, t_client *tmp, t_serv *serv)
{
  int			end;
  
  end = 0;
  if (check_cmd_before_fill(cmd, tmp, serv, &end) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (tmp->cmd == NULL)
    {
      tmp->cmd = strdup(cmd);
      if ((tmp->cmd = realloc(tmp->cmd, strlen(tmp->cmd) + 3)) == NULL)
	return (my_error(ERR_REALLOC));
      tmp->cmd = strcat(tmp->cmd, ";");
    }
  else
    {
      if (strcmp(cmd, "\0") == 0 || strcmp(cmd, "") == 0)
	return (EXIT_FAILURE);
      if ((tmp->cmd = realloc(tmp->cmd, strlen(tmp->cmd) + strlen(cmd) + 3)) == NULL)
	return (my_error(ERR_REALLOC));
      tmp->cmd = strcat(tmp->cmd, cmd);
      if (end == 1)
	tmp->cmd = strcat(tmp->cmd, ";");
      if (count_char(tmp->cmd, ';') >= 10)
	tmp->is_full = 1;
    }
  return (EXIT_SUCCESS);
}

void			check_fds_states(t_serv *serv, int type)
{
  char			*cmd;
  t_client		*tmp;

  if (type == 0)
    tmp = serv->client;
  else
    tmp = serv->gfx;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, &(serv->readfds)))
	{
	  if ((cmd = tmp->fct_read(serv, tmp->fd)) == NULL)
	    return;
	  if (tmp->connected == 1)
	    fill_cmd(cmd, tmp, serv);
	  else
	    check_team(serv, tmp, cmd);
	}
      if (tmp->cmd != NULL && tmp->need_write == 1)
      	if (FD_ISSET(tmp->fd, &(serv->writefds)))
      	  {
      	    tmp->fct_write(serv, tmp, tmp->shortest_cmd);
	    update_client(tmp, serv);
      	  }
      tmp = tmp->next;
   }
}

char			*close_connect(t_serv *serv, int fd, int type)
{
  t_client		*tmp;
  t_client		*next;

  if (type == 0)
    tmp = serv->client;
  else
    tmp = serv->gfx;
  serv->nb_client--;
  if (close_first_elem(tmp, serv, fd, type) == EXIT_FAILURE)
    return (NULL);
  while (tmp->next != NULL && tmp->next->fd != fd)
    tmp = tmp->next;
  if (tmp->next != NULL)
    return (NULL);
  if (tmp->next != NULL)
    {
      if (write_pdi_gfx(serv->gfx, tmp) == EXIT_FAILURE)
	return (NULL);
      next = tmp->next->next;
      free(tmp->next);
      tmp->next = next;
    }
  else
    tmp->next = NULL;
  fprintf(stderr, CYAN "*** Deleting player %d\n" END, fd);
  close(fd);
  return (NULL);
}

int			close_first_elem(t_client *tmp, t_serv *serv, int fd, int type)
{
  fprintf(stderr, CYAN "*** Attempting to delete player %d\n" END, fd);
  if (tmp == NULL)
    return (EXIT_FAILURE);
  if (tmp->fd == fd)
    {
      if (type == 0)
	{
	  serv->client = serv->client->next;
	  if (write_pdi_gfx(serv->gfx, tmp) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else
	serv->gfx = serv->gfx->next;
      free(tmp);
      close(fd);
      fprintf(stderr, CYAN "*** Deleting player %d\n" END, fd);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

char			*client_read(UNUSED t_serv *serv, int fd)
{
   int			size_read;
  char			*cmd;

  if ((cmd = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
    return (my_error_null(ERR_MALLOC));
  bzero(cmd, BUFF_SIZE);
  size_read = read(fd, cmd, BUFF_SIZE - 1);
  if (size_read <= 0)
    {
      close_connect(serv, fd, 0);
      close_connect(serv, fd, 1);
      return (NULL);
    }
  if (size_read < BUFF_SIZE)
    return (cmd);
  return (cmd);
}
