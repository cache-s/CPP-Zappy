/*
** parsing.c for  in /home/bourma_m/Projet/SystemUnix/elcrypt
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sat Mar 14 18:00:43 2015 Mathieu Bourmaud
** Last update Sun Mar 15 20:38:55 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			fill_port(t_settings *settings, char *arg, int i)
{
  if (arg == NULL)
    return (my_error(BOLD RED ERR_PORT END));
  settings->port = atoi(arg);
  if (settings->port == 0 || strlen(arg) > 4)
    return (my_error(BOLD RED ERR_PORT END));
  return (i + 1);
}

int			fill_width(t_settings *settings, char *arg, int i)
{
  if (arg == NULL)
    return (my_error(BOLD RED ERR_WIDTH END));
  settings->width = atoi(arg);
  return (i + 1);
}

int			fill_height(t_settings *settings, char *arg, int i)
{
  if (arg == NULL)
    return (my_error(BOLD RED ERR_HEIGHT END));
  settings->height = atoi(arg);
  return (i + 1);
}

int			fill_teams(t_settings *settings, char **args, int i)
{
  int			j;

  j = 0;
  i += 1;
  if (args[i] == NULL)
    return (my_error(BOLD RED ERR_TEAM END));
  settings->teams = strdup(args[i]);
  if ((settings->teams = realloc(settings->teams, strlen(settings->teams) \
				 + strlen(";") + 1)) == NULL)
    return (my_error(ERR_REALLOC));
  settings->teams = strcat(settings->teams, ";");
  i += 1;
  while (args[i] != NULL)
    {
      if (args[i][0] == '-')
	return (i - 1);
      if ((settings->teams = realloc(settings->teams, strlen(settings->teams) \
			    + strlen(args[i]) + strlen(";") + 1)) == NULL)
  	return (my_error(ERR_REALLOC));
      settings->teams = strcat(settings->teams, args[i]);
      settings->teams = strcat(settings->teams, ";");
      i++;
      j++;
    }
  if (fill_teams_tabs(settings) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (i);
}

int			fill_teams_tabs(t_settings *settings)
{
  int			i;

  i = 0;
  if ((settings->clients = malloc(sizeof(int) * \
			 count_char(settings->teams, ';') + 1)) == NULL)
    return (my_error(ERR_MALLOC));
  while (settings->clients[i])
    {
      settings->clients[i] = 0;
      i++;
    }
  return (EXIT_SUCCESS);
}

int			fill_nb_clients(t_settings *settings, char *arg, int i)
{
  if (arg == NULL)
    return (my_error(BOLD RED ERR_NB_CLIENTS END));
  settings->nb_clients = atoi(arg);
  return (i + 1);
}

int			fill_delay(t_settings *settings, char *arg, int i)
{
  if (arg == NULL)
    return (my_error(BOLD RED ERR_DELAY END));
  settings->delay = atof(arg);
  return (i + 1);
}

