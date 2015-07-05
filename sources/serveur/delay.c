/*
** delay.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Tue Jun 30 17:05:40 2015 Mathieu
** Last update Tue Jun 30 17:05:40 2015 Mathieu
*/

#include		"serveur.h"

void			set_value(t_serv *serv, double *new_value, t_client *tmp)
{
  char			*cmd_save;
  char			*token;

  cmd_save = strdup(tmp->cmd);
  if ((token = strtok(cmd_save, ";")) != NULL)
    {
      *new_value = get_delay(serv, token);
      tmp->shortest_cmd = strdup(token);
      tmp->time_left = *new_value;
    }
}

double			get_the_shortest_cmd(t_serv *serv)
{
  t_client		*tmp;
  double		last_value;
  double		new_value;

  last_value = 126 / (double)serv->settings->delay;
  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp->cmd != NULL)
	{
	  if (tmp->shortest_cmd == NULL)
	    set_value(serv, &new_value, tmp);
	  else
	    new_value = tmp->time_left;
	  if (last_value > new_value)
	    last_value = new_value;
	}
      tmp = tmp->next;
    }
  return (last_value);
}

double			get_delay(t_serv *serv, char *cmd)
{
  int			pos;

  pos = call_cmds(serv, cmd);
  return ((double)serv->cmd_time[pos] / (double)serv->settings->delay);
}

void			set_delay_tab(t_serv *serv)
{
  serv->cmd_time[0] = 7;
  serv->cmd_time[1] = 7;
  serv->cmd_time[2] = 7;
  serv->cmd_time[3] = 7;
  serv->cmd_time[4] = 1;
  serv->cmd_time[5] = 7;
  serv->cmd_time[6] = 7;
  serv->cmd_time[7] = 7;
  serv->cmd_time[8] = 7;
  serv->cmd_time[9] = 0;
  serv->cmd_time[10] = 0;
  serv->cmd_time[11] = 0;
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
