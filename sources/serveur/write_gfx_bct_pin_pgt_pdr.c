/*
** write_gfx_bct_pin_pgt_pdr.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Sat Jun 27 12:06:19 2015 Martin Porrès
** Last update Fri Jul  3 11:11:17 2015 Martin Porrès
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
      if (my_write(tmp->fd, msg) == EXIT_FAILURE)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_bct_gfx(t_client *gfx, t_block *block)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      write_bct(block, tmp->fd);
      tmp = tmp->next;
    }
  return (ret);
  
}

int		write_pin_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pin %d %d %d %d %d %d %d %d %d %d\n", client->id,
		  client->x, client->y, client->items[0], client->items[1],
		  client->items[2], client->items[3], client->items[4],
		  client->items[5], client->items[6]) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);

}

int		write_pgt_gfx(t_client *gfx, t_client *client, int item)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pgt %d %d\n", client->id, item) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_pdr_gfx(t_client *gfx, t_client *client, int item)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pdr %d %d\n", client->id, item) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}
