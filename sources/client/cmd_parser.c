/*
** cmd_parser.c for  in /home/poupon_d/Rendu/PSU_2014_zappy/sources/client
** 
** Made by poupon_d
** Login   <poupon_d@epitech.net>
** 
** Started on  Wed Jun 17 16:06:12 2015 poupon_d
** Last update Wed Jun 17 16:06:12 2015 poupon_d
*/

#include			"client.h"

void				assign_tab_name(t_client *client)
{
  client->name_fnc[AVANCE] = strdup("avance");
  client->name_fnc[DROITE] = strdup("droite");
  client->name_fnc[GAUCHE] = strdup("gauche");
  client->name_fnc[VOIR] = strdup("voir");
  client->name_fnc[INVENTAIRE] = strdup("inventaire");
  client->name_fnc[PREND] = strdup("prend");
  client->name_fnc[POSE] = strdup("pose");
  client->name_fnc[EXPULSE] = strdup("expulse");
  client->name_fnc[BROADCAST] = strdup("broadcast");
  client->name_fnc[INCANTATION] = strdup("incantation");
  client->name_fnc[FORK] = strdup("fork");
  client->name_fnc[CONNECT_NBR] = strdup("connect_nbr");
}

void				assign_tab_cmd(t_client *client)
{
  client->cmd[AVANCE] = &cmd_avance;
  client->cmd[DROITE] = &cmd_droite;
  client->cmd[GAUCHE] = &cmd_gauche;
  client->cmd[VOIR] = &cmd_voir;
  client->cmd[INVENTAIRE] = &cmd_inventaire;
  client->cmd[PREND] = &cmd_prend;
  client->cmd[POSE] = &cmd_pose;
  client->cmd[EXPULSE] = &cmd_expulse;
  client->cmd[BROADCAST] = &cmd_broadcast;
  client->cmd[INCANTATION] = &cmd_incantation;
  client->cmd[FORK] = &cmd_fork;
  client->cmd[CONNECT_NBR] = &cmd_connect_nbr;
}

void				cmd_parser(t_client *client, char *command)
{
  int           i;

  printf("Cmd = %s\n", command);
  assign_tab_name(client);
  assign_tab_cmd(client);
  i = 0;
  while (i != NB_CMD)
    {
      if (strcmp(client->name_fnc[i], command) == 0)
	client->cmd[i](client);
      i++;
    }
}
