/*
** getPlayer.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jun 28 19:52:04 2015 Jordan Chazottes
** Last update Sun Jul  5 22:50:46 2015 Jordan Chazottes
*/

#include	"gfx.h"

t_player	*get_prev_player(t_gfx *s, int id)
{
  t_player	*tmp;

  tmp = s->players;
  if (tmp->id == id)
    return (NULL);
  while (tmp != NULL && tmp->next != NULL && tmp->next->id != id)
    tmp = tmp->next;
  return (tmp);
}

t_player	*get_player(t_gfx *s, int id)
{
  t_player	*tmp;

  tmp = s->players;
  while (tmp != NULL && tmp->id != id)
    tmp = tmp->next;
  return (tmp);
}
