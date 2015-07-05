/*
** cmd4.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:20:14 2015 Jordan Chazottes
** Last update Sun Jul  5 22:52:33 2015 Jordan Chazottes
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

  tok = strtok(token, " ");
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  s->time = atoi(tok);
  return (EXIT_SUCCESS);
}
