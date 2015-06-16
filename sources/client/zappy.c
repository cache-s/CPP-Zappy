/*
** zappy.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 18:52:31 2015 Martin Porrès
** Last update Tue Jun 16 18:55:29 2015 Martin Porrès
*/

#include	"client.h"

int	zappy(t_client *client)
{
  printf("Team name : %s\nPort : %d\nHostname : %s\n", client->team_name, client->port, client->hostname);
  return (EXIT_SUCCESS);
}
