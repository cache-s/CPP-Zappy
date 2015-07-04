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

void			east(t_serv *serv, t_client *client)
{
  int			j;

  y_less(serv);
  y_plus(serv);
  x_plus(serv);
  j = serv->see->tmp_y_plus;
  while (j != serv->see->tmp_y_less)
    {
      look_floor(serv->see->tmp_x_plus, j, serv, client);
      if (j - 1 < 0)
	j = serv->settings->height;
      else
	j--;
    }
  if (serv->see->coma == client->lvl)
    serv->see->end = 1;
  look_floor(serv->see->tmp_x_plus, serv->see->tmp_y_less, serv, client);
}

void			west(t_serv *serv, t_client *client)
{
  int			j;

  y_less(serv);
  y_plus(serv);
  x_less(serv);
  j = serv->see->tmp_y_less;
  while (j != serv->see->tmp_y_plus)
    {
      look_floor(serv->see->tmp_x_less, j, serv, client);
      if (j + 1 >= serv->settings->height)
	j = 0;
      else
	j++;
    }
  if (serv->see->coma == client->lvl)
    serv->see->end = 1;
  look_floor(serv->see->tmp_x_less, serv->see->tmp_y_plus, serv, client);
}

void			south(t_serv *serv, t_client *client)
{
  int			j;

  y_less(serv);
  x_plus(serv);
  x_less(serv);
  j = serv->see->tmp_x_plus;
  while (j != serv->see->tmp_x_less)
    {
      look_floor(j, serv->see->tmp_y_less, serv, client);
      if (j - 1 < 0)
	j = serv->settings->width;
      else
	j--;
    }
  if (serv->see->coma == client->lvl)
    serv->see->end = 1;
  look_floor(serv->see->tmp_x_less, serv->see->tmp_y_less, serv, client);
}

void			north(t_serv *serv, t_client *client)
{
  int			j;

  y_plus(serv);
  x_less(serv);
  x_plus(serv);
  j = serv->see->tmp_x_less;
  while (j != serv->see->tmp_x_plus)
    {
      look_floor(j, serv->see->tmp_y_plus, serv, client);
      if (j + 1 >= serv->settings->width)
	j = 0;
      else
	j++;
    }
  if (serv->see->coma == client->lvl)
    serv->see->end = 1;
  look_floor(serv->see->tmp_x_plus, serv->see->tmp_y_plus, serv, client);
}

int			see_with_orientation(t_serv *serv, t_client *client)
{
  if (serv->see->check == 0)
    {
      serv->see->tmp_x_less = client->x;
      serv->see->tmp_x_plus = client->x;
      serv->see->tmp_y_plus = client->y;
      serv->see->tmp_y_less = client->y;
      serv->see->check = 1;
    }
  else
    {
      serv->see->tmp_x_less = serv->see->tmp_x_less;
      serv->see->tmp_x_plus = serv->see->tmp_x_plus;
      serv->see->tmp_y_plus = serv->see->tmp_y_plus;
      serv->see->tmp_y_less = serv->see->tmp_y_less;
    }
  if (client->orientation == NORTH)
    north(serv, client);
  if (client->orientation == EST)
    east(serv, client);
  if (client->orientation == SOUTH)
    south(serv, client);
  if (client->orientation == WEST)
    west(serv, client);
  return (0);
}

