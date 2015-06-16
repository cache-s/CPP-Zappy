/*
** my_regex.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:17:54 2015 Mathieu Bourmaud
** Last update Tue Jun 16 13:04:26 2015 Sebastien Cache-Delanos
*/

#include	"commons_fcts.h"

int		my_regex(const char *val, const char *good)
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
