/*
** initStruct.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 14:23:03 2015 Jordan Chazottes
** Last update Fri Jul  3 15:20:11 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		initStruct(t_gfx *s)
{
  s->width = 0;
  s->height = 0;
  s->screen = NULL;
  s->pSelect = -1;

  s->network.socket = 0;
  s->network.entire_cmd = 0;
  s->network.cmd = NULL;
  s->network.init = 0;
  s->players = NULL;
}
