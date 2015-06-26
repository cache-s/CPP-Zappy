/*
** init_tabs.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myirc
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sat Apr 11 19:09:27 2015 Mathieu Bourmaud
** Last update Fri May  8 11:53:02 2015 Mathieu Bourmaud
*/

#include		"serveur.h"

void			init_AI_cmds(t_serv *serv)
{
  serv->cmds[0] = cmd_move_forward;
  serv->cmds[1] = cmd_right;
  serv->cmds[2] = cmd_left;
  serv->cmds[3] = cmd_see;
  serv->cmds[4] = cmd_inventory;
  serv->cmds[5] = cmd_take;
  serv->cmds[6] = cmd_drop;
  serv->cmds[7] = cmd_kick;
  serv->cmds[8] = cmd_broadcast;
  serv->cmds[9] = cmd_incantation;
  serv->cmds[10] = cmd_fork;
  serv->cmds[11] = cmd_connect_nbr;
  serv->cmds[12] = cmd_graphic;
}

int			init_AI_tabs(t_serv *serv)
{
  if ((serv->AIFcts = malloc(sizeof(char *) * NB_CMDS + 1)) == NULL)
    return (my_error(ERR_MALLOC));
  serv->fds = serv->socket;
  serv->fct_read = server_read;
  serv->client = NULL;
  serv->AIFcts[0] = strdup("avance");
  serv->AIFcts[1] = strdup("droite");
  serv->AIFcts[2] = strdup("gauche");
  serv->AIFcts[3] = strdup("voir");
  serv->AIFcts[4] = strdup("inventaire");
  serv->AIFcts[5] = strdup("prend");
  serv->AIFcts[6] = strdup("pose");
  serv->AIFcts[7] = strdup("expulse");
  serv->AIFcts[8] = strdup("broadcast");
  serv->AIFcts[9] = strdup("incantation");
  serv->AIFcts[10] = strdup("fork");
  serv->AIFcts[11] = strdup("connect_nbr");
  serv->AIFcts[12] = strdup("GRAPHIC");
  init_AI_cmds(serv);
  return (EXIT_SUCCESS);
}
