/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Fri Jul  3 14:41:26 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_incantation(t_serv *serv, t_client *client,
					UNUSED char *cmd)
{

  if (client->lvl == 8 || inc_lvl(serv, client) == EXIT_FAILURE)
    {
      my_write(client->fd, "ko");
      printf(BOLD RED "Sending 'ko' to %d\n" END, client->fd); 
      return (EXIT_FAILURE);
    }
  if (my_write(client->fd, "elevation en cours") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf(BOLD RED "Sending 'elevation en cours' to %d\n" END, client->fd); 
  if (write_pic_gfx(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  client->incanting = 1;
  client->incant_time = 300 / serv->settings->delay;
  return (EXIT_SUCCESS);
}

int			cmd_end_incantation(t_serv *serv, t_client *client)
{
  if (client->lvl == 8 || inc_lvl(serv, client) == EXIT_FAILURE)
    {
      if (write_pie_gfx(serv->gfx, client, 0) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      my_write(client->fd, "ko");
      return (EXIT_FAILURE);
    }
  empty_block(&(serv->map->blocks[client->x][client->y]));
  if (write_bct_gfx(serv->gfx, &(serv->map->blocks[client->x][client->y]))
      == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (generate_all_item(serv, 1) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_pie_gfx(serv->gfx, client, 1) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (up_players(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  client->incanting = 0;
  return (EXIT_SUCCESS);
}

int			up_players(t_serv *serv, t_client *client)
{
  t_client		*tmp;

  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp->x == client->x && tmp->y == client->y)
	{
	  tmp->lvl += 1;
	  if (dprintf(client->fd, "niveau actuel : %d\n", tmp->lvl) == -1)
	    return (EXIT_FAILURE);
	  printf(BOLD RED "Sending 'niveau actuel : %d' to %d\n" END, tmp->lvl, tmp->fd);
	  if (write_plv_gfx(serv->gfx, tmp) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

void			empty_block(t_block *block)
{
  block->items[0] = 0;
  block->items[1] = 0;
  block->items[2] = 0;
  block->items[3] = 0;
  block->items[4] = 0;
  block->items[5] = 0;
  block->items[6] = 0;
}
