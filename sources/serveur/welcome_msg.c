/*
** welcom_msg.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myirc
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Apr 14 18:36:57 2015 Mathieu Bourmaud
** Last update Fri May  8 11:45:59 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			welcome_msg(t_serv *serv, int cs)
{
  if (write(cs, WELCOME, strlen(WELCOME)) == -1)
    return (EXIT_FAILURE);
  if (my_write(cs, serv->ip) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(cs, SRV_USAGE) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
