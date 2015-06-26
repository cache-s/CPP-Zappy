/*
** initStruct.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 14:23:03 2015 Jordan Chazottes
** Last update Fri Jun 26 13:23:13 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		initStruct(t_gfx *s)
{
  s->width = 800;
  s->height = 600;
  s->network.entire_cmd = 0;
  s->network.init = 0;
}
