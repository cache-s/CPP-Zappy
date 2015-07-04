/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:20:43 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

void			check_player(int x, int y, t_serv *serv, t_client *client)
{
  t_client		*tmp;

  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp->x == x && tmp->y == y)
	dprintf(client->fd, " joueur");
      tmp = tmp->next;
    }
}

int			look_floor(int x, int y, t_serv *serv, t_client *client)
{
  int			i;
  int			tmp_i;

  i = 0;
  tmp_i = 0;
  check_player(x, y, serv, client);
  while (i < 7)
    {
      tmp_i = serv->map->blocks[x][y].items[i];
      if (serv->map->blocks[x][y].items[i] != 0)
	{
	  while (tmp_i != 0)
	    {
	      dprintf(client->fd, " %s", serv->items[i]);
	      tmp_i--;
	    }
	}
      i++;
    }
  if (serv->see->end != 1)
    dprintf(client->fd, ",");
  return (EXIT_SUCCESS);
}

void			init_see(t_serv *serv)
{
  serv->see->tmp_x_plus = 0;
  serv->see->tmp_x_less = 0;
  serv->see->tmp_y_plus = 0;
  serv->see->tmp_y_less = 0;
  serv->see->coma = 0;
  serv->see->end = 0;
  serv->see->check = 0;
}

int			cmd_see(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  int			i;

  i = 1;
  if ((serv->see = malloc(sizeof(* serv->see))) == NULL)
    return (my_error(ERR_MALLOC));
  init_see(serv);
  dprintf(client->fd, "{");
  look_floor(client->x, client->y, serv, client);
  while (i <= client->lvl)
    {
      serv->see->coma++;
      see_with_orientation(serv, client);
      i++;
    }
  dprintf(client->fd, "}\n");
  printf(BOLD RED "Sending 'Res of voir' to %d\n", client->fd); 
  return (EXIT_SUCCESS);
}
