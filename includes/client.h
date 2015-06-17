/*
** client.h for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/includes
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 11:32:07 2015 Martin Porrès
** Last update Tue Jun 16 18:55:01 2015 Martin Porrès
*/

#ifndef			_CLIENT_H_
# define		_CLIENT_H_

# include		<unistd.h>
# include		<stdio.h>
# include		<stdlib.h>
# include		<string.h>
# include		"errors.h"

typedef			int(*args_fct)();
typedef			void(*f_tab)();

# define		MAX_ARGS	3
# define		MAX_LEN		3
# define		NB_CMD		12

enum			fnc_name
  {
    AVANCE		= 0,
    DROITE		= 1,
    GAUCHE		= 2,
    VOIR		= 3,
    INVENTAIRE		= 4,
    PREND		= 5,
    POSE		= 6,
    EXPULSE	        = 7,
    BROADCAST		= 8,
    INCANTATION		= 9,
    FORK		= 10,
    CONNECT_NBR		= 11,
  };

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
  char			*name_fnc[NB_CMD];
  f_tab			cmd[NB_CMD];
}			t_client;

int			parsing(int ac, char **av);
void			init_parsing(t_parser *parser);
int			get_pos_in_tab(t_parser *parser, char *cmd);
int			check_values(t_parser *parser, int ac);
int			arg_team(t_client *client, char *arg);
int			arg_port(t_client *client, char *arg);
int			arg_host(t_client *client, char *arg);
int			my_regex(char *val, char *good);
int			zappy(t_client *client);


// CMD
void			cmd_avance();
void			cmd_droite();
void			cmd_gauche();
void			cmd_voir();
void			cmd_inventaire();
void			cmd_prend();
void			cmd_pose();
void			cmd_expulse();
void			cmd_broadcast();
void			cmd_incantation();
void			cmd_fork();
void			cmd_connect_nbr();

#endif
