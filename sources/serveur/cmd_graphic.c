/*
** cmd_graphic.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Thu Jun 25 16:55:26 2015 Mathieu
** Last update Sun Jun 28 12:41:04 2015 Martin Porrès
*/

#include		"serveur.h"

void			write_bct(t_block *block, int fd)
{
  int			i;
  
  i = 0;
  dprintf(fd, "bct %d %d ", block->x, block->y);
  while (i < 7)
    {
      if ((i + 1) >= 7)
	dprintf(fd, "%d\n", block->items[i]);
      else
	dprintf(fd, "%d ", block->items[i]);
      i++;
    }
}

int			cmd_graphic(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  int			i;
  int			j;

  i = 0;
  if (client->gfx == 1)
    return (EXIT_SUCCESS);
  if (move_to_gfx_list(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  dprintf(client->fd, "msz %d %d\n", serv->settings->width, serv->settings->height);  
  dprintf(client->fd, "sgt %d\n", serv->settings->delay);
  while (i < serv->settings->width)
    {
      j = 0;
      while (j < serv->settings->height)
	{
	  write_bct(&(serv->map->blocks[i][j]), client->fd);
	  j++;
	}
      i++;
    }
  write_tna(serv, client->fd);
  return (EXIT_SUCCESS);
}

void		write_tna(t_serv *serv, int fd)
{
  char		*tmp;

  tmp = serv->settings->teams;
  tmp = strtok(tmp, ";");
  while (tmp != NULL)
    {
      dprintf(fd, "tna %s\n", tmp);
      tmp = strtok(NULL, ";");
    }
}

int		move_to_gfx_list(t_serv *serv, t_client *client)
{
  t_client	*tmp;

 client->gfx = 1;
  if (serv->gfx == NULL)
    serv->gfx = client;
  else
    {
      tmp = serv->gfx;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = client;
    }
  if (serv->client == client)
    serv->client = client->next;
  else
    {
      tmp = serv->client;
      while (tmp->next != NULL && tmp->next != client)
	tmp = tmp->next;
      if (tmp->next == NULL)
	return (my_error("move_to_gfx_list : can't find gfx in the list"));
      tmp->next = client->next;
    }
  client->next = NULL;
  return (EXIT_SUCCESS);
}
