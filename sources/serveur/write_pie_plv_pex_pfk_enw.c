/*
** write_pie_plv_pex_pfk_enw.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:07:59 2015 Martin Porrès
** Last update Fri Jul  3 11:19:26 2015 Martin Porrès
*/

#include	"serveur.h"

int		write_pie_gfx(t_client *gfx, t_client *client, int r)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pie %d %d %d\n", client->x, client->y, r) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_plv_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "plv %d %d\n", client->id, client->lvl) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_pex_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pex %d\n", client->id) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_pfk_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pfk %d\n", client->id) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_enw_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "enw %d %d %d %d\n", client->id, client->id, client->x, client->y) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

