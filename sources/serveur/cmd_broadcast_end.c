/*
** cmd_broadcast_end.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:36:23 2015 Martin Porrès
** Last update Fri Jul  3 11:36:55 2015 Martin Porrès
*/

#include		"serveur.h"

int			set_path_orientation(int x, int y)
{
  int			base;
  
  if (x == 0 && y == 0)
    return (0);
  if ((x > 0 && y < 0) || (x < 0 && y > 0))
    {
      if (x > 0 && y < 0)
	{
	  base = 3;
	  return (find_best_orientation(abs(x), abs(y), base));
	}
      base = 7;
      return (find_best_orientation(abs(x), abs(y), base));
    }
  if (x > 0 && y > 0)
    {
      base = 1;
      return (find_best_orientation(abs(y), abs(x), base));
    }
  base = 5;
  return (find_best_orientation(abs(y), abs(x), base));
}

int		        find_best_orientation(int x, int y, int base)
{
  if (x > y)
    {
      if (y == 0)
	return (base);
      if (x > (y * (4 / 3)))
	return (base);
      return (base + 1);
    }
  if (y < (x * (4 / 3)))
    return (base + 1);
  if (base + 2 > 8)
    return (1);
  return (base + 2);
}

int			set_real_orientation(int o, eOrientation client_o)
{
  if (client_o == EST)
    o += 2;
  if (client_o == SOUTH)
    o += 4;
  if (client_o == WEST)
    o += 6;
  if (o > 8)
    o -= 8;
  return (o);
}
