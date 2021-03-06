/*
** cmd_graphic.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Thu Jun 25 16:55:26 2015 Mathieu
** Last update Thu Jul  2 18:02:55 2015 Martin Porrès
*/

#include		"serveur.h"

int			write_bct(t_block *block, int fd)
{
  if (dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", block->x, block->y,
	      block->items[0], block->items[1],
	      block->items[2], block->items[3],
	      block->items[4], block->items[5],
	      block->items[6]) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
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
  if (dprintf(client->fd, "msz %d %d\n", serv->settings->width,
	      serv->settings->height) == -1)
    return (EXIT_FAILURE);
  if (dprintf(client->fd, "sgt %d\n", serv->settings->delay) == -1)
    return (EXIT_FAILURE);
  while (i < serv->settings->width)
    {
      j = -1;
      while (++j < serv->settings->height)
	write_bct(&(serv->map->blocks[i][j]), client->fd);
      i++;
    }
  if (write_tna(serv, client->fd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_players(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			write_players(t_serv *serv, t_client *client)
{
  t_client		*tmp;

  tmp = serv->client;
  while (tmp != NULL)
    {
      if (write_pnw_gfx(client, tmp) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		write_tna(t_serv *serv, int fd)
{
  char		*tmp;

  tmp = serv->settings->teams;
  tmp = strtok(tmp, ";");
  while (tmp != NULL)
    {
      if (dprintf(fd, "tna %s\n", tmp) == -1)
	return (EXIT_FAILURE);
      tmp = strtok(NULL, ";");
    }
  return (EXIT_SUCCESS);
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
