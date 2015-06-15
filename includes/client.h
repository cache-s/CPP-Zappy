/*
** client.h for myFTP in /home/porres_m/Projets/SysUnix/myftp/PSU_2014_myftp/includes
** 
** Made by Martin Porres
** Login   <porres_m@epitech.net>
** 
** Started on  Mon Mar  9 14:23:39 2015 Martin Porres
** Last update Sat Apr 11 16:22:41 2015 Martin Porrès
*/

#ifndef		_CLIENT_H_
# define	_CLIENT_H_

#include	<netdb.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"commons_fcts.h"

#define		USAGE		"fils de chienne"

#define		BUFFER_LEN	4096
#define		NB_CMD		12

enum		e_cmd
  {
    SERVER,
    USER,
    NICK,
    LIST,
    JOIN,
    PART,
    USERS,
    MSG,
    SEND,
    ACCEPT,
    HELP,
    QUIT,
    UNKNOWN
  };

typedef struct	s_env
{
  int		port;
  char		*ip;
  int		fd_socket;
  int		quit;
  char		*cmd[NB_CMD];
  char		*tab[NB_CMD];
}		t_env;

int		client();
int		server_connect(t_env *);
int		set_ip_port(t_env *, char *);
int		do_select(t_env *);
int		create_client(t_env *);
int		server_write(t_env *);
int		server_read(t_env *);
int		set_cmd(t_env *);
int		set_tab(t_env *);
char		*parse_stdin(t_env *, char *);
char		*new_cmd(t_env *, char *, int, char *);
void		retr_cmd(t_env *, char *);
void		check_retr(t_env *, char *, char *, FILE *);
void		stor_cmd(t_env *);
char		*alloc_str(char *, int, char[]);

#endif		/* _CLIENT_H_ */
