/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 29 17:48:47 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_drop(t_serv *serv, t_client *client, char *cmd)
{
  int			item;
  int			ok;

  ok = 0;
  if (cmd != NULL && (item = get_item_number(serv, cmd)) != -1)
    if (client->items[item] > 0)
      {
	client->items[item] -= 1;
	serv->map->blocks[client->x][client->y].items[item] += 1;
	ok = 1;
      }
  if (write_pdr_gfx(serv->gfx, client, item) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_pin_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_bct_gfx(serv->gfx, &(serv->map->blocks[client->x][client->y])) \
      == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_ok(client->fd, ok) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
