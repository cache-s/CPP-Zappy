/*
** client.h for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/includes
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 11:32:07 2015 Martin Porrès
** Last update Tue Jun 16 11:59:04 2015 Martin Porrès
*/

#ifndef		_CLIENT_H_
# define	_CLIENT_H_

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#define		USAGE "./client -n \"team name\" -p port [-h hostname]\n"

int		usage(int ac, char **av);

#endif
