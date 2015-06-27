/*
** initMap.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 15:11:07 2015 Jordan Chazottes
** Last update Sat Jun 27 16:50:03 2015 Jordan Chazottes
*/

#include	"gfx.h"
#include	<string.h>

int		getMapSize(t_gfx *s, char *str)
{
  char		*tmp;
  char		*token;

  tmp = strdup(str);
  token = strtok(tmp, " ");
  if (strcmp(token, "msz") != 0)
    return (EXIT_FAILURE);
  s->width = atoi(strtok(NULL, " "));
  s->height = atoi(strtok(NULL, " "));
  return (EXIT_SUCCESS);
}

int		getTime(t_gfx *s, char *str)
{
  char		*tmp;
  char		*token;

  tmp = strdup(str);
  token = strtok(tmp, " ");
  if (strcmp(token, "sgt") != 0)
    return (EXIT_FAILURE);
  s->time = atoi(strtok(NULL, " "));
  return (EXIT_SUCCESS);
}

int		initMap(t_gfx *s, char *str, char *token, char *end_str)
{
  char		*str2;
  char		*token2;
  char		*end_token;

  str = strdup(s->network.cmd);
  /* token = strtok_r(str, "\n", &end_str); */
  if (getMapSize(s, strtok_r(str, "\n", &end_str)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (getTime(s, strtok_r(NULL, "\n", &end_str)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (token != NULL)
    {
      str2 = strdup(token);
      token2 = strtok_r(str2, " ", &end_token);
      while (token2 != NULL)
	{
	  token2 = strtok_r(NULL, " ", &end_token);
	}
      token = strtok_r(NULL, "\n", &end_str);
    }
  s->network.init = 2;
  printf("Map size : %d %d\nTime = %d\n", s->width, s->height, s->time);
  return (EXIT_SUCCESS);
}
