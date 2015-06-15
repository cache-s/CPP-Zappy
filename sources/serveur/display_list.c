/*
** display_list.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myirc
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sat Apr 11 19:07:43 2015 Mathieu Bourmaud
** Last update Sat Apr 11 19:08:15 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			display_liststart(t_client *client)
{
  if (write(client->fd, RPL_LISTSTART, strlen(RPL_LISTSTART)) == -1)
    return (EXIT_FAILURE);
  if (write(client->fd, " ", 1) == -1)
    return (EXIT_FAILURE);
  if (write(client->fd, client->nick, strlen(client->nick)) == -1)
    return (EXIT_FAILURE);
  if (write(client->fd, " ", 1) == -1)
    return (EXIT_FAILURE);
  if (my_write(client->fd, N321) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			display_listend(t_client *client)
{
  if (write(client->fd, RPL_LISTEND, strlen(RPL_LISTEND)) == -1)
    return (EXIT_FAILURE);
  if (write(client->fd, " ", 1) == -1)
    return (EXIT_FAILURE);
  if (write(client->fd, client->nick, strlen(client->nick)) == -1)
    return (EXIT_FAILURE);
  if (write(client->fd, " ", 1) == -1)
    return (EXIT_FAILURE);
  if (my_write(client->fd, N323) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			display_list(char **list, t_client *client, int *users)
{
  int			i;

  i = 0;
  if (display_liststart(client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (list[i])
    {
      if (write(client->fd, RPL_LIST, strlen(RPL_LIST)) == -1)
	return (EXIT_FAILURE);
      if (write(client->fd, " ", 1) == -1)
	return (EXIT_FAILURE);
      if (write(client->fd, client->nick, strlen(client->nick)) == -1)
	return (EXIT_FAILURE);
      if (write(client->fd, " ", 1) == -1)
	return (EXIT_FAILURE);
      if (write(client->fd, list[i], strlen(list[i])) == -1)
	return (EXIT_FAILURE);
      dprintf(client->fd, " %d :\n", users[i]);
      i++;
    }
  if (display_listend(client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
