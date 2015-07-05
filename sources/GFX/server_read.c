/*
** server_read.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Thu Jun 25 18:38:38 2015 Jordan Chazottes
** Last update Sun Jul  5 17:32:07 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		server_read(t_gfx *s)
{
  char		*buffer;
  int		ret;

  if ((buffer =  malloc(BUFF_SIZE)) == NULL)
    return (my_error(ERR_MALLOC));
  bzero(buffer, BUFF_SIZE);
  if ((ret = read(s->network.socket, buffer, BUFF_SIZE - 1)) <= 0)
    return (EXIT_FAILURE);
  if (save_srv_cmd(s, buffer) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(buffer);
  if (ret == BUFF_SIZE - 1)
    s->network.entire_cmd = 0;
  else
    {
      printf("%s\n", s->network.cmd);
      s->network.entire_cmd = 1;
    }
  return (EXIT_SUCCESS);
}
