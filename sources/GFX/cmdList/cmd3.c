/*
** cmd3.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:13:42 2015 Jordan Chazottes
** Last update Mon Jul  6 17:53:56 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		cmd_pie(t_gfx *s, char *token)
{
  t_player	*tmp;
  t_pos		pos;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  pos.x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  pos.y = atoi(tok);
  tmp = s->players;
  while (tmp != NULL)
    {
      if (tmp->x == pos.x && tmp->y == pos.y && tmp->act == INCANTATION)
        tmp->act = STAND;
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);

}

int		cmd_pfk(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = get_player(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = FORK;
  return (EXIT_SUCCESS);
}

int		cmd_pdr(t_gfx *s, char *token)
{
  t_player	*tmp;
  char		*tok;
  int		id;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = get_player(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if (tmp->items[id] > 0)
    {
      s->map->blocks[tmp->x][tmp->y].items[id]++;
      tmp->items[id]--;
    }
  return (EXIT_SUCCESS);
}

int		cmd_pgt(t_gfx *s, char *token)
{
  t_player	*tmp;
  char		*tok;
  int		id;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = get_player(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if (s->map->blocks[tmp->x][tmp->y].items[id] > 0)
    {
      s->map->blocks[tmp->x][tmp->y].items[id]--;
      tmp->items[id]++;
    }
  tmp->act = CROUCH;
  return (EXIT_SUCCESS);
}

int		cmd_pdi(t_gfx *s, char *token)
{
  t_player	*tmp;
  t_player	*tmp2;
  char		*tok;
  int		id;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if (my_regex(tok, ".0123456789") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  id = atoi(tok);
  tmp = get_player(s, id);
  if (tmp->isFirst == 1)
    {
      if (tmp->next == NULL)
        s->players = NULL;
      else
        {
          s->players = tmp->next;
          s->players->isFirst = 1;
        }
      return (EXIT_SUCCESS);
    }
  if (tmp->next == NULL)
    return (cmd_pdi2(s, id));
  tmp2 = get_prev_player(s, id);
  tmp2->next = tmp->next;
  return (EXIT_SUCCESS);
}
