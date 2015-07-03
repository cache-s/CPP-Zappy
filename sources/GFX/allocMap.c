/*
** allocMap.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jun 28 10:46:14 2015 Jordan Chazottes
** Last update Fri Jul  3 11:41:31 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		allocMap(t_gfx *s)
{
  int		i;

  i = 0;
  if ((s->map = (t_map *)malloc(sizeof(t_map *))) == NULL)
    return (my_error(ERR_MALLOC));
  if ((s->map->blocks = malloc(s->height * sizeof(t_block *))) == NULL)
    return (my_error(ERR_MALLOC));
  while (i < s->width)
    {
      if ((s->map->blocks[i] = malloc(s->width * sizeof(t_block))) == NULL)
	return (my_error(ERR_MALLOC));
      ++i;
    }
  s->map->dispX = 0;
  s->map->dispY = 0;
  initWindow(s);
  return (EXIT_SUCCESS);
}
