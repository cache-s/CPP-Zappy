/*
** serveur.h for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp/includes
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 09:44:26 2015 Mathieu Bourmaud
** Last update Fri Jun 26 13:31:24 2015 Jordan Chazottes
*/

#ifndef			_SERVEUR_H_
# define		_SERVEUR_H_

# include		<stdio.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/wait.h>
# include		<time.h>
# include		<netdb.h>
# include		<unistd.h>
# include		<stdio.h>
# include		<stdlib.h>
# include		<arpa/inet.h>
# include		<netinet/in.h>
# include		<string.h>
# include		"commons_fcts.h"

# define		MAX_ARGS	6
# define		MAX_FD		1000
# define		BUFF_SIZE	5
# define		NB_CMDS		13
# define		WELCOME		"BIENVENUE\n"

#define			UNUSED		__attribute__((unused))

typedef			int(*tabFcts)();
typedef			char *(*fct)();
typedef			int(*argsFct)();

typedef struct		s_init_serv
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;
}			t_init_serv;

typedef struct		s_parser
{
  argsFct		args[MAX_ARGS + 1];
  char			**tabArgs;
  int			*occArgs;
}			t_parser;

typedef struct		s_settings
{
  int			port;
  int			width;
  int			height;
  char			*teams;
  int			nb_clients;
  int			delay;
  t_parser		parser;
}			t_settings;

typedef struct		s_client
{
  fct			fct_read;
  fct			fct_write;
  int			fd;
  char			*team;
  char			need_write;
  char			*cmd;
  int			orientation;
  int			x;
  int			y;
  char			gfx;
  int			x;
  int			y;
  int			items[7];
  struct s_client	*next;
}			t_client;

typedef struct		s_block
{
  int			x;
  int			y;
  int			items[7];
}			t_block;

typedef struct		s_map
{
  t_block	       	**blocks;
}			t_map;

typedef struct		s_serv
{
  int			port;
  int			socket;
  int			fds;
  fd_set		readfds;
  fd_set		writefds;
  fct			fct_read;
  char			**AIFcts;
  tabFcts		cmds[NB_CMDS];
  t_init_serv		init;
  t_map			*map;
  t_client		*client;
  t_settings		*settings;
  t_parser		parse;
  int			nb_client;
  char			**items;
}			t_serv;

int		init_settings(t_settings *settings);
t_settings	*parse_args(char **av);
int		init_AI_tabs(t_serv *serv);
void		init_AI_cmds(t_serv *serv);
int		new_client(t_serv *serv);
int		create_client(t_serv *serv, int cs);
int		accept_clients(t_serv *serv);
int		init_server(t_serv *serv);
char		*close_connect(t_serv *serv, int fd);

int		my_write(int fd, char *str);
void		empty_fds(t_serv *serv);
void		check_fds_states(t_serv *serv);
char		*client_read(t_serv *serv, int fd);
char		*server_read(t_serv *serv, int i);
char		*client_write(t_serv *serv, int i, char *cmd);

int		call_cmds(t_serv *serv, char *cmd);
int		check_values(t_settings *settings);

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
int		cmd_graphic(t_serv *serv, t_client *client, char *cmd);

int		fill_port(t_settings *settings, char *av, int i);
int		fill_width(t_settings *settings, char *av, int i);
int		fill_height(t_settings *settings, char *av, int i);
int		fill_teams(t_settings *settings, char **av, int i);
int		fill_nb_clients(t_settings *settings, char *av, int i);
int		fill_delay(t_settings *settings, char *av, int i);

int		map_generation(t_serv *serv);
int		jewels_food_generation(t_block *block, int x, int y);
void		display_game_configuration(t_serv *serv);

int		write_msz(t_serv *serv, t_client *client);
int		write_sgt(t_serv *serv, t_client *client);
int		write_tna(t_serv *serv, t_client *client);

#endif
