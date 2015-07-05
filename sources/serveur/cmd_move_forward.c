/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Thu Jul  2 12:02:23 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_move_forward(t_serv *serv, t_client *client,
					 UNUSED char *cmd)
{
  if (client->orientation == EST || client->orientation == WEST)
    modify_x(client->orientation, client, serv->settings->width);
  else
    modify_y(client->orientation, client, serv->settings->height);
  if (write_ppo_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf(RED BOLD "Sending 'ok' to %d" END, client->fd);
  return (EXIT_SUCCESS);
}

void			modify_x(eOrientation orientation, t_client *client, int width)
{
  if (orientation == WEST)
    {
      client->x -= 1;
      if (client->x < 0)
	client->x = width - 1;
    }
  else
    {
      client->x += 1;
      if (client->x >= width - 1)
	client->x = 0;
    }
}

void			modify_y(eOrientation orientation, t_client *client,
				 int height)
{
  if (orientation == NORTH)
    {
      client->y -= 1;
      if (client->y < 0)
	client->y = height - 1;
    }
  else
    {
      client->y += 1;
      if (client->y >= height - 1)
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
