/*
** errors.h for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:00:38 2015 Mathieu Bourmaud
** Last update Thu Jun 25 18:25:33 2015 Martin Porrès
*/

#ifndef		_ERRORS_H_
# define	_ERRORS_H_

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"colors.h"

/* NETWORK ERRORS */
#define		ERR_PORT		"The port is not available. It must contains only numbers"
#define		ERR_USAGE_SRV		"Usage : ./server [-p port] [-x world_x] [-y world_y] [-c max_clients] [-t speed] -n team_name1 team_name2 ..."
#define		ERR_USAGE_CLT		"Usage : ./client -n \"team name\" -p port [-h hostname]\n"
#define		ERR_INIT_CLT		"init_client() has failed"
#define		ERR_INIT_SRV		"init_server() has failed"
#define		ERR_SOCKET		"socket() has failed."
#define		ERR_BIND		"bind() has failed."
#define		ERR_LISTEN		"listen() has failed."
#define		ERR_SELECT		"select() has failed."
#define		ERR_ACCEPT		"accept() has failed."
#define		ERR_CONNECT		"connect() has failed."
#define		ERR_GETPROTO		"getprotobyname() has failed."
#define		ERR_READ		"read() has failed"
#define		ERR_WRITE		"write() has failed"
#define		ERR_WELCOME		"Error : wrong welcome message"
#define		ERR_SERVER		"Error : server disconnected"

/* COMMON ERRORS */
#define		ERR_MEMSET		"memset() has failed"
#define		ERR_REALLOC		"realloc() has failed"
#define		ERR_MALLOC		"malloc() has failed"
#define		ERR_CWD			"getcwd() has failed"
#define		ERR_CHDIR		"chdir() has failed"
#define		ERR_STRDUP		"strdup() has failed"
#define		ERR_STRCAT		"strcat() has failed"
#define		ERR_STRCPY		"strcpy() has failed"

/* ARUGMENTS ERRORS */
#define		ERR_NB_TEAMS		"Error : the game can't start with only one team"
#define		ERR_UNIQUE_TEAM		"Error : each team must be unique"
#define		ERR_SPEED		"Error : the speed must be between 1 and 1000000"
#define		ERR_SIZE_X		"Error : the width must be between 1 and 10000"
#define		ERR_SIZE_Y		"Error : the height must be between 1 and 10000"
#define		MAX_SPEED		1000000
#define		MIN_X			1
#define		MIN_Y			1
#define		MAX_X			10000
#define		MAX_Y			10000

int		my_error(const char *);
char		*my_error_null(const char *);
int		my_error_close(const char *, int);

#endif
