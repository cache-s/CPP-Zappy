/*
** my_regex.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:17:54 2015 Mathieu Bourmaud
** Last update Wed Mar 25 11:21:30 2015 Mathieu Bourmaud
*/

#include	"commons_fcts.h"

int		my_regex(char *val, char *good)
{
  int		i;
  int		j;
  size_t	occ;

  i = 0;
  occ = 0;
  while (val[i])
    {
      j = 0;
      while (good[j])
	{
	  if (val[i] == good[j])
	    occ++;
	  j++;
	}
      i++;
    }
  if (occ != strlen(val))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
