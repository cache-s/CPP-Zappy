/*
** initFont.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jul  3 15:21:27 2015 Jordan Chazottes
** Last update Fri Jul  3 15:24:09 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		initFonts(t_gfx *s)
{
  if ((s->font = TTF_OpenFont("assets/fonts/pump.ttf", 20)) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
