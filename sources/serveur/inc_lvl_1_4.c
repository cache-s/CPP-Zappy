/*
** inc_lvl_1_4.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:24:04 2015 Martin Porrès
** Last update Fri Jul  3 11:25:22 2015 Martin Porrès
*/

#include	"serveur.h"

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
