/*
** errors.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:00:32 2015 Mathieu Bourmaud
** Last update Tue Jun 16 13:05:33 2015 Sebastien Cache-Delanos
*/

#include		"errors.h"

int			my_error(const char *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (EXIT_FAILURE);
}

char			*my_error_null(const char *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (NULL);
}

int			my_error_close(const char *msg, int fd)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  close(fd);
  return (EXIT_FAILURE);
}
