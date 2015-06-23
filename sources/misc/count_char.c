/*
** check_pwd.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Mar 17 17:38:23 2015 Mathieu Bourmaud
** Last update Thu Apr  9 11:08:05 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			count_char(char *str, char c)
{
  int			occ;
  int			i;

  occ = 0;
  i = 0;
  puts(str);
  while (str[i])
    {
      if (str[i] == c)
	occ++;
      i++;
    }
  return (occ);
}
