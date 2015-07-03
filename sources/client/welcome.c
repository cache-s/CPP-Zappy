/*
** welcome.c for zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jun 26 11:54:22 2015 Martin Porrès
** Last update Fri Jul  3 16:27:23 2015 Martin Porrès
*/

#include	"client.h"
#include	"AI_c_connector.h"

int		init_connection(t_client *client)
{

  if (client->init == 0)
    {
      if (welcome(client) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      if (client->clt_cmd != NULL)
	{
	  free(client->clt_cmd);
	  client->clt_cmd = NULL;
	}
      if (init_num_and_pos(client) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		init_num_and_pos(t_client *client)
{
  int		is_tok;
  char		*tmp;

  is_tok = 0;
  tmp = NULL;
  if (num_client(client, &is_tok, tmp) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (is_tok)
    {
      if ((tmp = strtok(NULL, " ")) == NULL)
	return (EXIT_SUCCESS);
    }
  else
    if ((tmp = strtok(client->srv_cmd, " ")) == NULL)
      return (EXIT_SUCCESS);	  
  if (pos_client(client, tmp) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		welcome(t_client *client)
{
  if (strcmp("BIENVENUE\n", client->srv_cmd) != 0)
    return (my_error(ERR_WELCOME));
  else
    {
      client->init++;
      if ((client->clt_cmd = strdup(client->team_name)) == NULL)
	return (my_error(ERR_STRDUP));
    }
  return (EXIT_SUCCESS);
}

int		num_client(t_client *client, int *is_tok, char *tmp)
{
  if (client->init == 1)
    {
      if ((tmp = strtok(client->srv_cmd, "\n")) == NULL)
	return (my_error(ERR_WELCOME));
      else
	{
	  (*is_tok)++;
	  if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
	    return (my_error(ERR_WELCOME));
	  client->num_client = atoi(tmp);
	  client->init++;
	}
    }
  return (EXIT_SUCCESS);
}

int		pos_client(t_client *client, char *tmp)
{
  if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
    return (my_error(ERR_WELCOME));
  client->x = atoi(tmp);
  if ((tmp = strtok(NULL, "\n")) == NULL)
    return (my_error(ERR_WRITE));
  if (my_regex(tmp, "0123456789") == EXIT_FAILURE)
    return (my_error(ERR_WELCOME));
  client->y = atoi(tmp);
  client->init++;
  client->srv_cmd = "";
  srand(time(NULL));
  AI_setId(rand());
  return (EXIT_SUCCESS);
}
