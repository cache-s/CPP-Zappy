/*
** getCmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 15:11:07 2015 Jordan Chazottes
** Last update Sun Jul  5 19:41:08 2015 Jordan Chazottes
*/

#include	"gfx.h"

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
  free(tok);
  return (EXIT_SUCCESS);
}
