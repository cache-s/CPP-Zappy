/*
** parsing.c for Zappy in /home/porres_m/Projets/SysUnix/zappy/PSU_2014_zappy/sources/client
** 
** Made by Martin Porrès
** Login   <porres_m@epitech.net>
** 
** Started on  Tue Jun 16 11:26:51 2015 Martin Porrès
** Last update Tue Jun 16 18:54:21 2015 Martin Porrès
*/

#include	"client.h"

void	init_parsing(t_parser *parser)
{
  bzero(parser->occArgs, MAX_ARGS * sizeof(int));
  strcpy(parser->tabArgs[0], "-n");
  strcpy(parser->tabArgs[1], "-p");
  strcpy(parser->tabArgs[2], "-h");
  parser->args[0] = arg_team;
  parser->args[1] = arg_port;
  parser->args[2] = arg_host;
}

int	get_pos_in_tab(t_parser *parser, char *cmd)
{
  int	i;

  i = 0;
  while (i < MAX_ARGS)
    {
      if (strcmp(cmd, parser->tabArgs[i]) == 0)
	{
	  parser->occArgs[i] += 1;
	  return (i);
	}
      i++;
    }
  return (-1);
}

int	check_values(t_parser *parser, int ac)
{
  int	i;

  i = 0;
  while (i < MAX_ARGS - 1)
    if (parser->occArgs[i++] != 1)
      return (EXIT_FAILURE);
  if (ac == (MAX_ARGS * 2 + 1) &&  parser->occArgs[i] != 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	parsing(int ac, char **av)
{
  int	i;
  int	pos;
  t_parser	parser;
  t_client	client;

  if (ac != (MAX_ARGS * 2 - 1) && ac != (MAX_ARGS * 2 + 1))
    {
      printf(ERR_USAGE_CLT);
      return (EXIT_SUCCESS);
    }
  init_parsing(&parser);
  i = 0;
  while (++i < ac - 1)
    if ((pos = get_pos_in_tab(&parser, av[i])) != -1)
      if (parser.args[pos](&client, av[i + 1]) == EXIT_FAILURE)
	return (EXIT_FAILURE);
  if (check_values(&parser, ac) == EXIT_FAILURE)
    {
      printf(ERR_USAGE_CLT);
      return (EXIT_SUCCESS);
    }
  if (ac == (MAX_ARGS * 2 - 1))
    if (parser.args[2](&client, "localhost") == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (zappy(&client));
}
