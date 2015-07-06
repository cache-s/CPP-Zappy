/*
** getCmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 15:11:07 2015 Jordan Chazottes
** Last update Mon Jul  6 17:45:22 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		get_cmd(t_gfx *s, char *token)
{
  char		*tok;
  char		*str;
  int		i;

  i = 0;
  if ((str = strdup(token)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(str, " ")) == NULL)
    return (EXIT_FAILURE);
  while (s->cmdTab[i] != NULL && strcmp(tok, s->cmdTab[i]) != 0)
    ++i;
  if (s->cmdTab[i] == NULL)
    return (EXIT_FAILURE);
  if ((s->cmds[i](s, token)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
