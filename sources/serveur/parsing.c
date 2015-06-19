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

void			init_settings(t_settings *settings)
{
  /* bzero(settings->parser.occArgs, MAX_ARGS * sizeof(int)); */
  strcpy(settings->parser.tabArgs[0], "-p");
  strcpy(settings->parser.tabArgs[1], "-x");
  strcpy(settings->parser.tabArgs[2], "-y");
  strcpy(settings->parser.tabArgs[3], "-n");
  strcpy(settings->parser.tabArgs[4], "-c");
  strcpy(settings->parser.tabArgs[5], "-t");
  settings->parser.args[0] = fill_port;
  settings->parser.args[1] = fill_width;
  settings->parser.args[2] = fill_height;
  settings->parser.args[3] = fill_teams;
  settings->parser.args[4] = fill_nb_clients;
  settings->parser.args[5] = fill_delay;
}

int			get_pos_in_tab(t_settings *settings, char *cmd)
{
  int			i;

  i = 0;
  while (i < (MAX_ARGS - 2))
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

char			**getTeams(char **args)
{
  return (args);
}

int			parse_args(char **av)
{
  int			i;
  int			pos;
  t_settings		settings;

  init_settings(&settings);
  i = 0;
  while (i < MAX_ARGS)
    {
      pos = get_pos_in_tab(&settings, av[i]);
      if (pos != 42)
      	i = settings.parser.args[pos](&settings, av[i + 1], i);
      if (pos == 3)
	i = settings.parser.args[pos](&settings, av, i);
      i++;
    }
  if ((check_values(&settings) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			check_values(t_settings *settings)
{
  int			i;
  int			occ;

  i = 0;
  occ = 0;
  while (i < (MAX_ARGS - 2))
    {
      if (settings->parser.occArgs[0] != 0 && settings->parser.occArgs[1] != 0)
	return (my_error("test"));
      if (settings->parser.occArgs[i] > 1)
	return (my_error("test"));
      if (settings->parser.occArgs[i] != 0)
	occ++;
      i++;
    }
  if (occ != 4)
    return (my_error("toto"));
  return (EXIT_SUCCESS);
}
