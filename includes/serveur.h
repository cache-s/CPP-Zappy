/*
** serveur.h for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp/includes
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 09:44:26 2015 Mathieu Bourmaud
** Last update Fri Jul  3 14:51:18 2015 Martin Porrès
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
# define		BUFF_SIZE	500
# define		NB_CMDS		13
# define		WELCOME		"BIENVENUE\n"

#define			UNUSED		__attribute__((unused))

typedef			int(*tabFcts)();
typedef			char *(*fct)();
typedef			int(*argsFct)();

typedef enum		eOrientation
  {
    NORTH = 1,
    EST = 2,
    SOUTH = 3,
    WEST = 4
  }			eOrientation;

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
  int			*clients;
  int			nb_clients;
  int			delay;
  t_parser		parser;
}			t_settings;

typedef struct		s_client
{
  char			is_full;
  int			id;
  fct			fct_read;
  fct			fct_write;
  int			fd;
  char			*team;
  char			need_write;
  char			*cmd;
  char			*shortest_cmd;
  double		time_left;
  eOrientation		orientation;
  char			gfx;
  int			lvl;
  int			x;
  int			y;
  char			connected;
  int			items[7];
  int			cmd_end;
  double		lifetime;
  struct s_client	*next;
}			t_client;

typedef struct		s_see
{
  int			tmp_x_plus;
  int			tmp_x_less;
  int			tmp_y_plus;
  int			tmp_y_less;
  int			check;
  int			coma;
  int			end;
  int			lvl; // a remove
}			t_see;

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

typedef struct		s_timer
{
  time_t		start;
  time_t		end;
  time_t		elapsed;
}			t_timer;

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
  t_client		*gfx;
  t_settings		*settings;
  t_parser		parse;
  t_timer		timer;
  t_see			*see;
  int			nb_client;
  char			**items;
  double		cmd_time[12];
  int			inc_tab[8][7];
}			t_serv;

int		init_settings(t_settings *settings);
t_settings	*parse_args(char **av);
int		init_AI_tabs(t_serv *serv);
void		init_AI_cmds(t_serv *serv);
int		new_client(t_serv *serv);
int		create_client(t_serv *serv, int cs);
int		accept_clients(t_serv *serv);
int		init_server(t_serv *serv);
char		*close_connect(t_serv *serv, int fd, int type);
int		set_client_values(t_serv *serv, t_client *new, int fd);

int		my_write(int fd, char *str);
void		empty_fds(t_serv *serv);
void		check_fds_states(t_serv *serv, int type);
char		*client_read(t_serv *serv, int fd);
char		*server_read(t_serv *serv, int i);
char		*client_write(t_serv *serv, int i, char *cmd);

int		call_cmds(t_serv *serv, char *cmd);
int		check_values(t_settings *settings);

int		close_first_elem(t_client *tmp, t_serv *serv, int fd, int type);
int		welcome_msg(t_serv *serv, int fd);
int		count_char(char *str, char c);

int		cmd_move_forward(t_serv *serv, t_client *client, char *cmd);
void		modify_x(eOrientation orientation, t_client *client, int width);
void		modify_y(eOrientation orientation, t_client *client, int height);

int		cmd_right(t_serv *serv, t_client *client, char *cmd);
int		cmd_left(t_serv *serv, t_client *client, char *cmd);
int		cmd_see(t_serv *serv, t_client *client, char *cmd);
int		cmd_inventory(t_serv *serv, t_client *client, char *cmd);
int		cmd_take(t_serv *serv, t_client *client, char *cmd);
int		cmd_drop(t_serv *serv, t_client *client, char *cmd);
int		cmd_kick(t_serv *serv, t_client *client, char *cmd);
int		cmd_broadcast(t_serv *serv, t_client *client, char *cmd);
int		cmd_incantation(t_serv *serv, t_client *client, char *cmd);
int		cmd_end_incantation(t_serv *serv, t_client *client);
int		cmd_fork(t_serv *serv, t_client *client, char *cmd);
int		cmd_connect_nbr(t_serv *serv, t_client *client, char *cmd);
int		cmd_graphic(t_serv *serv, t_client *client, char *cmd);
int		check_team(t_serv *serv, t_client *client, char *cmd);
int		get_team_pos(t_serv *serv, char *team);
int		get_item_number(t_serv *serv, char *cmd);
int		get_k(t_settings *settings, t_client *speaker, t_client *listener);
int		find_closest_path(int map_size, int speaker, int listener);
int		set_path_orientation(int x, int y);
int		find_best_orientation(int x, int y, int base);
int		set_real_orientation(int o, eOrientation client_o);
int		see_with_orientation(t_serv *serv, t_client *client);
int		look_floor(int x, int y, t_serv *serv, t_client *client);
int		up_players(t_serv *serv, t_client *client);
void		empty_block(t_block *block);
int		kick_player(t_serv *serv, t_client *kicker, t_client *kicked, int k);

int		fill_port(t_settings *settings, char *av, int i);
int		fill_width(t_settings *settings, char *av, int i);
int		fill_height(t_settings *settings, char *av, int i);
int		fill_teams(t_settings *settings, char **av, int i);
int		fill_teams_tabs(t_settings *settings);
int		fill_nb_clients(t_settings *settings, char *av, int i);
int		fill_delay(t_settings *settings, char *av, int i);

int		move_to_gfx_list(t_serv *serv, t_client *client);
int		map_generation(t_serv *serv);
int		jewels_food_generation(t_block *block, int x, int y);
void		display_game_configuration(t_serv *serv);
int		generate_random_item(t_serv *serv, int item, int nb);
int		generate_all_item(t_serv *serv, int nb);

void		write_tna(t_serv *serv, int fd);
void		write_bct(t_block *block, int fd);
int		write_bct_gfx(t_client *gfx, t_block *block);
int		write_pin_gfx(t_client *gfx, t_client *client);
int		write_ppo_gfx(t_client *gfx, t_client *client);
int		write_pgt_gfx(t_client *gfx, t_client *client, int item);
int		write_pdr_gfx(t_client *gfx, t_client *client, int item);
int		write_to_gfx(t_client *gfx, char *msg);
int		write_pbc_gfx(t_client *gfx, t_client *client, char *cmd);
int		write_pnw_gfx(t_client *gfx, t_client *client);
int		write_pdi_gfx(t_client *gfx, t_client *client);
int		write_pic_gfx(t_serv *serv, t_client *client);
int		write_pic_end(t_serv *serv, t_client *client, char *ids);
int		write_pie_gfx(t_client *gfx, t_client *client, int r);
int		write_plv_gfx(t_client *gfx, t_client *client);
int		write_pex_gfx(t_client *gfx, t_client *client);
int		write_pfk_gfx(t_client *gfx, t_client *client);
int		write_enw_gfx(t_client *gfx, t_client *client);
int		write_eht_gfx(t_client *gfx, int id);

int		write_ok(int fd, int ok);

int		get_the_shortest_cmd(t_serv *serv);
double		get_delay(t_serv *serv, char *cmd);
void		set_delay_tab(t_serv *serv);
int		update_timers(t_serv *serv, struct timeval *tv, double time);
int		update_client(t_client *client, t_serv *serv);

int		inc_lvl(t_serv *serv, t_client *client);
int		inc_count_player(t_serv *serv, t_client *client);
void		init_inc_tab(t_serv *serv);
void		init_inc_tab_2(t_serv *serv);
void		init_inc_tab_3(t_serv *serv);

#endif
