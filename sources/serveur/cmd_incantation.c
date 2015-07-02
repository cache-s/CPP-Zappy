/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Thu Jul  2 00:25:20 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_incantation(t_serv *serv, t_client *client, UNUSED char *cmd)
{

  if (client->lvl == 8 || serv->inc_lvl[client->lvl](serv, client) == EXIT_FAILURE)
    {
      my_write(client->fd, "ko");
      return (EXIT_FAILURE);
    }
  if (my_write(client->fd, "elevation en cours") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_pic_gfx(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  //temps d'incation
  if (cmd_end_incantation(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}


int			cmd_end_incantation(t_serv *serv, t_client *client)
{
  if (client->lvl == 8 || serv->inc_lvl[client->lvl](serv, client) == EXIT_FAILURE)
    {
      if (write_pie_gfx(serv->gfx, client, 0) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      my_write(client->fd, "ko");
      return (EXIT_FAILURE);
    }
  empty_block(&(serv->map->blocks[client->x][client->y]));
  if (write_bct_gfx(serv->gfx, &(serv->map->blocks[client->x][client->y])) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  // faire pop des ressources
  if (write_pie_gfx(serv->gfx, client, 1) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (up_players(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
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

int			inc_lvl1(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  puts("inc_lvl1");
  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  printf("lvl : %d\n", client->lvl);
  if (client->lvl == 1 && item[0] == 0 && item[1] == 1 && item[2] == 0 &&
      item[3] == 0 && item[4] == 0 && item[5] == 0 && item[6] == 0)
    {
      puts("Ressources ok");
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 1)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 1 && nb_lvl == 1)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			inc_lvl2(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  if (client->lvl == 2 && item[0] == 0 && item[1] == 1 && item[2] == 1 &&
      item[3] == 1 && item[4] == 0 && item[5] == 0 && item[6] == 0)
    {
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 2)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 2 && nb_lvl == 2)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			inc_lvl3(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  if (client->lvl == 3 && item[0] == 0 && item[1] == 2 && item[2] == 0 &&
      item[3] == 1 && item[4] == 0 && item[5] == 2 && item[6] == 0)
    {
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 3)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 2 && nb_lvl == 2)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			inc_lvl4(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  if (client->lvl == 4 && item[0] == 0 && item[1] == 1 && item[2] == 1 &&
      item[3] == 2 && item[4] == 0 && item[5] == 1 && item[6] == 0)
    {
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 4)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 4 && nb_lvl == 4)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			inc_lvl5(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  if (client->lvl == 5 && item[0] == 0 && item[1] == 1 && item[2] == 2 &&
      item[3] == 1 && item[4] == 3 && item[5] == 0 && item[6] == 0)
    {
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 5)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 4 && nb_lvl == 4)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			inc_lvl6(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  if (client->lvl == 6 && item[0] == 0 && item[1] == 1 && item[2] == 2 &&
      item[3] == 3 && item[4] == 0 && item[5] == 1 && item[6] == 0)
    {
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 6)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 6 && nb_lvl == 6)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			inc_lvl7(t_serv *serv, t_client *client)
{
  int			*item;
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  item = serv->map->blocks[client->x][client->y].items;
  if (client->lvl == 7 && item[0] == 0 && item[1] == 2 && item[2] == 2 &&
      item[3] == 2 && item[4] == 2 && item[5] == 2 && item[6] == 1)
    {
      while (tmp != NULL)
	{
	  if (tmp->x == client->x && tmp->y == client->y)
	    {
	      nb_player++;
	      if (tmp->lvl == 7)
		nb_lvl++;
	    }
	  tmp = tmp->next;
	}
      if (nb_player == 6 && nb_lvl == 6)
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
