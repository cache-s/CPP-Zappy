/*
** updates.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jul  5 20:00:27 2015 Mathieu
** Last update Sun Jul  5 20:00:27 2015 Mathieu
*/

#include		"serveur.h"

int			update_fork_incant(t_serv *serv, int elapsed, t_client *tmp)
{
  if (tmp->incanting)
    {
      tmp->incant_time -= elapsed / 1000000;
      if (tmp->incant_time <= 0)
	if (cmd_end_incantation(serv, tmp) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
    }
  if (tmp->forking)
    {
      tmp->fork_time -= elapsed / 1000000;
      if (tmp->fork_time <= 0)
	if (cmd_fork(serv, tmp, NULL) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			check_death(t_serv *serv, t_client *tmp)
{
  if (tmp->heart_perc > (126 / (double)serv->settings->delay) * 1000000)
    {
      tmp->items[0] -= 1;
      tmp->heart_perc -= ((126 / (double)serv->settings->delay) * 1000000);
    }
  if (tmp->items[0] <= 0)
    {
      printf(RED BOLD "Sending mort to %d\n" END, tmp->fd);
      if (my_write(tmp->fd, "mort") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      close_connect(serv, tmp->fd, 0);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			update_timers(t_serv *serv, struct timeval *tv, double time)
{
  t_client		*tmp;
  double		elapsed;

  tmp = serv->client;
  elapsed = (time * 1000000) - (tv->tv_usec + (tv->tv_sec * 1000000));
  while (tmp != NULL)
    {
      if (elapsed < 0)
	elapsed = 0;
      tmp->time_left -= elapsed / 1000000;
      tmp->heart_perc += elapsed;
      update_fork_incant(serv, elapsed, tmp);
      check_death(serv, tmp);
      if (tmp->time_left <= 0)
	tmp->time_left = 0;
      if ((int)tmp->time_left == 0 && tmp->shortest_cmd != NULL)
      	{
	  tmp->need_write = 1;
      	  tmp->time_left = 0;
	  FD_SET(serv->socket, &serv->writefds);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int			update_client(t_client *client, UNUSED t_serv *serv)
{
  char			*new_cmd;
  int			len;
  int			len_s;
  char			*save_cmd;

  if (client->cmd == NULL)
    return (EXIT_SUCCESS);
  save_cmd = strdup(client->cmd);
  len = strlen(client->cmd);
  strtok(client->cmd, ";");
  len_s = strlen(client->cmd) + 1;
  if ((new_cmd = malloc(len - len_s + 1)) == NULL)
    return (my_error(ERR_MALLOC));
  new_cmd = str_cpy_from(new_cmd, save_cmd, len_s);
  client->cmd = strdup(new_cmd);
  if (count_char(client->cmd, ';') < 1)
    client->cmd = NULL;
  if (client->shortest_cmd != NULL)
    free(client->shortest_cmd);
  client->shortest_cmd = NULL;
  client->need_write = 0;
  return (EXIT_SUCCESS);
}
