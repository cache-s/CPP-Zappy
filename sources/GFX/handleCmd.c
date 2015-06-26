/*
** handleCmd.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Fri Jun 26 12:57:34 2015 Jordan Chazottes
** Last update Fri Jun 26 13:51:01 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		handleCmd(t_gfx *s)
{
  if (server_read(s) == EXIT_FAILURE)
    return (my_error(ERR_SERVER));
  if (s->network.entire_cmd == 1)
    if (s->network.init != 2)
      if (initConnection(s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
