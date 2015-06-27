/*
** initMap.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 15:11:07 2015 Jordan Chazottes
** Last update Fri Jun 26 18:15:53 2015 Jordan Chazottes
*/

#include	"gfx.h"
       #include <string.h>

int		initMap(t_gfx *s)
{
  char		*str;
  char		*token;
  str = strdup(s->network.cmd);
  token = strtok(str, "\n");
  while (token != NULL)
    {
      /* printf(" %s\n", token); */
      token = strtok(NULL, "\n");
    }
  s->network.init = 2;
  return (EXIT_SUCCESS);
}
