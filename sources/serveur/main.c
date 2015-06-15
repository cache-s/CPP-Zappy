/*
** main.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 09:42:17 2015 Mathieu Bourmaud
** Last update Fri Mar 13 11:39:58 2015 Mathieu Bourmaud
*/

#include	"serveur.h"

int		main(int ac, char **av)
{
  if (ac != 2)
    return (my_error(ERR_USAGE_SRV));
  if (my_regex(av[1], "0123456789") ==  EXIT_FAILURE)
    return (my_error(ERR_PORT));
  if (init_server(atoi(av[1])) ==  EXIT_FAILURE)
    return (my_error(ERR_INIT_SRV));
  return (EXIT_SUCCESS);
}
