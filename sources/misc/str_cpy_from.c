/*
** str_cpy_from.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sat Jul  4 14:11:04 2015 Mathieu
** Last update Sat Jul  4 14:11:04 2015 Mathieu
*/

#include	"commons_fcts.h"

char		*str_cpy_from(char *dest, const char *src, size_t from)
{
  int		j;
  
  j = 0;
  while (src[from] != '\0')
    {
      dest[j] = src[from];
      from++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
