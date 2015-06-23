/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:27:42 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_fork(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_fork") == EXIT_FAILURE)
    return (EXIT_FAILURE);

  /* 
     Fork 
     Début du fork :
     "pfk #n\n" 
     Fin du fork : 
     "enw #e #n X Y\n" 

     Send to GFX : 
     Start : pfk, player nbr
     end : enw, numéro d'oeuf sur le serveur, player nbr, X & Y pos
     Send to IA : ok
   */
  return (EXIT_SUCCESS);
}
