/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 29 17:03:17 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_move_forward(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  if (client->orientation == NORTH || client->orientation == SOUTH)
    modify_x(client, serv->settings->width);
  else
    modify_y(client, serv->settings->height);
  if (write_ppo_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf(RED BOLD "Sending 'ok' to %d\n" END, client->fd);
  return (EXIT_SUCCESS);
}

void			modify_x(t_client *client, int width)
{
  if (client->orientation == NORTH)
    {
      client->x -= 1;
      if (client->x < 0)
	client->x = width;
    }
  else
    {
      client->x += 1;
      if (client->x >= width)
	client->x = 0;
    }
}

void			modify_y(t_client *client, int height)
{
  if (client->orientation == WEST)
    {
      client->y -= 1;
      if (client->y < 0)
	client->y = height;
    }
  else
    {
      client->y += 1;
      if (client->y >= height)
	client->y = 0;
    }
}

int			write_ppo_gfx(t_client *gfx, t_client *client)
{
  t_client      *tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "ppo %d %d %d %d\n", client->id, client->x,
		  client->y, client->orientation) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}
