/*
** client.h for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/includes
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 11:32:07 2015 Martin Porrès
** Last update Tue Jun 16 18:55:01 2015 Martin Porrès
*/

#ifndef		_CLIENT_H_
# define	_CLIENT_H_

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"errors.h"

typedef		int(*args_fct)();

#define		MAX_ARGS	3
#define		MAX_LEN		3

typedef struct	s_parser
{
  args_fct	args[MAX_ARGS];
  char		tabArgs[MAX_ARGS][MAX_LEN];
  int		occArgs[MAX_ARGS];
}		t_parser;

typedef struct	s_client
{
  char		*team_name;
  int		port;
  char		*hostname;
}		t_client;

int		parsing(int ac, char **av);
void		init_parsing(t_parser *parser);
int		get_pos_in_tab(t_parser *parser, char *cmd);
int		check_values(t_parser *parser, int ac);
int		arg_team(t_client *client, char *arg);
int		arg_port(t_client *client, char *arg);
int		arg_host(t_client *client, char *arg);
int		my_regex(char *val, char *good);
int		zappy(t_client *client);

#endif
