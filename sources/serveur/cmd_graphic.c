/*
** cmd_graphic.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Thu Jun 25 16:55:26 2015 Mathieu
** Last update Thu Jun 25 16:55:26 2015 Mathieu
*/

#include		"serveur.h"

char			*block_to_str(t_block *block)
{
  char			*cmd;
  int			i;
  
  i = 0;
  cmd = strdup("bct");
  if ((cmd = realloc(cmd, strlen(itoa(block->x)) + strlen(itoa(block->y)) + 8)) == NULL)
    return (my_error_null(ERR_MALLOC));
  cmd = strcat(cmd, " ");
  cmd = strcat(cmd, itoa(block->x));
  cmd = strcat(cmd, " ");
  cmd = strcat(cmd, itoa(block->y));
  cmd = strcat(cmd, " ");
  while (i < 7)
    {
      if ((cmd = realloc(cmd, strlen(cmd) + strlen(itoa(block->items[i]) + 4))) == NULL)
  	return (my_error_null(ERR_REALLOC));
      cmd = strcat(cmd, itoa(block->items[i]));
      if (i + 1 != 7)
  	cmd = strcat(cmd, " ");
      i++;
    }
  return (cmd);
}

int			cmd_graphic(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  char			*msz;
  int			i;
  int			j;

  i = 0;
  if ((msz = malloc(sizeof(char) * 17)) == NULL)
    return (my_error(ERR_MALLOC));
  msz = strcpy(msz, "msz ");
  msz = strcat(msz, itoa(serv->settings->width));
  msz = strcat(msz, " ");
  msz = strcat(msz, itoa(serv->settings->height));
  if (my_write(client->fd, msz) == EXIT_FAILURE)
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
  return (EXIT_SUCCESS);
}
