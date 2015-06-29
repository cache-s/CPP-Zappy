/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 29 17:45:58 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_take(t_serv *serv, t_client *client, char *cmd)
{
  int			item;
  int			ok;

  ok = 0;
  if (cmd != NULL && (item = get_item_number(serv, cmd)) != -1)
    if (serv->map->blocks[client->x][client->y].items[item] > 0)
      {
	// if (item == 0) -> generate random food
	serv->map->blocks[client->x][client->y].items[item] -= 1;
	client->items[item] += 1;
	ok = 1;
      }
  if (write_pgt_gfx(serv->gfx, client, item) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_pin_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_bct_gfx(serv->gfx, &(serv->map->blocks[client->x][client->y])) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_ok(client->fd, ok) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_item_number(t_serv *serv, char *cmd)
{
  int		i;

  i = 0;
  while (i < 7)
    {
      if (strcmp(serv->items[i], cmd) == 0)
	return (i);
      i++;
    }
  return (-1);
}
