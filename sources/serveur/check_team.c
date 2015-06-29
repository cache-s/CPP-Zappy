/*
** check_team.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jun 28 18:23:25 2015 Mathieu
** Last update Sun Jun 28 18:23:25 2015 Mathieu
*/

#include		"serveur.h"

int			check_team(t_serv *serv, t_client *client, char *cmd)
{
  int			pos;

  pos = 0;
  cmd = strtok(cmd, "\n");
  if (strcmp(cmd, "GRAPHIC") == 0)
    return (cmd_graphic(serv, client, cmd));
  printf("%s %s\n", cmd, serv->settings->teams);
  if (strstr(serv->settings->teams, cmd) != NULL)
    {
      client->team = strdup(cmd);
      client->connected = 1;
      if (my_write(client->fd, "ok") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      pos = get_team_pos(serv, cmd);
      printf("%d\n", pos);
      /* serv->settings->clients[pos] += 1; */
      /* if (serv->settings->clients[pos] > serv->settings->nb_clients) */
      /* 	{ */
      /* 	  if (my_write(client->fd, "ko") == EXIT_FAILURE) */
      /* 	    return (EXIT_FAILURE); */
      /* 	  serv->settings->clients[pos] = serv->settings->nb_clients; */
      /* 	} */
      /* dprintf(client->fd, "%d\n", serv->settings->nb_clients - serv->settings->clients[pos]); */
      /* dprintf(client->fd, "%d %d\n", client->x, client->y); */
    }
  else  
    if (my_write(client->fd, "ko") == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			get_team_pos(t_serv *serv, char *team)
{
  char			*str;
  char			*token;
  int			i;

  i = 0;
  str = strdup(serv->settings->teams);
  token = strtok(str, ";");
  while (token != NULL)
    {
      if (strcmp(token, team) == 0)
	return (i);
      token = strtok(str, ";");
      i++;
    }
  return (i);
}
