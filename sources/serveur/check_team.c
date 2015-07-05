/*
** check_team.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jun 28 18:23:25 2015 Mathieu
** Last update Thu Jul  2 18:07:04 2015 Martin Porrès
*/

#include		"serveur.h"

int			check_team(t_serv *serv, t_client *client, char *cmd)
{
  int			pos;

  pos = 0;
  cmd = strtok(cmd, "\n");
  printf(BOLD BLUE "Received message '%s' from %d\n" END, cmd, client->fd);
  if (cmd == NULL)
    return (EXIT_FAILURE);
  if (strcmp(cmd, "GRAPHIC") == 0)
    return (cmd_graphic(serv, client, cmd));
  if (strstr(serv->settings->teams, cmd) != NULL)
    {
      client->team = strdup(cmd);
      client->connected = 1;
      pos = get_team_pos(serv, cmd);
      client->team_pos = pos;
      serv->settings->clients[pos] += 1;
      if (serv->settings->clients[pos] > serv->settings->nb_clients)
      	{
	  printf(BOLD RED "Received message '%s' from %d\n" END, "ko", client->fd);
      	  if (my_write(client->fd, "ko") == EXIT_FAILURE)
      	    return (EXIT_FAILURE);
      	  serv->settings->clients[pos] = serv->settings->nb_clients;
      	}
      dprintf(client->fd, "%d\n", serv->settings->nb_clients -
	      serv->settings->clients[pos]);
      dprintf(client->fd, "%d %d\n", client->x, client->y);
      if (write_pnw_gfx(serv->gfx, client) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (generate_all_item(serv, 1) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (generate_random_item(serv, 0, 4) ==  EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      printf(BOLD RED "Received message '%s' from %d\n" END, "ko", client->fd);
      if (my_write(client->fd, "ko") == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
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
      token = strtok(NULL, ";");
      i++;
    }
  return (i);
}

int			check_teams(t_settings *settings)
{
  int			occ;
  char			*saveptr;
  char			*tmp;
  char			*token;
  char			*save;

  occ = 0;
  tmp = strdup(settings->teams);
  save = strdup(settings->teams);
  token = strtok_r(tmp, ";", &saveptr);
  while (token != NULL)
    {
      save = strdup(settings->teams);
      while ((save = strstr(save, token)) != NULL)
	{
	  occ++;
	  save++;
	}
      token = strtok_r(NULL, ";", &saveptr);
    }
  if (occ > count_char(settings->teams, ';'))
    return (my_error(BOLD RED ERR_UNIQUE_TEAM END));
  if (count_char(settings->teams, ';') < 2)
    return (my_error(BOLD RED ERR_NB_TEAMS END));
  return (EXIT_SUCCESS);
}

int			check_values(t_settings *settings)
{
  if (settings->delay < 1 || settings->delay > MAX_SPEED)
    return (my_error(BOLD RED ERR_SPEED END));
  if (settings->width < MIN_X || settings->width > MAX_X)
    return (my_error(BOLD RED ERR_SIZE_X END));
  if (settings->height < MIN_Y || settings->height > MAX_Y)
    return (my_error(BOLD RED ERR_SIZE_X END));
  if (check_teams(settings) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
