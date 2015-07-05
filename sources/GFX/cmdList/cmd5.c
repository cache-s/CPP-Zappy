/*
** cmd5.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy/sources/GFX
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jul  5 19:22:25 2015 Jordan Chazottes
** Last update Sun Jul  5 19:50:55 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		cmd_seg(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_smg(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_suc(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_sbp(t_gfx *s, char *token)
{
  (void)	s;
  (void)	token;
  return (EXIT_SUCCESS);
}

int		cmd_pdi2(t_gfx *s, int id)
{
  t_player	*tmp;

  tmp = getPlayer(s, id);
  if (tmp->next == NULL)
    tmp = NULL;
  return (EXIT_SUCCESS);
}
