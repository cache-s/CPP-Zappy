/*
** write_eht_ok.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:08:51 2015 Martin Porrès
** Last update Fri Jul  3 11:09:29 2015 Martin Porrès
*/

#include	"serveur.h"

int		write_eht_gfx(t_client *gfx, int id)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "eht %d\n", id) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_ok(int fd, int ok)
{
  if (ok)
    {
      printf(BOLD RED "Sending 'ok' to %d\n" END, fd);
      if (my_write(fd, "ok") == EXIT_FAILURE)
        return (EXIT_FAILURE);
    }
  else
    {
      printf(BOLD RED "Sending 'ko' to %d\n" END, fd);
      if (my_write(fd, "ko") == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
