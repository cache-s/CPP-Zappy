/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Thu Jul  2 16:30:31 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_fork(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  int			fork;

  fork = 0;
  if (client->fork_step == 0 && fork != 1)
    {
      if (write_pfk_gfx(serv->gfx, client) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      client->forking = 1;
      client->fork_time = 42 / serv->settings->delay;
      client->fork_step = 1;
      fork++;
    }
  if (client->fork_step == 1 && fork != 1)
    if (fork_step1(serv, client, &fork) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if (client->fork_step == 2 && fork != 1)
    if (fork_step2(serv, client, &fork) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			fork_step1(t_serv *serv, t_client *client, int *fork)
{
  if (write_enw_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  client->forking = 1;
  client->fork_time = 600 / serv->settings->delay;
  client->fork_step = 2;
  *fork += 1;
  return (EXIT_SUCCESS);
}

int			fork_step2(t_serv *serv, t_client *client, int *fork)
{
  serv->settings->clients[client->team_pos] -= 1;
  if (write_eht_gfx(serv->gfx, client->id) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  client->forking = 0;
  client->fork_step = 0;
  *fork += 1;
  return (EXIT_SUCCESS);
}
