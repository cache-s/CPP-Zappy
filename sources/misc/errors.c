/*
** errors.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:00:32 2015 Mathieu Bourmaud
** Last update Tue Mar 10 10:40:34 2015 Mathieu Bourmaud
*/

#include		"errors.h"

int			my_error(char *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (EXIT_FAILURE);
}

char			*my_error_null(char *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (NULL);
}

int			my_error_close(char *msg, int fd)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  close(fd);
  return (EXIT_FAILURE);
}
