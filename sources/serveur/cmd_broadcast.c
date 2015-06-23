/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:21:56 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_broadcast(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_broadcast") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /*
    Broadcast (Communication)
    "pbc #n M\n"

    Boucle qui parcourt toute la liste des joueurs et leur envoie le message
    
    Send to GFX : pbc, player number, message
    Send to IA : ok
   */
  return (EXIT_SUCCESS);
}
