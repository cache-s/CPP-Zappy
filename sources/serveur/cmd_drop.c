/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:21:32 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_drop(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_drop") == EXIT_FAILURE)
    return (EXIT_FAILURE);

  /*
    Pose un objet.
    "pdr #n i\n"
    "pin #n X Y q q q q q q q\n"
    "bct X Y q q q q q q q\n" 

    Send to GFX : pdr, player number, numéro de ressource
    pin, player number, x & y pos, quantité x 7
    bct, x & y pos, quantité x 7
    Send to IA : ok/ko
  */
  return (EXIT_SUCCESS);
}
