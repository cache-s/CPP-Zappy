/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:20:56 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_inventory(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "cmd_inventory") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  
  /* 
     Renvoie l'inventaire du player.
     -
     
     char *my_inv;
     while (player->inv != vide)
     my_inv = strcat(player->inv[x]);

     Send to GFX : Rien
     Send to IA : linemate n, sibur n [...]
  */
  return (EXIT_SUCCESS);
}
