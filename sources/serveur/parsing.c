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

int			init_settings(t_settings *settings)
{
  if ((settings->parser.occArgs = malloc(sizeof(int) * MAX_ARGS + 1)) == NULL)
    return (my_error(ERR_MALLOC));
  if ((settings->parser.tabArgs = malloc(sizeof(char *) * \
					 MAX_ARGS + 1)) == NULL)
    return (my_error(ERR_MALLOC));
  if ((settings->teams = malloc(sizeof(char *) * 2)) == NULL)
    return (my_error(ERR_MALLOC));
  bzero(settings->parser.occArgs, MAX_ARGS * sizeof(int));
  settings->parser.tabArgs[0] = strdup("-p");
  settings->parser.tabArgs[1] = strdup("-x");
  settings->parser.tabArgs[2] = strdup("-y");
  settings->parser.tabArgs[3] = strdup("-n");
  settings->parser.tabArgs[4] = strdup("-c");
  settings->parser.tabArgs[5] = strdup("-t");
  init_tab_settings(settings);
  settings->port = 4242;
  settings->width = 50;
  settings->height = 50;
  settings->teams = strdup("Team1;Team2;");
  settings->nb_clients = 200;
  settings->delay = 100;
  return (EXIT_SUCCESS);
}

int			init_tab_settings(t_settings *settings)
{
  settings->parser.args[0] = fill_port;
  settings->parser.args[1] = fill_width;
  settings->parser.args[2] = fill_height;
  settings->parser.args[3] = fill_teams;
  settings->parser.args[4] = fill_nb_clients;
  settings->parser.args[5] = fill_delay;
  return (EXIT_SUCCESS);
}

int			get_pos_in_tab(t_settings *settings, char *cmd)
{
  int			i;

  i = 0;
  if (cmd == NULL)
    return (42);
  while (i < MAX_ARGS)
    {
      if (strcmp(cmd, settings->parser.tabArgs[i]) == 0)
	{
	  settings->parser.occArgs[i] += 1;
	  return (i);
	}
      i++;
    }
  return (42);
}

t_settings		*parse_args(char **av)
{
  int			i;
  int			pos;
  t_settings		*settings;

  i = 0;
  if ((settings = malloc(sizeof(t_settings) + 1)) == NULL)
    return (NULL);
  if (init_settings(settings) == EXIT_FAILURE)
    return (NULL);
  while (av[i])
    {
      pos = get_pos_in_tab(settings, av[i]);
      if (pos != 42 && pos != 3)
      	if ((i = settings->parser.args[pos](settings, av[i + 1], i))
	    == EXIT_FAILURE)
	  return (NULL);
      if (pos == 3)
	if ((i = settings->parser.args[pos](settings, av, i)) == EXIT_FAILURE)
	  return (NULL);
      i++;
    }
  if ((check_values(settings) == EXIT_FAILURE))
    return (NULL);
  return (settings);
}
