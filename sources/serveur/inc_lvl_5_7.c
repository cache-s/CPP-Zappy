/*
** inc_lvl_5_7.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:25:46 2015 Martin Porrès
** Last update Fri Jul  3 11:26:16 2015 Martin Porrès
*/

#include	"serveur.h"

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
