/*
** handleCmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 12:57:34 2015 Jordan Chazottes
** Last update Sun Jun 28 16:16:44 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		handleCmd(t_gfx *s)
{
  char		*str;
  char		*end_str;
  char		*token;

  if (server_read(s) == EXIT_FAILURE)
    return (my_error(ERR_SERVER));
  if (s->network.entire_cmd == 1)
    {
      if (s->network.init == 0)
	return (welcomeServ(s));
      str = strdup(s->network.cmd);
      token = strtok_r(str, "\n", &end_str);
      while (token != NULL)
	{
	  getCmd(s, token);
	  token = strtok_r(NULL, "\n", &end_str);
	}
    }
  return (EXIT_SUCCESS);
}
