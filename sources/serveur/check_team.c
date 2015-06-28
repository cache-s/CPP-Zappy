/*
** check_team.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jun 28 18:23:25 2015 Mathieu
** Last update Sun Jun 28 18:23:25 2015 Mathieu
*/

#include		"serveur.h"

int			check_team(t_serv *serv, t_client *client, char *cmd)
{
  if (strcmp(cmd, "GRAPHIC\n") == 0)
    return (cmd_graphic(serv, client, cmd));
  if (strstr(serv->settings->teams, cmd) != NULL)
    {
      client->team = strdup(cmd);
      client->connected = 1;
      if (my_write(client->fd, "ok") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      // Envoyer NUM-CLIENT (nb client restant pouvant se co)
      // Envoyer X Y
    }
  else  
    if (my_write(client->fd, "ko") == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
