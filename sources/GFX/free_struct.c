/*
** freeStruct.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Wed Jul  1 17:51:46 2015 Jordan Chazottes
** Last update Sun Jul  5 22:44:22 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		free_struct(t_gfx *s)
{
  int		i;
  t_player	*tmp;

  i = 0;
  while (i < s->height)
    free(s->map->blocks[i++]);
  free(s->map->blocks);
  free(s->map);
  tmp = s->players;
  while (tmp != NULL)
    {
      s->players = s->players->next;
      tmp = s->players;
      free(tmp);
    }
  free(s->players);
  i = 0;
  while (i < NB_CMDS)
    free(s->cmdTab[i++]);
  free(s->cmdTab);
  TTF_CloseFont(s->font);
  TTF_Quit();
}
