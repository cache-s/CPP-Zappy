/*
** initStruct.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 14:23:03 2015 Jordan Chazottes
** Last update Fri Jun 26 16:02:14 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		initStruct(t_gfx *s)
{
  s->width = 0;
  s->height = 0;
  s->screen = NULL;

  s->network.socket = 0;
  s->network.entire_cmd = 0;
  s->network.cmd = NULL;
  s->network.init = 0;
}
