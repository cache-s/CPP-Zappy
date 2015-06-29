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

void			look_floor(int x, int y, t_serv *serv, t_client *client)
{
  int			i;
  int			tmp_i;
  int			check;
  
  i = 0;
  check = 0;
  while (i < 7)
    {
      tmp_i = serv->map->blocks[x][y].items[i];
      if (serv->map->blocks[x][y].items[i] != 0)
	{
	  if (tmp_i > 1)
	    {
	      while (tmp_i != 0)
		{
		  dprintf(client->fd, "%i ", i);
		  tmp_i--;
		}
	    }
	  else
	    {
	      if (check == 1)
		dprintf(client->fd, "%i ", i);
	      else
		dprintf(client->fd, "%i", i);
	    }
	  check = 1;
	}
      i++;
    }
  dprintf(client->fd, ",");
}

void			see_with_orientation(t_serv *serv, t_client *client)
{
  int			tmp_x_left;
  int			tmp_x_right;
  int			tmp_y;
  int			j;

  tmp_x_left = client->x;
  tmp_x_right = client->x;
  tmp_y = client->y;
  tmp_y = tmp_y + 1;
  tmp_x_left = tmp_x_left - 1;
  tmp_x_right = tmp_x_right + 1;     
  j = tmp_x_left;
  dprintf(client->fd, "<j = %i>",j);
  dprintf(client->fd, "<x = %i>",tmp_x_right);
  while (j != tmp_x_right)
    {
      look_floor(j, tmp_y, serv, client); 
      j++;
    }
}

int			cmd_see(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  int			i;
  int			lvl;
  
  dprintf(client->fd, "{");
  lvl = 2;
  i = 1;
  look_floor(client->x, client->y, serv, client);
  while (i <= lvl)
    {
      see_with_orientation(serv, client);
      i++;
    }
  dprintf(client->fd, "}\n");
  return (EXIT_SUCCESS);
}
