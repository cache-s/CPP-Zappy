/*
** read_write.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri Mar 20 20:01:45 2015 Mathieu Bourmaud
** Last update Wed May  6 16:31:31 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

char			*client_write(t_serv *serv, int fd, char *line)
{
  char			*arg;
  char			*cmd;
  int			pos;
  char			*final;

  if (strcmp(line, "\n") == 0)
    return (NULL);
  line = strtok(line, "\n");
  if ((final = strdup(line)) == NULL)
    return (my_error_null(ERR_STRDUP));
  if ((cmd = strtok(line, " ")) == NULL)
    return (NULL);
  arg = strtok(NULL, "\n");
  pos = call_cmds(serv, cmd);
  if (pos == NB_CMDS)
    arg = strdup(final);
  if ((serv->cmds[pos](serv, fd, arg)) == EXIT_FAILURE)
    return (NULL);
  return ("toto");
}

char			*server_read(t_serv *serv, int i)
{
  (void)i;
  if ((my_write(1, "New user")) == EXIT_FAILURE)
    return (NULL);
  if (new_client(serv) == EXIT_FAILURE)
    return (NULL);
  return (NULL);
}

int			write_success(int fd, char *cmd, char *arg)
{
  if (write(fd, cmd, strlen(cmd)) == -1)
    return (EXIT_FAILURE);
  if (write(fd, " ", 1) == -1)
    return (EXIT_FAILURE);
  if (arg != NULL)
    if (write(fd, arg, strlen(arg)) == -1)
      return (EXIT_FAILURE);
  if (write(fd, " :", 2) == -1)
    return (EXIT_FAILURE);
  if (my_write(fd, " Success") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
