/*
** serveur.h for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp/includes
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 09:44:26 2015 Mathieu Bourmaud
** Last update Tue Jun 16 13:11:45 2015 Sebastien Cache-Delanos
*/

#ifndef			_SERVEUR_H_
# define		_SERVEUR_H_

# include		<stdio.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/wait.h>
# include		<netdb.h>
# include		<unistd.h>
# include		<stdio.h>
# include		<stdlib.h>
# include		<arpa/inet.h>
# include		<netinet/in.h>
# include		<string.h>
# include		"commons_fcts.h"

# define		MAX_FD		1000
# define		BUFF_SIZE	5
# define		NB_CMDS		12
# define		WELCOME		"Welcome to the server : "
# define		SRV_USAGE	"To use the server, you must register\
 by typing /nick [username] or NICK [username]."

#define			UNUSED		__attribute__((unused))

typedef struct		s_init_serv
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;
}			t_init_serv;

typedef			int(*tabFcts)();
typedef			char *(*fct)();

typedef struct		s_client
{
  char			*nick;
  char			*channel;
  fct			fct_read;
  fct			fct_write;
  char			connected;
  char			isRegistered;
  int			fd;
  char			need_write;
  char			*cmd;
  struct s_client	*next;
}			t_client;

typedef struct		s_serv
{
  int			port;
  int			socket;
  int			fds;
  fd_set		readfds;
  fd_set		writefds;
  fct			fct_read;
  char			*ip;
  char			**AIFcts;
  tabFcts		cmds[NB_CMDS];
  t_init_serv		init;
  int			nb_client;
  t_client		*client;
}			t_serv;

int		init_AI_tabs(t_serv *serv);
void		init_AI_cmds(t_serv *serv);
int		new_client(t_serv *serv);
int		create_client(t_serv *serv, int cs);
int		accept_clients(t_serv *serv);
int		init_server(int port);
char		*close_connect(t_serv *serv, int fd);

int		my_write(int fd, char *str);
void		empty_fds(t_serv *serv);
void		check_fds_states(t_serv *serv);
char		*client_read(t_serv *serv, int fd);
char		*server_read(t_serv *serv, int i);
char		*client_write(t_serv *serv, int i, char *cmd);

int		call_cmds(t_serv *serv, char *cmd);

int		close_first_elem(t_client *client, t_serv *serv, int fd);
int		welcome_msg(t_serv *serv, int fd);
int		count_char(char *str, char c);

int		cmd_move_forward(t_serv *serv, t_client *client, char *cmd);
int		cmd_right(t_serv *serv, t_client *client, char *cmd);
int		cmd_left(t_serv *serv, t_client *client, char *cmd);
int		cmd_see(t_serv *serv, t_client *client, char *cmd);
int		cmd_inventory(t_serv *serv, t_client *client, char *cmd);
int		cmd_take(t_serv *serv, t_client *client, char *cmd);
int		cmd_drop(t_serv *serv, t_client *client, char *cmd);
int		cmd_kick(t_serv *serv, t_client *client, char *cmd);
int		cmd_broadcast(t_serv *serv, t_client *client, char *cmd);
int		cmd_incantation(t_serv *serv, t_client *client, char *cmd);
int		cmd_fork(t_serv *serv, t_client *client, char *cmd);
int		cmd_connect_nbr(t_serv *serv, t_client *client, char *cmd);

#endif
