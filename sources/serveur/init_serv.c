/*
** init_serv.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Wed Mar 11 11:07:30 2015 Mathieu Bourmaud
** Last update Thu May  7 14:56:34 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

int			new_client(t_serv *serv)
{
  int			cs;
  int			client_len;

  client_len = sizeof(serv->init.sin_client);
  if ((cs = accept(serv->socket, (struct sockaddr *)&(serv->init.sin_client),
		   (socklen_t *)&client_len)) == -1)
    return (my_error_close(ERR_ACCEPT, serv->socket));
  if (cs > serv->fds)
    serv->fds = cs;
  if (my_write(2, "New client connected on the server") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (create_client(serv, cs) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (welcome_msg(serv, cs) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			create_client(t_serv *serv, int fd)
{
  t_client		*new;
  t_client		*tmp;

  if ((new = malloc(sizeof(t_client))) == NULL)
    return (my_error(ERR_MALLOC));
  new->cmd = NULL;
  new->need_write = 0;
  new->next = NULL;
  new->fd = fd;
  new->fct_read = client_read;
  new->fct_write = client_write;
  new->orientation = 1;
  serv->nb_client++;
  if (serv->client == NULL)
    {
      serv->client = new;
      return (EXIT_SUCCESS);
    }
  tmp = serv->client;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (EXIT_SUCCESS);
}

int			accept_clients(t_serv *serv)
{
  empty_fds(serv);
  if ((select(serv->fds + 1, &serv->readfds,
	      &serv->writefds, NULL, NULL)) == -1)
    return (my_error_close(ERR_SELECT, serv->socket));
  if (FD_ISSET(serv->socket, &serv->readfds))
    new_client(serv);
   check_fds_states(serv);
  return (EXIT_SUCCESS);
}

int			init_server(t_serv *serv)
{
  if ((serv->init.pe = getprotobyname("TCP")) == NULL)
    return (my_error(ERR_GETPROTO));
  if ((serv->socket = socket(AF_INET, SOCK_STREAM,
			    serv->init.pe->p_proto)) == -1)
    return (my_error_close(ERR_SOCKET, serv->socket));
  serv->init.sin.sin_family = AF_INET;
  serv->init.sin.sin_port = htons(port);
  serv->init.sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(serv->socket, (const struct sockaddr *)&(serv->init.sin),
	   sizeof(serv->init.sin)) == -1)
    return (my_error_close(ERR_BIND, serv->socket));
  if (listen(serv->socket, MAX_FD) == -1)
    return (my_error_close(ERR_LISTEN, serv->socket));
  init_AI_tabs(serv);
  while (42)
    if (accept_clients(serv) == EXIT_FAILURE)
      return (my_error(ERR_ACCEPT));
  close(serv->socket);
  return (EXIT_SUCCESS);
}
