/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Thu Jul  2 16:30:31 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_fork(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  if (write_pfk_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  // wait fork
  
  serv->settings->nb_clients++;// à remplacer
  if (write_enw_gfx(serv->gfx, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  // wait eclosion
  if (write_eht_gfx(serv->gfx, client->id) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  //set egg to rdy
  return (EXIT_SUCCESS);
}
