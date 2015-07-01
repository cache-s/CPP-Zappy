/*
** see_with_orientation.c for  in /home/poupon_d/Rendu/PSU_2014_zappy/sources/serveur
** 
** Made by poupon_d
** Login   <poupon_d@epitech.net>
** 
** Started on  Wed Jul  1 17:23:31 2015 poupon_d
** Last update Wed Jul  1 17:23:31 2015 poupon_d
*/

#include		"serveur.h"

int			north(t_serv *serv, t_client *client)
{
  int			j;

  serv->see->tmp_y = serv->see->tmp_y + 1;
  serv->see->tmp_x_left = serv->see->tmp_x_left - 1;
  serv->see->tmp_x_right = serv->see->tmp_x_right + 1;
  j = serv->see->tmp_x_left;
  /* dprintf(client->fd, "<j = %i>",j); */
  /* dprintf(client->fd, "<x = %i>", serv->see->tmp_x_right); */
  while (j != serv->see->tmp_x_right)
    {
      look_floor(j, serv->see->tmp_y, serv, client);
      j++;
    }
  if (serv->see->coma == serv->see->lvl)
    serv->see->end = 1;
  look_floor(serv->see->tmp_x_right, serv->see->tmp_y, serv, client);
  /* dprintf(client->fd, "<j = %i>",j); */
  return (0);
}

int			see_with_orientation(t_serv *serv, t_client *client)
{
  if (serv->see->check == 0)
    {
      serv->see->tmp_x_left = client->x;
      serv->see->tmp_x_right = client->x;
      serv->see->tmp_y = client->y;
      serv->see->check = 1;
    }
  else
    {
      serv->see->tmp_x_left = serv->see->tmp_x_left;
      serv->see->tmp_x_right = serv->see->tmp_x_right;
      serv->see->tmp_y = serv->see->tmp_y;
    }
  north(serv, client);
  return (0);
}

