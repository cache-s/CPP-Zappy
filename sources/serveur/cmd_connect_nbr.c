/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Sat Jun 27 20:58:59 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_connect_nbr(t_serv *serv, t_client *client,
					UNUSED char *cmd)
{
  printf(RED BOLD "Sending '%d' to %d\n" END, serv->settings->nb_clients
	 - serv->settings->clients[client->team_pos], client->fd);
  if (dprintf(client->fd, "%d\n", serv->settings->nb_clients
	      - serv->settings->clients[client->team_pos]) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
