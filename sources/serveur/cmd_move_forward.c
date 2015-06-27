/*
** cmd_move_forward.c for  in /home/bourma_m/Projet/SystemUnix/zappy/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Fri May  8 11:35:41 2015 Mathieu Bourmaud
** Last update Sat Jun 27 16:51:39 2015 Martin Porrès
*/

#include		"serveur.h"

int			cmd_move_forward(t_serv *serv, t_client *client, UNUSED char *cmd)
{
  if (client->orientation == NORTH || client->orientation == SOUTH)
    modify_x(client);
  else
    modify_y(client);
  if (write_player_pos(serv, client) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_write(client->fd, "ok") == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void			modify_x(t_client *client)
{
  if (client->orientation == NORTH)
    client->x -= 1;
  else
    client->x += 1;
}

void			modify_y(t_client *client)
{
  if (client->orientation == WEST)
    client->y -= 1;
  else
    client->y += 1;
}

int			write_player_pos(t_serv *serv, t_client *client)
{
  char			*msg;
  char			*id;
  char			*pos[2];
  char			*o;

  if ((id = itoa(client->id)) == NULL)
    return (EXIT_FAILURE);
  if ((pos[0] = itoa(client->x)) == NULL)
    return (EXIT_FAILURE);
  if ((pos[1] = itoa(client->y)) == NULL)
    return (EXIT_FAILURE);
  if ((o = itoa(client->orientation)) == NULL)
    return (EXIT_FAILURE);
  if ((msg = malloc(strlen(id) + strlen(pos[0]) + strlen(pos[1]) + 9)) == NULL)
    return (my_error(ERR_MALLOC));
  if (write_player_pos_end(msg, id, pos, o) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_to_gfx(serv->gfx, msg) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(msg);
  free(id);
  free(pos[0]);
  free(pos[1]);
  free(o);
  return (EXIT_SUCCESS);
}

int			write_player_pos_end(char *msg, char *id, char *pos[2], char *o)
{
  if ((msg = strcpy(msg, "ppo ")) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, id, 4)) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, " ", 4 + strlen(id))) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, pos[0], 5 + strlen(id))) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, " ", 5 + strlen(id) + strlen(pos[0]))) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, pos[1], 6 + strlen(id) + strlen(pos[0]))) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, " ", 6 + strlen(id) + strlen(pos[0]) + strlen(pos[1]))) == NULL)
    return (my_error(ERR_STRCPY));
  if ((msg = strncpy(msg, o, 7 + strlen(id) + strlen(pos[0]) + strlen(pos[1]))) == NULL)
    return (my_error(ERR_STRCPY));
  return (EXIT_SUCCESS);
}
