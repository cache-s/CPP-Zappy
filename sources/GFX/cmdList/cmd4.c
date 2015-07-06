/*
** cmd4.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:20:14 2015 Jordan Chazottes
** Last update Mon Jul  6 17:52:08 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		cmd_enw(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = get_player(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = STAND;
  return (EXIT_SUCCESS);
}

int		cmd_eht(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_ebo(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_edi(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_sgt(t_gfx *s, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  s->time = atoi(tok);
  return (EXIT_SUCCESS);
}
