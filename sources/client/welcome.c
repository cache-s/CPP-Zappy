/*
** welcome.c for zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jun 26 11:54:22 2015 Martin Porrès
** Last update Fri Jun 26 15:13:17 2015 Martin Porrès
*/

#include	"client.h"

int			init_connection(t_client *client)
{
  char			*tmp;
  int			is_tok;

  is_tok = 0;
  if (client->init == 0) // WELCOME
    if (strcmp("BIENVENUE\n", client->srv_cmd) != 0)
      return (my_error(ERR_WELCOME));
    else
      {
	client->init++;
	if ((client->clt_cmd = strdup(client->team_name)) == NULL)
	  return (my_error(ERR_STRDUP));
      }// END WELCOME
  else
    {
      if (client->init == 1)
	{	  // NUM CLIENT
	  if ((tmp = strtok(client->srv_cmd, "\n")) == NULL)
	    return (my_error(ERR_WELCOME));
	  else
	    {
	      is_tok++;
	      if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
		return (my_error(ERR_WELCOME));
	      client->num_client = atoi(tmp);
	      client->init++;
	    } // END NUM CLIENT
	}      // PLAYER POS
      if (is_tok)
	{
	  if ((tmp = strtok(NULL, " ")) == NULL)
	    return (EXIT_SUCCESS);
	}
      else
	if ((tmp = strtok(client->srv_cmd, " ")) == NULL)
	  return (EXIT_SUCCESS);	  
      if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
	return (my_error(ERR_WELCOME));
      client->x = atoi(tmp);
      if ((tmp = strtok(NULL, "\n")) == NULL)
	return (my_error(ERR_WRITE));
      if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
	return (my_error(ERR_WELCOME));
      client->y = atoi(tmp);
      client->init++;
      if (client->srv_cmd != NULL)
	free(client->srv_cmd);
      client->srv_cmd = "";
      // call ai for settings
      printf("Num client : %d\nX : %d\n Y : %d\n", client->num_client, client->x, client->y);
      // END PLAYER POS
    }
  return (EXIT_SUCCESS);
}
