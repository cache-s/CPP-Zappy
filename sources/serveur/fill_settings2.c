/*
** fill_settings2.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jul  5 19:21:55 2015 Mathieu
** Last update Sun Jul  5 19:21:55 2015 Mathieu
*/

#include		"serveur.h"

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
