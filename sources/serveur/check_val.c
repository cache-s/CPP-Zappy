/*
** check_val.c for  in /home/bourma_m/Projet/SystemUnix/elcrypt
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sun Mar 15 20:08:40 2015 Mathieu Bourmaud
** Last update Sun Mar 15 20:39:09 2015 Mathieu Bourmaud
*/

#include		"elcrypt.h"

int			check_values(t_elcrypt *crypt)
{
  int			i;
  int			occ;

  i = 0;
  occ = 0;
  if ((crypt->key2 = malloc(33)) == NULL)
    return (my_error(ERR_MALLOC));
  while (i < (MAX_ARGS - 2))
    {
      if (crypt->parser.occArgs[0] != 0 && crypt->parser.occArgs[1] != 0)
	return (my_error(ERR_ARGS));
      if (crypt->parser.occArgs[i] > 1)
	return (my_error(ERR_SAME_ARG));
      if (crypt->parser.occArgs[i] != 0)
	occ++;
      i++;
    }
  if (occ != 4)
    return (my_error(ERR_USAGE));
  return (EXIT_SUCCESS);
}
