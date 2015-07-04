/*
** cmdList.c for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Sun Jun 28 01:18:18 2015 Jordan Chazottes
** Last update Sat Jul  4 19:06:56 2015 Jordan Chazottes
*/

#include	"gfx.h"

int		getOri(eOrientation ori)
{
  if (ori == NORTH)
    return (162);
  if (ori == EAST)
    return (0);
  if (ori == SOUTH)
    return (74);
  return (250);

}

int		getAct(eAction act)
{
  if (act == STAND)
    return (0);
  if (act == BROADCAST)
    return (1);
  if (act == INCANTATION)
    return (2);
  if (act == FORK)
    return (3);
  if (act == CROUCH)
    return (4);
  if (act == DIE)
    return (5);
  return (0);
}

int		drawDie(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Rect	rect;

  rect.x = 535;
  rect.y = getOri(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		drawCrouch(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Rect	rect;

  rect.x = 500;
  rect.y = getOri(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		drawFork(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Surface	*fImg;
  SDL_Rect	rect;

  if ((fImg = SDL_LoadBMP("assets/sprites/fork.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(fImg, SDL_SRCCOLORKEY, SDL_MapRGB(fImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  SDL_SetAlpha(fImg, SDL_SRCALPHA, 128);
  rect.x = 35;
  rect.y = getOri(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  rect.x = rect.y = 0;
  rect.w = rect.h = 100;
  pos.x -= 35;
  pos.y -= 10;
  applySurface(pos, s, fImg, &rect);
  return (EXIT_SUCCESS);
}

int		drawIncant(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Surface	*iImg;
  SDL_Rect	rect;

  if ((iImg = SDL_LoadBMP("assets/sprites/crystals.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(iImg, SDL_SRCCOLORKEY, SDL_MapRGB(iImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  rect.x = 35;
  rect.y = getOri(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  rect.x = 53 * (p->level - 1);
  rect.y = 0;
  rect.w = 53;
  rect.h = 87;
  pos.y -= 30;
  applySurface(pos, s, iImg, &rect);
  return (EXIT_SUCCESS);
}

int		drawStand(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Rect	rect;

  rect.x = 35;
  rect.y = getOri(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		drawBroadcast(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p)
{
  SDL_Rect	rect;
  SDL_Surface	*bImg;

  if ((bImg = SDL_LoadBMP("assets/sprites/broadcast.bmp")) == NULL)
    return (EXIT_FAILURE);
  if (SDL_SetColorKey(bImg, SDL_SRCCOLORKEY, SDL_MapRGB(bImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  rect.x = 35;
  rect.y = getOri(p->ori);
  rect.w = 34;
  rect.h = 66;
  applySurface(pos, s, img, &rect);
  rect.x = rect.y = 0;
  rect.w = rect.h = 48;
  pos.y -= 20;
  applySurface(pos, s, bImg, &rect);
  return (EXIT_SUCCESS);
}

int		draw_p1(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset1.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[getAct(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p2(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset2.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[getAct(p->act)](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p3(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset3.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[p->act](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p4(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset4.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[p->act](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p5(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset5.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[p->act](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p6(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset6.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[p->act](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p7(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset7.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[p->act](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_p8(t_gfx *s, t_pos pos, t_player *p)
{
  SDL_Surface	*pImg;

  if ((pImg = SDL_LoadBMP("assets/sprites/mage_charset8.bmp")) == NULL)
    return (my_error(ERR_LOAD));
  if (SDL_SetColorKey(pImg, SDL_SRCCOLORKEY, SDL_MapRGB(pImg->format, 0, 0, 255)) != 0)
    return (EXIT_FAILURE);
  s->drawAction[p->act](s, pos, pImg, p);
  SDL_FreeSurface(pImg);
  return (EXIT_SUCCESS);
}

int		draw_food(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 0;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = pos.i*64 - (s->xScroll - SCR_WIDTH);
  pos.y = pos.j*64 - (s->yScroll - SCR_HEIGHT) + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_linemate(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 16;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i*64) + 16;
  pos.y = pos.j*64 + 50;
  applySurface(pos, s, img, &rect);  
  return (EXIT_SUCCESS);
}

int		draw_deraumere(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 32;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i*64) + 32;
  pos.y = pos.j*64 + 50;
  applySurface(pos, s, img, &rect);  
  return (EXIT_SUCCESS);
}

int		draw_sibur(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 48;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i*64) + 48;
  pos.y = pos.j*64 + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_mendiane(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 64;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = pos.i*64;
  pos.y = (pos.j*64) + 16 + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_phiras(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 80;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i*64) + 16;
  pos.y = (pos.j*64) + 16 + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

int		draw_thystame(t_gfx *s, SDL_Surface *img, t_pos pos)
{
  SDL_Rect	rect;

  rect.x = 96;
  rect.y = 0;
  rect.w = 16;
  rect.h = 16;
  pos.x = (pos.i*64) + 32;
  pos.y = (pos.j*64) + 16 + 50;
  applySurface(pos, s, img, &rect);
  return (EXIT_SUCCESS);
}

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
  t_pos		pos;
  int		i;

  i = -1;
  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  pos.x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  pos.y = atoi(tok);
  s->map->blocks[pos.x][pos.y].x = pos.x;
  s->map->blocks[pos.x][pos.y].y = pos.y;
  tok = strtok(NULL, " ");
  while (tok != NULL)
    {
      s->map->blocks[pos.x][pos.y].items[++i] = atoi(tok);
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
  new->act = STAND;
  new->next = NULL;
  setPlayerParam(new, token);
  if (s->players == NULL)
    {
      new->isFirst = 1;
      s->players = new;
      return (EXIT_SUCCESS);
    }
  new->isFirst = 0;
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
  tmp->act = STAND;
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
  tmp->act = BROADCAST;
  return (EXIT_SUCCESS);
}

int		cmd_pic(t_gfx *s, char *token)
{
  int           id;
  t_player      *tmp;
  char          *tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = INCANTATION;
  return (EXIT_SUCCESS);
}

int		cmd_pie(t_gfx *s, char *token)
{
  t_player      *tmp;
  t_pos		pos;
  char          *tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  pos.x = atoi(tok);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  pos.y = atoi(tok);
  tmp = s->players;
  while (tmp != NULL)
    {
      if (tmp->x == pos.x && tmp->y == pos.y && tmp->act == INCANTATION)
	tmp->act = STAND;
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);

}

int		cmd_pfk(t_gfx *s, char *token)
{
  int           id;
  t_player      *tmp;
  char          *tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = FORK;
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
  tmp->act = CROUCH;
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
  tmp = getPlayer(s, id);
  if (tmp->isFirst == 1)
    {
      if (tmp->next == NULL)
	{
	  free(tmp);
	  s->players = NULL;
	}
      else
	{
	  s->players = tmp->next;
	  s->players->isFirst = 1;
	}
      return (EXIT_SUCCESS);
    }
  if (tmp->next == NULL)
    tmp = NULL;
  tmp2 = getPrevPlayer(s, id);
  tmp2->next = tmp->next;
  free(tmp);
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
  int		id;
  t_player	*tmp;
  char		*tok;

  if ((tok = strtok(token, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  if ((tok = strtok(NULL, " ")) == NULL)
    return (EXIT_FAILURE);
  id = atoi(tok);
  if ((tmp = getPlayer(s, id)) == NULL)
    return (EXIT_FAILURE);
  tmp->act = STAND;
 /* t_player	*new; */
  /* t_player	*tmp; */

  /* if ((new = malloc(sizeof(t_player))) == NULL) */
  /*   return (my_error(ERR_MALLOC)); */
  /* new->type = EGG; */
  /* setEggParam(new, token); */
  /* if (s->players == NULL) */
  /*   { */
  /*     s->players = new; */
  /*     return (EXIT_SUCCESS); */
  /*   } */
  /* tmp = s->players; */
  /* while (tmp->next != NULL) */
  /*   tmp = tmp->next; */
  /* tmp->next = new; */
  /* tmp = s->players; */
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
