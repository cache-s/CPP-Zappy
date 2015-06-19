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
  settings->port = atoi(arg);
  return (i + 1);
}

int			fill_width(t_settings *settings, char *arg, int i)
{
  settings->width = atoi(arg);
  return (i + 1);
}

int			fill_height(t_settings *settings, char *arg, int i)
{
  settings->height = atoi(arg);
  return (i + 1);
}

int			fill_teams(t_settings *settings, char **args, int i)
{
  int			j;

  j = 0;
  while (args[i])
    { 
      if (args[i][0] == '-')
	return (i);
      settings->teams[j] = strdup(args[i]);
      i++;
      j++;
    }
  return (i);
}

int			fill_nb_clients(t_settings *settings, char *arg, int i)
{
  settings->nb_clients = atoi(arg);
  return (i + 1);
}

int			fill_delay(t_settings *settings, char *arg, int i)
{
  settings->delay = atof(arg);
  return (i + 1);
}

