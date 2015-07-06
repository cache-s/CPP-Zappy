/*
** main.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:19:44 2015 Jordan Chazottes
** Last update Mon Jul  6 17:49:01 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		main(int ac, char **av)
{
  if (ac != 3 || my_regex(av[2], ".0123456789") == EXIT_FAILURE)
    return (usage());
  return (core_GFX(av[1], atoi(av[2])));
}
