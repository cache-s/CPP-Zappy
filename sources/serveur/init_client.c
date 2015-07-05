/*
** init_client.c for  in /home/poupon_d/Rendu/PSU_2014_zappy/sources/serveur
** 
** Made by poupon_d
** Login   <poupon_d@epitech.net>
** 
** Started on  Sun Jul  5 18:28:55 2015 poupon_d
** Last update Sun Jul  5 18:28:55 2015 poupon_d
*/

#include			"serveur.h"

int				set_items(t_serv *serv, t_client *new)
{
  int                   i;

  i = 0;
  new->items[0] = 10;
  while (i++ < 7)
    new->items[i] = 0;
  serv->nb_client++;
  if (my_write(2, YELLOW "*** Client settings initialized" END)
      == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int				set_client_values(t_serv *serv, t_client *new, int fd)
{
  new->cmd = NULL;
  new->shortest_cmd = NULL;
  new->need_write = 0;
  new->next = NULL;
  new->fd = fd;
  new->incanting = 0;
  new->id = fd;
  new->gfx = 0;
  new->time_left = 0;
  new->is_full = 0;
  new->connected = 0;
  new->fct_read = client_read;
  new->fct_write = client_write;
  new->orientation = NORTH;
  new->heart_perc = 0;
  new->x = random() % serv->settings->width;
  new->y = random() % serv->settings->height;
  new->lvl = 1;
  new->incant_time = 30000;
  new->forking = 0;
  new->fork_time = 42000;
  new->fork_step = 0;
  set_items(serv, new);
  return (EXIT_SUCCESS);
}
