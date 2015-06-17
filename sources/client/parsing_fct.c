/*
** parsing_fct.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 17:23:21 2015 Martin Porrès
** Last update Tue Jun 16 19:12:10 2015 Martin Porrès
*/

#include	"client.h"

int	arg_team(t_client *client, char *arg)
{
    if ((client->team_name = strdup(arg)) == NULL)
        return (my_error("Parsing : invalid team name\n"));
    return (EXIT_SUCCESS);
  }

int	arg_port(t_client *client, char *arg)
{
    if (my_regex(arg, "0123456789") == EXIT_FAILURE)
        return (my_error("Parsing : invalid port\n"));
    client->port = atoi(arg);
    return (EXIT_SUCCESS);
  }

int	arg_host(t_client *client, char *arg)
{
    if ((client->hostname = strdup(arg)) == NULL)
        return (my_error("Parsing : invalid hostname\n"));
    return (EXIT_SUCCESS);  
  }
