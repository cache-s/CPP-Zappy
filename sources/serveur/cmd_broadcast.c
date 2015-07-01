/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Tue Jun 30 19:12:53 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_broadcast(t_serv *serv, t_client *client, char *cmd)
{
  t_client		*tmp;
  int			k;
  int			ret;

  ret = EXIT_SUCCESS;
  if (write_pbc_gfx(serv->gfx, client, cmd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp != client)
	{
	  k = get_k(serv->settings, client, tmp);
	  if (dprintf(tmp->fd, "message %d, %s\n", k, cmd) == -1)
	    ret = EXIT_FAILURE;
	}
      tmp = tmp->next;
    }
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /*
    Broadcast (Communication)
    "pbc #n M\n"

    Boucle qui parcourt toute la liste des joueurs et leur envoie le message
    
    Send to GFX : pbc, player number, message
    Send to IA : ok
   */
  return (ret);
}

int			get_k(t_settings *settings, t_client *speaker, t_client *listener)
{
  int			x;
  int			y;
  int			o;

  x = find_closest_path(settings->width, speaker->x, listener->x);
  y = find_closest_path(settings->height, speaker->y, listener->y);
  if ((o = set_path_orientation(x, y)) == 0)
    return (0);
  return (set_real_orientation(o, listener->orientation));
}

int			find_closest_path(int map_size, int speaker, int listener)
{
  int			west_north;
  int			est_south;

  if (speaker > listener)
    {
      est_south = speaker - listener;
      west_north = map_size - (speaker - listener);
    }
  else
    {
      west_north = listener - speaker;
      est_south = map_size - (listener - speaker);
    }
  if (west_north < est_south)
    {
      puts("WEST NORTH");
      return (west_north);
    }
  else
    {
      puts("EST SOUTH");
      return (est_south * -1);
    }
}

int			set_path_orientation(int x, int y)
{
  int			base;
  
  if (x == 0 && y == 0)
    return (0);
  if ((x > 0 && y < 0) || (x < 0 && y > 0)) //x < y
    {
      if (x > 0 && y < 0)
	{
	  puts("WEST SOUTH");
	  base = 3;
	  return (find_best_orientation(abs(x), abs(y), base));
	}
      puts("EST NORTH");
      base = 7;
      return (find_best_orientation(abs(x), abs(y), base));
    }
  if (x > 0 && y > 0)
    {
      puts("WEST NORTH");
      base = 1;
      return (find_best_orientation(abs(y), abs(x), base));
    }
  puts("EST SOUTH");
  base = 5;
  return (find_best_orientation(abs(y), abs(x), base));
}

int		        find_best_orientation(int x, int y, int base)
{
  if (x > y) //24 > 2
    {
      if (y == 0)
	return (base);
      if (x > (y * (4 / 3))) // 22 > 12
	return (base);
      return (base + 1);
    }
  if (y < (x * (4 / 3)))
    return (base + 1);
  if (base + 2 > 8)
    return (1);
  return (base + 2);
}

int			set_real_orientation(int o, eOrientation client_o)
{
  if (client_o == EST)
    o += 2;
  if (client_o == SOUTH)
    o += 4;
  if (client_o == WEST)
    o += 6;
  if (o > 8)
    o -= 8;
  return (o);
}

  //si pos > 0 -> WEST_NORTH else EST_SOUTH
