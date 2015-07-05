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
