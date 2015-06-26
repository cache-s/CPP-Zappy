/*
** usage.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/client
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 11:26:51 2015 Martin Porrès
** Last update Tue Jun 23 12:02:11 2015 Sebastien Cache-Delanos
*/

#include		"client.h"

int	usage(int ac, char **av)
{
  t_client			client;

  if (ac < 5 || ac > 7 || strcmp(av[1], "-n") != 0 || strcmp(av[3], "-p") != 0 || (ac > 5 && strcmp(av[5], "-h")) != 0)
    {
      printf(USAGE);
      return (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}
