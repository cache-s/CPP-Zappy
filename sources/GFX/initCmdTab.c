/*
** initCmdTab.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sat Jun 27 19:07:21 2015 Jordan Chazottes
** Last update Fri Jul  3 22:26:52 2015 Jordan Chazottes
*/

#include	"gfx.h"

void		initFctTab(t_gfx *s)
{
  s->cmds[0] = &cmd_msz;
  s->cmds[1] = &cmd_bct;
  s->cmds[2] = &cmd_tna;
  s->cmds[3] = &cmd_pnw;
  s->cmds[4] = &cmd_ppo;
  s->cmds[5] = &cmd_plv;
  s->cmds[6] = &cmd_pin;
  s->cmds[7] = &cmd_pex;
  s->cmds[8] = &cmd_pbc;
  s->cmds[9] = &cmd_pic;
  s->cmds[10] = &cmd_pie;
  s->cmds[11] = &cmd_pfk;
  s->cmds[12] = &cmd_pdr;
  s->cmds[13] = &cmd_pgt;
  s->cmds[14] = &cmd_pdi;
  s->cmds[15] = &cmd_enw;
  s->cmds[16] = &cmd_eht;
  s->cmds[17] = &cmd_ebo;
  s->cmds[18] = &cmd_edi;
  s->cmds[19] = &cmd_sgt;
  s->cmds[20] = &cmd_seg;
  s->cmds[21] = &cmd_smg;
  s->cmds[22] = &cmd_suc;
  s->cmds[23] = &cmd_sbp;
}

void		initDrawTab(t_gfx *s)
{
  s->drawItem[0] = &draw_food;
  s->drawItem[1] = &draw_linemate;
  s->drawItem[2] = &draw_deraumere;
  s->drawItem[3] = &draw_sibur;
  s->drawItem[4] = &draw_mendiane;
  s->drawItem[5] = &draw_phiras;
  s->drawItem[6] = &draw_thystame;
  s->drawPlayer[0] = &draw_p1;
  s->drawPlayer[1] = &draw_p2;
  s->drawPlayer[2] = &draw_p3;
  s->drawPlayer[3] = &draw_p4;
  s->drawPlayer[4] = &draw_p5;
  s->drawPlayer[5] = &draw_p6;
  s->drawPlayer[6] = &draw_p7;
  s->drawPlayer[7] = &draw_p8;
  s->drawAction[STAND] = &drawStand;
  s->drawAction[BROADCAST] = &drawBroadcast;
}

int		initCmdTab(t_gfx *s)
{
  if ((s->cmdTab = malloc(sizeof(char *) * NB_CMDS)) == NULL)
    return (my_error(ERR_MALLOC));
  s->cmdTab[0] = strdup("msz");
  s->cmdTab[1] = strdup("bct");
  s->cmdTab[2] = strdup("tna");
  s->cmdTab[3] = strdup("pnw");
  s->cmdTab[4] = strdup("ppo");
  s->cmdTab[5] = strdup("plv");
  s->cmdTab[6] = strdup("pin");
  s->cmdTab[7] = strdup("pex");
  s->cmdTab[8] = strdup("pbc");
  s->cmdTab[9] = strdup("pic");
  s->cmdTab[10] = strdup("pie");
  s->cmdTab[11] = strdup("pfk");
  s->cmdTab[12] = strdup("pdr");
  s->cmdTab[13] = strdup("pgt");
  s->cmdTab[14] = strdup("pdi");
  s->cmdTab[15] = strdup("enw");
  s->cmdTab[16] = strdup("eht");
  s->cmdTab[17] = strdup("ebo");
  s->cmdTab[18] = strdup("edi");
  s->cmdTab[19] = strdup("sgt");
  s->cmdTab[20] = strdup("seg");
  s->cmdTab[21] = strdup("smg");
  s->cmdTab[22] = strdup("suc");
  s->cmdTab[23] = strdup("sbp");
  s->cmdTab[24] = NULL;
  return (EXIT_SUCCESS);
}

