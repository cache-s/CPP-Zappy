/*
** save_srv_cmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 25 18:39:48 2015 Jordan Chazottes
** Last update Thu Jun 25 18:41:47 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		save_srv_cmd(t_gfx *s, char *buffer)
{
  if (s->network.cmd == NULL)
    {
      if ((s->network.cmd = strdup(buffer)) == NULL)
	return (my_error(ERR_STRDUP));
    }
  else
    {
      if ((s->network.cmd = realloc(s->network.cmd, strlen(s->network.cmd)
				    + strlen(buffer) + 1)) == NULL)
	return (my_error(ERR_REALLOC));
      if ((s->network.cmd = strcat(s->network.cmd, buffer)) == NULL)
	return (my_error(ERR_STRCAT));
    }
  return (EXIT_SUCCESS);
}
