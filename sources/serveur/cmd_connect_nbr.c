/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Mon Jun 15 16:27:54 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			cmd_connect_nbr(t_serv *serv, t_client *client, char *cmd)
{
  (void)serv;
  (void)cmd;
  if (my_write(client->fd, "connect_nbr") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /* 
     Nombre de Slot non utilisé par l'équipe 
     
     Renvoyer à L'IA la valeur.
  */
  return (EXIT_SUCCESS);
}
