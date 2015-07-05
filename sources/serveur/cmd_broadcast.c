/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Fri Jul  3 11:37:03 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_broadcast(t_serv *serv, t_client *client,
				      char *cmd)
{
  t_client		*tmp;
  int			k;
  int			ret;

  printf("CMD={%s}\n", cmd);
  ret = EXIT_SUCCESS;
  if (write_pbc_gfx(serv->gfx, client, cmd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp != client)
	{
	  k = get_k(serv->settings, client, tmp);
	  printf("Sending '%d, %s' to %d\n", k, cmd, tmp->fd);
	  if (dprintf(tmp->fd, "message %d, %s\n", k, cmd) == -1)
	    ret = EXIT_FAILURE;
	}
      tmp = tmp->next;
    }
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (ret);
}

int			get_k(t_settings *settings, t_client *speaker,
			      t_client *listener)
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

int			find_closest_path(int map_size, int speaker,
					  int listener)
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
    return (west_north);
  else
    return (est_south * -1);
}
