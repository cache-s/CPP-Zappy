/*
** initSprites.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Mon Jun 29 15:28:29 2015 Jordan Chazottes
** Last update Mon Jun 29 19:12:59 2015 Jordan Chazottes
*/

#include	"gfx.h"

/* int		initSprRes(t_gfx *s) */
/* { */
/*   int		i; */
/*   int		j; */

/*   if ((s->res = (t_res *)malloc(sizeof(t_res *))) == NULL) */
/*     return (my_error(ERR_MALLOC)); */
/*   i = 0; */
/*   j = 0; */
/*   if ((s->res->img = SDL_LoadBMP("assets/sprites/resources.bmp")) == NULL) */
/*     return (EXIT_FAILURE); */
/*   if (SDL_SetColorKey(s->res->img, SDL_SRCCOLORKEY, SDL_MapRGB(s->res->img->format, 0, 0, 255)) != 0) */
/*     return (EXIT_FAILURE); */
/*   while (i < 7) */
/*     { */
/*       s->res->pos[i].x = j; */
/*       s->res->pos[i].y = 0; */
/*       s->res->pos[i].w = 16; */
/*       s->res->pos[i].h = 16; */
/*       j += 16; */
/*       ++i; */
/*     } */
/*   return (EXIT_SUCCESS); */
/* } */

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
  /* if (initSprRes(s) == EXIT_FAILURE) */
  /*   return (EXIT_FAILURE); */
  if (initFloor(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
