/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Sat Jun 27 16:58:40 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_right(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  client->orientation += 1;
  if (client->orientation > WEST)
    client->orientation = NORTH;
  if (write_player_pos(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
