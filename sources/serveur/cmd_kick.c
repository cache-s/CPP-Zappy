/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Thu Jul  2 12:02:34 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_kick(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  t_client		*tmp;
  int			once;
  int			k;

  once = 0;
  k = client->orientation + 2;
  if (k > 4)
    k -= 4;
  tmp = serv->client;
  while (tmp != NULL)
    {
      if (once == 0)
	{
	  if (write_pex_gfx(serv->gfx, client) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  once++;
	}
      if (tmp != client && tmp->x == client->x && tmp->y == client->y)
	if (kick_player(serv, client, tmp, k) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  if (write_ok(client->fd, once) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			kick_player(t_serv *serv, t_client *kicker, \
				    t_client *kicked, int k)
{
  if (kicker->orientation == EST || kicker->orientation == WEST)
    modify_x(kicker->orientation, kicked, serv->settings->width);
  else
    modify_y(kicker->orientation, kicked, serv->settings->height);
  if (write_ppo_gfx(serv->gfx, kicked) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (dprintf(kicked->fd, "deplacement: %d\n", k) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
