/*
** handleCmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 12:57:34 2015 Jordan Chazottes
** Last update Mon Jul  6 17:42:18 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		handle_cmd(t_gfx *s)
{
  char		*end_str;
  char		*token;

  if (server_read(s) == EXIT_FAILURE)
    return (my_error(ERR_SERVER));
  if (s->network.entire_cmd == 1)
    {
      if (s->network.init == 0)
	return (welcome_serv(s));
      if ((token = strtok_r(strdup(s->network.cmd), "\n", &end_str)) == NULL)
	return (EXIT_FAILURE);
      while (token != NULL)
	{
	  if (get_cmd(s, token) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  token = strtok_r(NULL, "\n", &end_str);
	}
      if (token != NULL)
	free(token);
      if (s->network.cmd != NULL)
	free(s->network.cmd);
      s->network.cmd = NULL;
    }
  return (EXIT_SUCCESS);
}
