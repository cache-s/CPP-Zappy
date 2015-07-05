/*
** set_param.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:25:22 2015 Jordan Chazottes
** Last update Sun Jul  5 19:25:51 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		setPlayerParam(t_player *new, char *token)
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
  new->team = strdup(tok);
  return (EXIT_SUCCESS);
}

int		setEggParam(t_player *new, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->eId = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->id = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->y = atoi(tok);
  return (EXIT_SUCCESS);
}
