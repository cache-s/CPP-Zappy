/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 29 18:06:32 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_inventory(UNUSED t_serv *serv, t_client *client,
				      UNUSED char *cmd)
{
  if (dprintf(client->fd, "{nourriture %d,linemate %d,deraumere %d,sibur %d,\
mendiane %d,phiras %d,thystame %d}\n", client->items[0], client->items[1],
	      client->items[2], client->items[3], client->items[4],
	      client->items[5], client->items[6]) == -1)
    return (EXIT_FAILURE);
  printf(BOLD RED"Sending '{nourriture %d,linemate %d,deraumere %d,sibur %d,\
mendiane %d,phiras %d,thystame %d}' to %d\n" END,
	 client->items[0], client->items[1],
	 client->items[2], client->items[3], client->items[4],
	 client->items[5], client->items[6], client->fd);
  return (EXIT_SUCCESS);
}
