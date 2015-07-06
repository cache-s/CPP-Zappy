/*
** freeStruct.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Wed Jul  1 17:51:46 2015 Jordan Chazottes
** Last update Mon Jul  6 17:46:09 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		free_struct(t_gfx *s)
{
  int		i;

  i = 0;
  while (i < s->height)
    free(s->map->blocks[i++]);
  free(s->map->blocks);
  free(s->map);
  i = 0;
  while (i < NB_CMDS)
    free(s->cmdTab[i++]);
  if (s->cmdTab != NULL)
    free(s->cmdTab);
  TTF_CloseFont(s->font);
  TTF_Quit();
}
