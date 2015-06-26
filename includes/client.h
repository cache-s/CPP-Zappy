/*
** client.h for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/includes
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 11:32:07 2015 Martin Porrès
** Last update Fri Jun 26 11:49:12 2015 Martin Porrès
*/

#ifndef			_CLIENT_H_
# define		_CLIENT_H_

#include		<unistd.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<arpa/inet.h>
#include		<netinet/in.h>
#include		<netdb.h>
#include		"errors.h"

typedef			int(*args_fct)();

#define			MAX_ARGS	3
#define			MAX_LEN		3
#define			BUFF_SIZE	4096

typedef struct		s_parser
{
  args_fct		args[MAX_ARGS];
  char			tabArgs[MAX_ARGS][MAX_LEN];
  int			occArgs[MAX_ARGS];
}			t_parser;

typedef struct		s_client
{
  char			*team_name;
  int			port;
  char			*hostname;
  int			fd_socket;
  int			num_client;
  int			x;
  int			y;
  int			entire_cmd;
  int			init;
  char			*srv_cmd;
  char			*clt_cmd;
}			t_client;

int			parsing(int ac, char **av);
void			init_parsing(t_parser *parser);
int			get_pos_in_tab(t_parser *parser, char *cmd);
int			check_values(t_parser *parser, int ac);
int			arg_team(t_client *client, char *arg);
int			arg_port(t_client *client, char *arg);
int			arg_host(t_client *client, char *arg);
int			my_regex(char *val, char *good);
int			connect_to_server(t_client *client);
int			client_loop(t_client *client);
int			server_read(t_client *client);
int			save_srv_cmd(t_client *client, char *buffer);
int			init_connection(t_client *client);
int			write_cmd(t_client *client, fd_set *fd_write);
int			handle_cmd(t_client *client, fd_set *fd_write);

#endif
