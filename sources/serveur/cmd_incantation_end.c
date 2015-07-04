/*
** cmd_incantation_end.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:24:04 2015 Martin Porrès
** Last update Fri Jul  3 14:50:49 2015 Martin Porrès
*/

#include	"serveur.h"

int			inc_lvl(t_serv *serv, t_client *client)
{
  int			*item;

  if (client->lvl > 7)
    return (EXIT_FAILURE);
  item = serv->map->blocks[client->x][client->y].items;
  if (item[0] == 0 && item[1] == serv->inc_tab[client->lvl][1] && item[2] ==
      serv->inc_tab[client->lvl][2] && item[3] ==
      serv->inc_tab[client->lvl][3]
      && item[4] == serv->inc_tab[client->lvl][4] && item[5] ==
      serv->inc_tab[client->lvl][5] && item[6] ==
      serv->inc_tab[client->lvl][6])
    return (inc_count_player(serv, client));
  return (EXIT_FAILURE);
}

int			inc_count_player(t_serv *serv, t_client *client)
{
  int			nb_player;
  int			nb_lvl;
  t_client		*tmp;

  nb_player = 0;
  nb_lvl = 0;
  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp->x == client->x && tmp->y == client->y)
	{
	  nb_player++;
	  if (tmp->lvl == client->lvl)
	    nb_lvl++;
	}
      tmp = tmp->next;
    }
  if (nb_player == serv->inc_tab[client->lvl][0] && nb_lvl ==
      serv->inc_tab[client->lvl][0])
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

void			init_inc_tab(t_serv *serv)
{
  serv->inc_tab[0][0] = 0;
  serv->inc_tab[0][1] = 0;
  serv->inc_tab[0][2] = 0;
  serv->inc_tab[0][3] = 0;
  serv->inc_tab[0][4] = 0;
  serv->inc_tab[0][5] = 0;
  serv->inc_tab[0][6] = 0;
  serv->inc_tab[1][0] = 1;
  serv->inc_tab[1][1] = 1;
  serv->inc_tab[1][2] = 0;
  serv->inc_tab[1][3] = 0;
  serv->inc_tab[1][4] = 0;
  serv->inc_tab[1][5] = 0;
  serv->inc_tab[1][6] = 0;
  serv->inc_tab[2][0] = 2;
  serv->inc_tab[2][1] = 1;
  serv->inc_tab[2][2] = 1;
  serv->inc_tab[2][3] = 1;
  serv->inc_tab[2][4] = 0;
  serv->inc_tab[2][5] = 0;
  serv->inc_tab[2][6] = 0;
  init_inc_tab_2(serv);
}

void			init_inc_tab_2(t_serv *serv)
{
  serv->inc_tab[3][0] = 2;
  serv->inc_tab[3][1] = 2;
  serv->inc_tab[3][2] = 0;
  serv->inc_tab[3][3] = 1;
  serv->inc_tab[3][4] = 0;
  serv->inc_tab[3][5] = 2;
  serv->inc_tab[3][6] = 0;
  serv->inc_tab[4][0] = 4;
  serv->inc_tab[4][1] = 1;
  serv->inc_tab[4][2] = 1;
  serv->inc_tab[4][3] = 2;
  serv->inc_tab[4][4] = 0;
  serv->inc_tab[4][5] = 1;
  serv->inc_tab[4][6] = 0;
  serv->inc_tab[5][0] = 4;
  serv->inc_tab[5][1] = 1;
  serv->inc_tab[5][2] = 2;
  serv->inc_tab[5][3] = 1;
  serv->inc_tab[5][4] = 3;
  serv->inc_tab[5][5] = 0;
  serv->inc_tab[5][6] = 0;
  serv->inc_tab[6][0] = 6;
  serv->inc_tab[6][1] = 1;
  serv->inc_tab[6][2] = 2;
  serv->inc_tab[6][3] = 3;
  serv->inc_tab[6][4] = 0;
  serv->inc_tab[6][5] = 1;
  serv->inc_tab[6][6] = 0;
  init_inc_tab_3(serv);
}

void			init_inc_tab_3(t_serv *serv)
{
  serv->inc_tab[7][0] = 6;
  serv->inc_tab[7][1] = 2;
  serv->inc_tab[7][2] = 2;
  serv->inc_tab[7][3] = 2;
  serv->inc_tab[7][4] = 2;
  serv->inc_tab[7][5] = 2;
  serv->inc_tab[7][6] = 1;
}
