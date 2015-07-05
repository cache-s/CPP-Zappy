/*
** fill_settings2.c for  in /home/poupon_d/Rendu/PSU_2014_zappy
** 
** Made by poupon_d
** Login   <poupon_d@epitech.net>
** 
** Started on  Sun Jul  5 22:53:15 2015 poupon_d
** Last update Sun Jul  5 22:53:15 2015 poupon_d
*/

#include		"serveur.h"

int			fill_teams(t_settings *settings, char **args, int i)
{
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
