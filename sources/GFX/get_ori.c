/*
** get_ori.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 18:37:40 2015 Jordan Chazottes
** Last update Sun Jul  5 18:38:19 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		get_ori(eOrientation ori)
{
  if (ori == NORTH)
    return (162);
  if (ori == EAST)
    return (0);
  if (ori == SOUTH)
    return (74);
  return (250);
}
