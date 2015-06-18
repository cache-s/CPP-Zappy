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
  bzero(crypt->parser.occArgs, MAX_ARGS * sizeof(int));
  strcpy(crypt->parser.tabArgs[0], "-p");
  strcpy(crypt->parser.tabArgs[1], "-x");
  strcpy(crypt->parser.tabArgs[2], "-y");
  strcpy(crypt->parser.tabArgs[3], "-n");
  strcpy(crypt->parser.tabArgs[4], "-c");
  strcpy(crypt->parser.tabArgs[5], "-t");
  crypt->parser.args[0] = fill_port;
  crypt->parser.args[1] = fill_width;
  crypt->parser.args[2] = fill_height;
  crypt->parser.args[3] = fill_teams;
  crypt->parser.args[4] = fill_nb_clients;
  crypt->parser.args[5] = fill_delay;
}

int			get_pos_in_tab(t_settings *settings, char *cmd)
{
  int			i;

  i = 0;
  while (i < (MAX_ARGS - 2))
    {
      if (strcmp(cmd, crypt->parser.tabArgs[i]) == 0)
	{
	  crypt->parser.occArgs[i] += 1;
	  return (i);
	}
      i++;
    }
  return (42);
}

char			**getTeams(char **args)
{
  
}

int			parse_args(char **av)
{
  int			i;
  int			pos;
  t_settings		settings;

  init_settings(&settings);
  i = 0;
  while (i < 8)
    {
      pos = get_pos_in_tab(&settings, av[i]);
      if (pos != 42)
      	i = crypt.parser.args[pos](&crypt, av[i + 1], i);
      i++;
    }
  if ((check_values(&settings) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
