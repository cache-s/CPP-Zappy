/*
** cmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:05:02 2015 Jordan Chazottes
** Last update Sun Jul  5 19:08:00 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		cmd_msz(t_gfx *s, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  s->width = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  s->height = atoi(tok);
  if (allocMap(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cmd_bct(t_gfx *s, char *token)
{
  char		*tok;
  t_pos		pos;
  int		i;

  i = -1;
  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  pos.x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  pos.y = atoi(tok);
  s->map->blocks[pos.x][pos.y].x = pos.x;
  s->map->blocks[pos.x][pos.y].y = pos.y;
  tok = strtok(NULL, " ");
  while (tok != NULL)
    {
      s->map->blocks[pos.x][pos.y].items[++i] = atoi(tok);
      tok = strtok(NULL, " ");
    }
  return (EXIT_SUCCESS);
}

int		cmd_tna(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_pnw(t_gfx *s, char *token)
{
  t_player	*new;
  t_player	*tmp;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (my_error(ERR_MALLOC));
  new->type = PLAYER;
  new->eId = -1;
  new->act = STAND;
  new->next = NULL;
  setPlayerParam(new, token);
  if (s->players == NULL)
    {
      new->isFirst = 1;
      s->players = new;
      return (EXIT_SUCCESS);
    }
  new->isFirst = 0;
  tmp = s->players;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  tmp = s->players;
  return (EXIT_SUCCESS);
}

int		cmd_ppo(t_gfx *s, char *token)
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
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->ori = atoi(tok);
  tmp->act = STAND;
  return (EXIT_SUCCESS);
}
