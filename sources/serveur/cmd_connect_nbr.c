/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Sat Jun 27 20:58:59 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_connect_nbr(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  t_client		*tmp;
  int			i;
  char			*value;

  i = 0;
  tmp = serv->client;
  if (client->team == NULL)
    { // A VIRER QUAND MT AURA SET LES TEAMS
      puts("CACA");
      return (EXIT_FAILURE);
    }
  while (tmp != NULL)
    {
      if (tmp->team != NULL && strcmp(tmp->team, client->team) == 0)
	i++;
      tmp = tmp->next;
    }
  if ((value = itoa(serv->settings->nb_clients - i)) == NULL)
    return (EXIT_FAILURE);
  i = EXIT_SUCCESS;
  if (my_write(client->fd, value) == EXIT_FAILURE)
    i = EXIT_FAILURE;
  free(value);
  return (i);
}
