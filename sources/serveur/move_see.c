/*
** move_see.c for  in /home/poupon_d/Rendu/PSU_2014_zappy/sources/serveur
** 
** Made by poupon_d
** Login   <poupon_d@epitech.net>
** 
** Started on  Fri Jul  3 20:05:53 2015 poupon_d
** Last update Fri Jul  3 20:05:53 2015 poupon_d
*/

#include		"serveur.h"

void                    y_plus(t_serv *serv, t_client *client)
{
  dprintf(client->fd, "Test + 1 |y|: %i\n", serv->see->tmp_y_plus + 1); 
  if (serv->see->tmp_y_plus + 1 >= serv->settings->height)
    serv->see->tmp_y_plus = 0;
  else
    serv->see->tmp_y_plus = serv->see->tmp_y_plus + 1;
}

void                    x_plus(t_serv *serv, t_client *client)
{
  dprintf(client->fd, "Test + 1 |X| : %i\n", serv->see->tmp_x_plus + 1);
  if (serv->see->tmp_x_plus + 1 >= serv->settings->width)
    {
      dprintf(client->fd, "Du coup là ! ?\n");
    serv->see->tmp_x_plus = 0;
    }
  else
    serv->see->tmp_x_plus = serv->see->tmp_x_plus + 1;
}

void                    y_less(t_serv *serv, t_client *client)
{
  dprintf(client->fd, "Test - 1 |y|: %i\n", serv->see->tmp_y_less - 1);
  if (serv->see->tmp_y_less - 1 < 0)
    serv->see->tmp_y_less = serv->settings->height -1;
  else
    serv->see->tmp_y_less = serv->see->tmp_y_less - 1;
}

void                    x_less(t_serv *serv, t_client *client)
{
  dprintf(client->fd, "Test - 1 |x|: %i\n", serv->see->tmp_x_less - 1);
  if (serv->see->tmp_x_less - 1 < 0)
    {
    dprintf(client->fd, "Ici ?\n");
    serv->see->tmp_x_less = serv->settings->width - 1;
    }
  else
    serv->see->tmp_x_less = serv->see->tmp_x_less - 1;
}
