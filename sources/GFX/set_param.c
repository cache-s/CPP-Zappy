/*
** set_param.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:25:22 2015 Jordan Chazottes
** Last update Mon Jul  6 17:39:23 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		set_player_param(t_player *new, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->id = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->y = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->ori = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->level = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((new->team = strdup(tok)) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		set_egg_param(t_player *new, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  new->eId = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  new->id = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  new->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  new->y = atoi(tok);
  return (EXIT_SUCCESS);
}
