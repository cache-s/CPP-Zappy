/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:21:08 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_take(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_take") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  
  /* 
     Prend un objet et l'ajoute à l'inventaire du joueur.
     "pgt #n i\n"
     "pin #n X Y q q q q q q q\n"
     "bct X Y q q q q q q q\n" 

     Send to GFX : pgt, player number, numéro de ressource
     pin, payer number, X and Y pos, Quantité x 7
     bct, x and y pos, quantité x 7
     Send to IA : ok/ko
  */
  return (EXIT_SUCCESS);
}
