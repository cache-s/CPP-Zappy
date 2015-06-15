/*
** my_write.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri Mar 20 19:04:52 2015 Mathieu Bourmaud
** Last update Fri Apr 10 11:41:40 2015 Mathieu Bourmaud
*/

#include		"commons_fcts.h"

int			my_write(int fd, char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    return (EXIT_FAILURE);
  if (write(fd, "\n", 1) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
