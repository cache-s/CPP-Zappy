/*
** initNetwork.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 23 13:04:16 2015 Jordan Chazottes
** Last update Tue Jun 23 19:34:22 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		new_client(t_gfx *s)
{
  int		cs;
  int		client_len;

  client_len = sizeof(s->network.sin_client);
  if ((cs = accept(s->network.socket, (struct sockaddr *)&(s->network.sin_client),
		   (socklen_t *)&client_len)) == -1)
    return (my_error_close(ERR_ACCEPT, s->network.socket));
  if (my_write(2, "connected") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (create_client(s, cs) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (welcome_msg(cs) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

char		*client_read()
{
  return NULL;
}

char		*client_write()
{
  return NULL;
}

int		welcome_msg(int cs)
{
  if (write(cs, "GRAPHIC\n", 8) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		create_client(t_gfx *s, int fd)
{
  t_server	*new;
  
  if ((new = malloc(sizeof(t_server))) == NULL)
    return (my_error(ERR_MALLOC));
  new->fd = fd;
  new->fct_read = client_read;
  new->fct_write = client_write;
  new->need_write = 0;
  s->server = new;
  return (EXIT_SUCCESS);
}

int		accept_client(t_gfx *s)
{
  FD_ZERO(&s->network.readfd);
  FD_ZERO(&s->network.writefd);
  FD_SET(s->network.socket, &s->network.readfd);
  if ((select(2, &s->network.readfd, &s->network.writefd, NULL, NULL)) == -1)
    return (my_error_close(ERR_SELECT, s->network.socket));
  if (FD_ISSET(s->network.socket, &s->network.readfd))
    new_client(s);
  /* check_fds_states(s); */
  return (EXIT_SUCCESS);
}

int		initNetwork(t_gfx *s)
{
  if ((s->network.pe = getprotobyname("TCP")) == NULL)
    return (my_error(ERR_GETPROTO));
  if ((s->network.socket = socket(AF_INET, SOCK_STREAM, s->network.pe->p_proto)) == -1)
    return (my_error_close(ERR_SOCKET, s->network.socket));
  s->network.sin.sin_family = AF_INET;
  s->network.sin.sin_port = htons(4242);
  s->network.sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s->network.socket, (const struct sockaddr *)&(s->network.sin),
	   sizeof(s->network.sin)) == -1)
    return (my_error_close(ERR_BIND, s->network.socket));
  if (listen(s->network.socket, MAX_FD) == -1)
    return (my_error_close(ERR_LISTEN, s->network.socket));
  while (42 + 2 - 4 / 8 + 72)
    {
      if (accept_client(s) == EXIT_FAILURE)
	return (my_error(ERR_ACCEPT));
      //read&write
      //draw
    }
  close(s->network.socket);
  return (EXIT_SUCCESS);
}
