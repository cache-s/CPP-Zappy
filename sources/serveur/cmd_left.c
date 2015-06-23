/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:20:30 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_left(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_left") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  
  /* 
     Change l'orientation du joueur.
     ppo #n X Y O\n"

     player->orientation = GAUCHE; (Enum à faire si pas fait)
     
     Pas de check ça ne peut pas fail.
     
     Send to GFX : ppo, player number, X and Y position, Orientation
     Send to IA : ok
   */
  return (EXIT_SUCCESS);
}
