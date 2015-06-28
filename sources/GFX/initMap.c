/*
** initMap.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 15:11:07 2015 Jordan Chazottes
** Last update Sun Jun 28 10:49:41 2015 Jordan Chazottes
*/

#include	"gfx.h"
#include	<string.h>

int		setBlock(t_gfx *s, char *token)
{
  (void)s;
  char		*tok;

  tok = strtok(token, " ");
  if (strcmp(tok, "bct") != 0)
    return (EXIT_FAILURE);
  while (tok != NULL)
    {
      printf("-%s\n", tok);
      tok = strtok(NULL, " ");
    }
  return (EXIT_SUCCESS);
}

int		getCmd(t_gfx *s, char *token)
{
  char		*tok;
  char		*str;
  int		i;

  i = 0;
  str = strdup(token);
  tok = strtok(str, " ");
  while (s->cmdTab[i] != NULL && strcmp(tok, s->cmdTab[i]) != 0)
    ++i;
  if (s->cmdTab[i] == NULL)
    return (EXIT_FAILURE);
  if ((s->cmds[i](s, token)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		initMap(t_gfx *s, char *str, char *token, char *end_str)
{
  str = strdup(s->network.cmd);
  token = strtok_r(str, "\n", &end_str);
  while (token != NULL)
    {
      printf("*%s*\n", token);
      getCmd(s, token);      
      token = strtok_r(NULL, "\n", &end_str);
    }
  s->network.init = 2;
  printf("Map size : %d %d\nTime = %d\n", s->width, s->height, s->time);
  return (EXIT_SUCCESS);
}
