
/*
** cmd.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myirc/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Apr  6 15:49:34 2015 Mathieu Bourmaud
** Last update Fri May  8 11:54:33 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int                     call_cmds(t_serv *serv, char *cmd)
{
  int                   i;

  i = 0;
  while (i < NB_CMDS)
    {
      puts(serv->AIFcts[i]);
      if (strcmp(cmd, serv->AIFcts[i]) == 0)
	return (i);
      i++;
    }
  return (42);
}
