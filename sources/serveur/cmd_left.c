/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 29 17:02:30 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_left(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  client->orientation -= 1;
  if (client->orientation < NORTH)
    client->orientation = WEST;
  if (write_ppo_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf(BOLD RED "Sending 'ok' to %d\n" END, client->fd);
  return (EXIT_SUCCESS);
}
