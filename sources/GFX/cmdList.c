/*
** cmdList.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jun 28 01:18:18 2015 Jordan Chazottes
** Last update Sun Jun 28 12:06:28 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		cmd_msz(t_gfx *s, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  s->width = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  s->height = atoi(tok);
  if (allocMap(s) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cmd_bct(t_gfx *s, char *token)
{
  char		*tok;
  int		x;
  int		y;
  int		i;

  i = 0;
  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  y = atoi(tok);
  s->map->blocks[x][y].x = x;
  s->map->blocks[x][y].y = y;
  tok = strtok(NULL, " ");
  while (tok != NULL)
    {
      /* if ((tok = strtok(NULL, " ")) == NULL) */
      /* 	return (EXIT_FAILURE);	 */
      s->map->blocks[x][y].items[i] = atoi(tok);
      ++i;
      tok = strtok(NULL, " ");
    }
  /* printf("Case %d %d items = ", x, y); */
  /* i = 0; */
  /* while (i < 8) */
  /*   { */
  /*     printf("%d \n", s->map->blocks[x][y].items[i++]); */
  /*   } */
  return (EXIT_SUCCESS);
}

int		cmd_tna(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Tna\n");
  return (EXIT_SUCCESS);
}

int		cmd_pnw(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Pnw\n");
  return (EXIT_SUCCESS);
}

int		cmd_ppo(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Ppo\n");
  return (EXIT_SUCCESS);
}

int		cmd_plv(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("plv\n");
  return (EXIT_SUCCESS);
}

int		cmd_pin(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pin\n");
  return (EXIT_SUCCESS);
}

int		cmd_pex(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pex\n");
  return (EXIT_SUCCESS);
}

int		cmd_pbc(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pbc\n");
  return (EXIT_SUCCESS);
}

int		cmd_pic(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pic\n");
  return (EXIT_SUCCESS);
}

int		cmd_pie(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pie\n");
  return (EXIT_SUCCESS);
}

int		cmd_pfk(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pfk\n");
  return (EXIT_SUCCESS);
}

int		cmd_pdr(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pdr\n");
  return (EXIT_SUCCESS);
}

int		cmd_pgt(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pgt\n");
  return (EXIT_SUCCESS);
}

int		cmd_pdi(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("pdi\n");
  return (EXIT_SUCCESS);
}

int		cmd_enw(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Enw\n");
  return (EXIT_SUCCESS);
}

int		cmd_eht(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("eht\n");
  return (EXIT_SUCCESS);
}

int		cmd_ebo(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("ebo\n");
  return (EXIT_SUCCESS);
}

int		cmd_edi(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("edi\n");
  return (EXIT_SUCCESS);
}

int		cmd_sgt(t_gfx *s, char *token)
{
  char		*tok;

  tok = strtok(token, " ");
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  s->time = atoi(tok);  
  return (EXIT_SUCCESS);
}

int		cmd_seg(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("seg\n");
  return (EXIT_SUCCESS);
}

int		cmd_smg(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("smg\n");
  return (EXIT_SUCCESS);
}

int		cmd_suc(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("suc\n");
  return (EXIT_SUCCESS);
}

int		cmd_sbp(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("sbp\n");
  return (EXIT_SUCCESS);
}
