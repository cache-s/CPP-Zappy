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

void			check_fds_states(t_serv *serv, int type)
{
  char			*cmd;
  t_client		*tmp;

  tmp = (type == 0) ? serv->gfx : serv->client;
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
