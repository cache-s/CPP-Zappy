/*
** itoa.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Thu Jun 25 18:20:40 2015 Mathieu
** Last update Thu Jun 25 18:20:40 2015 Mathieu
*/

#include		"commons_fcts.h"

char			*itoa(int val)
{
  char			*str;

  if ((str = malloc(sizeof(char) * 15)) == NULL)
    return (my_error_null(ERR_MALLOC));
  sprintf(str, "%d", val);
  return (str);
}
