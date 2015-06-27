/*
** cmd_graphic.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Thu Jun 25 16:55:26 2015 Mathieu
** Last update Sat Jun 27 12:45:55 2015 Martin Porrès
*/

#include		"serveur.h"

char			*block_to_str(t_block *block)
{
  char			*cmd;
  int			i;
  
  i = 0;
  cmd = strdup("bct");
  if ((cmd = realloc(cmd, strlen(itoa(block->x)) + strlen(itoa(block->y)) + 10)) == NULL)
    return (my_error_null(ERR_MALLOC));
  cmd = strcat(cmd, " ");
  cmd = strcat(cmd, itoa(block->x));
  cmd = strcat(cmd, " ");
  cmd = strcat(cmd, itoa(block->y));
  cmd = strcat(cmd, " ");
  while (i < 7)
    {
      if ((cmd = realloc(cmd, strlen(cmd) + strlen(itoa(block->items[i]) + 5))) == NULL)
  	return (my_error_null(ERR_REALLOC));
      cmd = strcat(cmd, itoa(block->items[i]));
      if (i + 1 != 7)
  	cmd = strcat(cmd, " ");
      i++;
    }
  return (cmd);
}

int			write_msz(t_serv *serv, t_client *client)
{
  char			*msz;
  
  if ((msz = malloc(sizeof(char) * 17)) == NULL)
    return (my_error(ERR_MALLOC));
  msz = strcpy(msz, "msz ");
  msz = strcat(msz, itoa(serv->settings->width));
  msz = strcat(msz, " ");
  msz = strcat(msz, itoa(serv->settings->height));
  if (my_write(client->fd, msz) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(msz);
  return (EXIT_SUCCESS);
}

int			write_sgt(t_serv *serv, t_client *client)
{
  char			*sgt;
  
  if ((sgt = malloc(sizeof(char) * 15)) == NULL)
    return (my_error(ERR_MALLOC));
  sgt = strcpy(sgt, "sgt ");
  sgt = strcat(sgt, itoa(serv->settings->delay));
  if (my_write(client->fd, sgt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(sgt);
  return (EXIT_SUCCESS);
}

int			write_tna(t_serv *serv, t_client *client)
{
  char			*str;
  char			*tna;
  char			*tmp;
  (void)client;

  tmp = strdup(serv->settings->teams);
  printf("%s\n", serv->settings->teams);
  str = strtok(tmp, ";");
  while (str != NULL)
    {
      if ((tna = malloc(strlen(str) + strlen("tna ") + 10)) == NULL)
      	return (my_error(ERR_MALLOC));
      tna = strcpy(tna, "tna ");
      tna = strcat(tna, str);
      if (my_write(client->fd, tna) == EXIT_FAILURE)
      	return (EXIT_FAILURE);
      str = strtok(NULL, ";");
    }
  free(str);
  return (EXIT_SUCCESS);
}

int			cmd_graphic(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  int			i;
  int			j;

  i = 0;
  if (move_to_gfx_list(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_msz(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_sgt(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (i < serv->settings->width)
    {
      j = 0;
      while (j < serv->settings->height)
	{
	  if (my_write(client->fd, block_to_str(&(serv->map->blocks[i][j]))) == EXIT_FAILURE)
	    return (my_error(ERR_MALLOC));
	  j++;
	}
      i++;
    }
  if (write_tna(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		move_to_gfx_list(t_serv *serv, t_client *client)
{
  t_client	*tmp;

 client->gfx = 1;
  if (serv->gfx == NULL)
    serv->gfx = client;
  else
    {
      tmp = serv->gfx;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = client;
    }
  if (serv->client == client)
    serv->client = client->next;
  else
    {
      tmp = serv->client;
      while (tmp->next != NULL && tmp->next != client)
	tmp = tmp->next;
      if (tmp->next == NULL)
	return (my_error("move_to_gfx_list : can't find gfx in the list"));
      tmp->next = client->next;
    }
  return (EXIT_SUCCESS);
}
