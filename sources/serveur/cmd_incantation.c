/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:27:30 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_incantation(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_incantation") == EXIT_FAILURE)
    return (EXIT_FAILURE);

  /*
    Lance l'incantation de l'élévation.

    Début d'incantation :
     "pic X Y L #n #n …\n" 
    Fin d'incantation :
    "pie X Y R\n"
    "plv #n L\n"
    …
    "plv #n L\n"
    "bct X Y q q q q q q q\n"
    …
    "bct X Y q q q q q q q\n" 

    Send to GFX : 
     Start : pic, X & Y pos, niveau de l'incantation ou du joueur, numéro des joueurs qui incantent.
     End : pie, X & Y pos, player number, résulatat de l'incantation.
           plv, player number et son lvl --> Faire ça pour chaque joueur.
	   bct, X & Y pos, quantité x 7 --> pour chaque joueur.
  */
  return (EXIT_SUCCESS);
}
