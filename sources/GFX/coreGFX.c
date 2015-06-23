/*
** coreGFX.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:52:33 2015 Jordan Chazottes
** Last update Tue Jun 23 12:53:08 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		coreGFX(void) // change ip / port
{
  t_gfx		s;

  initStruct(&s);
  initNetwork(&s);
  initWindow(&s);
  while (eventHandler() != -1)
    {
      //onfédestrucs
    }
}
