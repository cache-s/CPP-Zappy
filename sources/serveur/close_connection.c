/*
** close_connection.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jul  5 16:49:53 2015 Mathieu
** Last update Sun Jul  5 16:49:53 2015 Mathieu
*/

#include		"serveur.h"

char			*close_connect(t_serv *serv, int fd, int type)
{
  t_client		*tmp;
  
  if (type == 0)
    tmp = serv->client;
  else
    tmp = serv->gfx;
  serv->nb_client--;
  if (close_first_elem(tmp, serv, fd, type) == EXIT_FAILURE)
    return (NULL);
  while (tmp->next != NULL && tmp->next->fd != fd)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return (NULL);
  if (close_connect_end(serv, fd, tmp) == NULL)
    return (NULL);
  return (NULL);
}

char			*close_connect_end(t_serv *serv, int fd, t_client *tmp)
{
  t_client		*next;

  if (tmp->next != NULL)
    {
      if (tmp->connected)
	if (write_pdi_gfx(serv->gfx, tmp) == EXIT_FAILURE)
	  return (NULL);
      next = tmp->next->next;
      free(tmp->next);
      tmp->next = next;
    }
  else
    tmp->next = NULL;
  serv->settings->clients[tmp->team_pos] -= 1;
  fprintf(stderr, YELLOW "*** Deleting player %d\n" END, fd);
  close(fd);
  return (NULL);
}

int			close_first_elem(t_client *tmp, t_serv *serv, int fd, int type)
{
  fprintf(stderr, YELLOW "*** Attempting to delete player %d\n" END, fd);
  if (tmp == NULL)
    return (EXIT_FAILURE);
  if (tmp->fd == fd)
    {
      if (type == 0)
	{
	  serv->client = serv->client->next;
	  if (tmp->connected)
	    if (write_pdi_gfx(serv->gfx, tmp) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
	}
      else
	serv->gfx = serv->gfx->next;
      serv->settings->clients[tmp->team_pos] -= 1;
      free(tmp);
      close(fd);
      fprintf(stderr, YELLOW "*** Deleting player %d\n" END, fd);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
