/*
** write_pbc_pnw_pdi_pic.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/serveur
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jul  3 11:06:39 2015 Martin Porrès
** Last update Fri Jul  3 11:15:41 2015 Martin Porrès
*/

#include	"serveur.h"

int		write_pbc_gfx(t_client *gfx, t_client *client, char *cmd)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pbc %d %s\n", client->id, cmd) == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_pnw_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (dprintf(tmp->fd, "pnw %d %d %d %d %d %s\n", client->id, client->x,
		  client->y, client->orientation, client->lvl, client->team)
	  == -1)
	ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_pdi_gfx(t_client *gfx, t_client *client)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = gfx;
  while (tmp != NULL)
    {
      if (tmp->connected == 1)
	if (dprintf(tmp->fd, "pdi %d\n", client->id) == -1)
	  ret = EXIT_FAILURE;
      tmp = tmp->next;
    }
  return (ret);
}

int		write_pic_gfx(t_serv *serv, t_client *client)
{
  t_client	*tmp;
  char		*ids;

  tmp = serv->client;
  if ((ids = malloc(66)) == NULL)
    return (my_error(ERR_MALLOC));
  bzero(ids, 66);
  if ((ids = strcpy(ids, "")) == NULL)
    return (my_error(ERR_STRCPY));
  while (tmp != NULL)
    {
      if (tmp->x == client->x && tmp->y == client->y &&
	  tmp->lvl == client->lvl)
	{
	  if ((ids = strcat(ids, " ")) == NULL)
	    return (my_error(ERR_STRCAT));
	  if ((ids = strcat(ids, itoa(tmp->id))) == NULL)
	    return (my_error(ERR_STRCAT));
	}
      tmp = tmp->next;
    }
  return (write_pic_end(serv, client, ids));
}

int		write_pic_end(t_serv *serv, t_client *client, char *ids)
{
  t_client	*tmp;
  int		ret;

  ret = EXIT_SUCCESS;
  tmp = serv->gfx;
  while (tmp != NULL)
    {
      if (strcmp(ids, "") == 0) 
	{
	  if (dprintf(tmp->fd, "pic %d %d %d\n", client->x,	\
		      client->y, client->lvl + 1) == -1)
	    ret = EXIT_FAILURE;
	}
      else
	{
	  if (dprintf(tmp->fd, "pic %d %d %d%s\n", client->x,	\
		      client->y, client->lvl + 1, ids) == -1)
	    ret = EXIT_FAILURE;
	}
      tmp = tmp->next;
    }
  return (ret);
}

