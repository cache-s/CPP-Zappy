/*
** get_act.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:38:32 2015 Jordan Chazottes
** Last update Sun Jul  5 18:38:54 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		get_act(eAction act)
{
  if (act == STAND)
    return (0);
  if (act == BROADCAST)
    return (1);
  if (act == INCANTATION)
    return (2);
  if (act == FORK)
    return (3);
  if (act == CROUCH)
    return (4);
  if (act == DIE)
    return (5);
  return (0);
}
