/*
** cmdList.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jun 28 01:18:18 2015 Jordan Chazottes
** Last update Sun Jun 28 21:27:14 2015 Jordan Chazottes
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
      s->map->blocks[x][y].items[i] = atoi(tok);
      ++i;
      tok = strtok(NULL, " ");
    }
  return (EXIT_SUCCESS);
}

int		cmd_tna(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  return (EXIT_SUCCESS);
}

int		setPlayerParam(t_player *new, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->id = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->y = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->ori = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->level = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->team = strdup(tok);
  return (EXIT_SUCCESS);
}

int		cmd_pnw(t_gfx *s, char *token)
{
  t_player	*new;
  t_player	*tmp;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (my_error(ERR_MALLOC));
  new->type = PLAYER;
  new->eId = -1;
  setPlayerParam(new, token);
  if (s->players == NULL)
    {
      s->players = new;
      return (EXIT_SUCCESS);
    }
  tmp = s->players;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  tmp = s->players;
  return (EXIT_SUCCESS);
}

int		cmd_ppo(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->y = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->ori = atoi(tok);
  return (EXIT_SUCCESS);
}

int		cmd_plv(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->level = atoi(tok);  
  return (EXIT_SUCCESS);
}

int		cmd_pin(t_gfx *s, char *token)
{
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  tmp->y = atoi(tok);
  id = 0;
  tok = strtok(NULL, " ");
  while (tok != NULL)
    {
      tmp->items[id++] = atoi(tok);
      tok = strtok(NULL, " ");
    }
  return (EXIT_SUCCESS);
}

int		cmd_pex(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Expulse\n");
  return (EXIT_SUCCESS);
}

int		cmd_pbc(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("broadcast\n");
  return (EXIT_SUCCESS);
}

int		cmd_pic(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Incantation start\n");
  return (EXIT_SUCCESS);
}

int		cmd_pie(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Incantation end\n");
  return (EXIT_SUCCESS);
}

int		cmd_pfk(t_gfx *s, char *token)
{
  (void)s;
  (void)token;

  printf("Oeuf pondu\n");
  return (EXIT_SUCCESS);
}

int		cmd_pdr(t_gfx *s, char *token)
{
  t_player	*tmp;
  char		*tok;
  int		id;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if (tmp->items[id] > 0)
    {
      s->map->blocks[tmp->x][tmp->y].items[id]++;
      tmp->items[id]--;
    }  
  return (EXIT_SUCCESS);
}

int		cmd_pgt(t_gfx *s, char *token)
{
  t_player	*tmp;
  char		*tok;
  int		id;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if (s->map->blocks[tmp->x][tmp->y].items[id] > 0)
    {
      s->map->blocks[tmp->x][tmp->y].items[id]--;
      tmp->items[id]++;
    }
  return (EXIT_SUCCESS);
}

int		cmd_pdi(t_gfx *s, char *token)
{
  t_player	*tmp;
  t_player	*tmp2;
  char		*tok;
  int		id;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  if ((tmp2 = getPrevPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp2->next = tmp->next;
  //free
  return (EXIT_SUCCESS);
}

int		setEggParam(t_player *new, char *token)
{
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->eId = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->id = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  new->y = atoi(tok);
  return (EXIT_SUCCESS);
}

int		cmd_enw(t_gfx *s, char *token)
{
  t_player	*new;
  t_player	*tmp;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (my_error(ERR_MALLOC));
  new->type = EGG;
  setEggParam(new, token);
  if (s->players == NULL)
    {
      s->players = new;
      return (EXIT_SUCCESS);
    }
  tmp = s->players;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  tmp = s->players;
  return (EXIT_SUCCESS);
}

int		cmd_eht(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("oeuf eclos\n");
  return (EXIT_SUCCESS);
}

int		cmd_ebo(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("joueur pour oeuf\n");
  return (EXIT_SUCCESS);
}

int		cmd_edi(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("oeuf mort de faim\n");
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
  printf("End game\n");
  return (EXIT_SUCCESS);
}

int		cmd_smg(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Message reçu\n");
  return (EXIT_SUCCESS);
}

int		cmd_suc(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Commande inconnue\n");
  return (EXIT_SUCCESS);
}

int		cmd_sbp(t_gfx *s, char *token)
{
  (void) s;
  (void) token;
  printf("Bad param\n");
  return (EXIT_SUCCESS);
}
