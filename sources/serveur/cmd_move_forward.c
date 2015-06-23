/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:19:58 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_move_forward(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_move_forward") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /*
    Avance d'une case à P position.
    ppo #n X Y O\n"

    player->pos->orientation +1;

    check à faire : Si le player ne sort pas de la map

    Send to GFX : ppo, player number, X and Y position, Orientation
    Send to IA : ok
 */
  return (EXIT_SUCCESS);
}
