/*
** write_to_gfx.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Sat Jun 27 12:06:19 2015 Martin Porrès
** Last update Sat Jun 27 17:55:12 2015 Martin Porrès
*/

#include	"serveur.h"

int		write_to_gfx(t_client *gfx, char *msg)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      printf("MESSAGE : %s|\n", msg);
      if (my_write(tmp->fd, msg) == EXIT_FAILURE)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}
