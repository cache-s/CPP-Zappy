/*
** cmd2.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:08:24 2015 Jordan Chazottes
** Last update Sun Jul  5 19:10:27 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		cmd_plv(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->level = atoi(tok);
  return (EXIT_SUCCESS);
}

int		cmd_pin(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->y = atoi(tok);
  id = 0;
  tok = strtok(NULL, " ");
  while (tok != NULL)
    {
      tmp->items[id++] = atoi(tok);
      tok = strtok(NULL, " ");
    }
  return (EXIT_SUCCESS);
}

int		cmd_pex(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_pbc(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = BROADCAST;
  return (EXIT_SUCCESS);
}

int		cmd_pic(t_gfx *s, char *token)
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
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = INCANTATION;
  return (EXIT_SUCCESS);
}
