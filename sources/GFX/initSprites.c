/*
** initSprites.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 15:28:29 2015 Jordan Chazottes
** Last update Tue Jun 30 18:05:06 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		initFloor(t_gfx *s)
{
  if ((s->floor = (t_floor *)malloc(sizeof(t_floor *))) == NULL)
    return (my_error(ERR_MALLOC));
  if ((s->floor->img = SDL_LoadBMP("assets/sprites/grass.bmp")) == NULL)
    return (EXIT_FAILURE);
  s->floor->pos[0].x = 0;
  s->floor->pos[0].y = 0;
  s->floor->pos[0].w = 64;
  s->floor->pos[0].h = 64;
  return (EXIT_SUCCESS);
}

int		initSprites(t_gfx *s)
{
  if (initFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
