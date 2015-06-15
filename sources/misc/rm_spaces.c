/*
** rm_spaces.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Thu Mar 12 11:05:31 2015 Mathieu Bourmaud
** Last update Thu Mar 12 13:56:15 2015 Mathieu Bourmaud
*/

#include		"commons_fcts.h"

void			rm_spaces(char* src)
{
  char			*i;
  char			*j;

  i = src;
  j = src;
  while (*j != 0)
    {
      *i = *j++;
      if (*i != ' ')
	i++;
    }
  *i = 0;
}

void			rm_spaces_except_one(char* src)
{
  char			*i;
  char			*j;
  int			occ;

  i = src;
  j = src;
  occ = 0;
  while (*j != 0)
    {
      *i = *j++;
      if (*i != ' ')
	i++;
      if (*i == ' ')
	occ++;
      if (occ == 1)
	i++;
    }
  *i = 0;
}
