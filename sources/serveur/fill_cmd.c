/*
** fill_cmd.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Sun Jul  5 16:49:02 2015 Mathieu
** Last update Sun Jul  5 16:49:02 2015 Mathieu
*/

#include		"serveur.h"

int			check_cmd_before_fill(char *cmd, t_client *tmp,
					      t_serv *serv, int *end)
{
  char			*cpy;

  cpy = strdup(cmd);
  cpy = strtok(cpy, "\n");
  if (cpy != NULL)
    printf(BOLD BLUE "Received message '%s' from %d\n" END, cpy, tmp->fd);
  if (cmd == NULL || strcmp(cmd, "") == 0 || strlen(cmd) == 1)
    return (EXIT_FAILURE);
  if (tmp->is_full == 1)
    {
      printf(BOLD RED "Sending message '%s' to %d\n" END, "ko", tmp->fd);
      if (my_write(tmp->fd, "ko") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_FAILURE);
    }
  if (count_char(cmd, '\n') >= 1)
    {
      cmd = strtok(cmd, "\n");
      *end = 1;
    }
  if (check_call_cmds(serv, cmd, tmp) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			check_call_cmds(t_serv *serv, char *cmd, t_client *client)
{
  char			*save;

  save = strdup(cmd);
  if (count_char(cmd, ' ') >= 1)
    save = strtok(save, " ");
  if (call_cmds(serv, save) == 42)
    {
      printf(BOLD RED "Sending message '%s' to %d\n" END, "ko", client->fd);
      if (my_write(client->fd, "ko") == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			fill_cmd(char *cmd, t_client *tmp, t_serv *serv)
{
  int			end;

  end = 0;
  if (check_cmd_before_fill(cmd, tmp, serv, &end) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (tmp->cmd == NULL)
    {
      tmp->cmd = strdup(cmd);
      if ((tmp->cmd = realloc(tmp->cmd, strlen(tmp->cmd) + 3)) == NULL)
	return (my_error(ERR_REALLOC));
      tmp->cmd = strcat(tmp->cmd, ";");
    }
  else
    {
      if ((tmp->cmd = realloc(tmp->cmd, strlen(tmp->cmd)
			      + strlen(cmd) + 3)) == NULL)
	return (my_error(ERR_REALLOC));
      tmp->cmd = strcat(tmp->cmd, cmd);
      if (end == 1)
	tmp->cmd = strcat(tmp->cmd, ";");
      if (count_char(tmp->cmd, ';') >= 10)
	tmp->is_full = 1;
    }
  return (EXIT_SUCCESS);
}
