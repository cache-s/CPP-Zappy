/*
** main.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:19:44 2015 Jordan Chazottes
** Last update Thu Jun 25 13:46:27 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		main(int ac, char **av)
{
  if (ac != 3)
    return (usage());
  return (coreGFX(av[1], atoi(av[2])));
}
