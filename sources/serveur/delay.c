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

int			get_the_shortest_cmd(t_serv *serv)
{
  t_client		*tmp;
  char			*cmd_save;
  char			*token;
  double		last_value;
  double		new_value;

  last_value = -42;
  tmp = serv->client;
  while (tmp != NULL)
    {
      if (tmp->cmd != NULL)
	{
	  if (tmp->shortest_cmd == NULL)
	    {
	      cmd_save = strdup(tmp->cmd);
	      token = strtok(cmd_save, ";");
	      new_value = get_delay(serv, token);
	      tmp->shortest_cmd = strdup(token);
	      tmp->time_left = new_value;
	      printf("client [%d] = CMD NULL\n", tmp->fd);
	      printf("CLIENT [%d] = time left = %f\n", tmp->fd, tmp->time_left);
	    }
	  else
	    {
	      printf("CLIENT [%d] = time left = %f\n", tmp->fd, tmp->time_left);
	      new_value = tmp->time_left;
	      printf("client [%d] = CMD NON NULL\n", tmp->fd);
	    }
	  printf("CLIENT [%d] = time left = %f\n", tmp->fd, tmp->time_left);
	  if (last_value > new_value || last_value == -42)
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
  printf("GET_DELAY = {%f}\n", serv->cmd_time[pos] / serv->settings->delay); 
  return (serv->cmd_time[pos] / serv->settings->delay);
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
  serv->cmd_time[9] = 300;
  serv->cmd_time[10] = 42;
  serv->cmd_time[11] = 0;
}

int			update_timers(t_serv *serv, struct timeval *tv, double time)
{
  t_client		*tmp;
  double		elapsed;

  /* printf("tv->tv_usec = %d, tv->sec = %d\n", (int)tv->tv_usec, (int)tv->tv_sec); */
  tmp = serv->client;
  elapsed = (time * 1000000) - (tv->tv_usec + (tv->tv_sec * 1000000));
  printf("elapsed = %f\n", elapsed);
  while (tmp != NULL)
    {
      tmp->time_left -= elapsed / 1000000;
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

int			update_client(t_client *client, t_serv *serv)
{
  (void)serv;
  printf("client->cmd = %s\n", client->cmd);
  client->cmd = strtok(client->cmd, strcat(client->shortest_cmd, ";"));
  printf("client->cmd = %s\n", client->cmd);
  if (client->shortest_cmd != NULL)
    free(client->shortest_cmd);
  client->shortest_cmd = NULL;
  client->need_write = 0;
  return (EXIT_SUCCESS);
} 
