/*
** gfx.h for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:44:33 2015 Jordan Chazottes
** Last update Sun Jul  5 19:58:36 2015 Jordan Chazottes
*/

#ifndef		_GFX_H_
# define	_GFX_H_

# include	<stdio.h>

/* INCLUDE */
/* SDL */
# include	<SDL/SDL.h>
# include	<SDL/SDL_image.h>
# include	<SDL/SDL_ttf.h>

/* /SDL/ */

/* NETWORK */
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<netinet/ip.h>
# include	<arpa/inet.h>
# include	<netdb.h>
/* /NETWORK/ */

# include	"commons_fcts.h"

/* /INCLUDE/ */

# define		MAX_FD		1000
# define                BUFF_SIZE       50
# define		WELCOME		"BIENVENUE\n"
# define		GRAPHIC		"GRAPHIC\n"
# define		NB_CMDS		25
# define		SPR_RES		8
# define		NB_ITEMS	7
# define		NB_LEVELS	8
# define		MAX_VIEW	10
# define		SCR_WIDTH	640
# define		SCR_HEIGHT	640
# define		NB_ACTIONS	6

typedef			int(*tabFcts)();
/* STRUCT */

/* NETWORK */

typedef struct		s_network
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;
  int			socket;
  char			entire_cmd;
  char			*cmd;
  fd_set		fd_read;
  fd_set		fd_write;
  char			init;
}			t_network;

/* DISPLAY*/
typedef enum		eOrientation
  {
    NORTH	= 1,
    EAST	= 2,
    SOUTH	= 3,
    WEST	= 4
  }			eOrientation;

typedef enum		eEvent
  {
    QUIT	= -1,
    DEFAULT	= 0
  }			eEvent;

typedef enum		eAction
  {
    STAND	= 0,
    BROADCAST	= 1,
    INCANTATION = 2,
    FORK	= 3,
    CROUCH	= 4,
    DIE		= 5
  }			eAction;

typedef enum		eType
  {
    PLAYER	= 0,
    EGG		= 1
  }			eType;

typedef struct		s_player
{
  int			id;
  int			x;
  int			y;
  int			level;
  char			*team;
  char			isFirst;
  eOrientation		ori;
  eType			type;
  int			eId;
  int			items[8];
  eAction		act;
  struct s_player	*next;
}			t_player; 

typedef struct		s_block
{
  int			x;
  int			y;
  int			items[8];
}			t_block;

typedef struct		s_map
{
  t_block		**blocks;
}			t_map;

typedef struct		s_pos
{
  int			i;
  int			j;
  int			x;
  int			y;
}			t_pos;

typedef struct		s_gfx
{
  int			width;
  int			height;
  int			time;
  int			xScroll;
  int			yScroll;
  int			pSelect;
  t_pos			bSelect;
  SDL_Surface		*screen;
  TTF_Font		*font;
  t_network		network;
  t_map			*map;
  t_player		*players;
  char			**cmdTab;
  tabFcts		cmds[NB_CMDS];
  tabFcts		drawItem[NB_ITEMS];
  tabFcts		drawPlayer[NB_LEVELS];
  tabFcts		drawAction[NB_ACTIONS];
}			t_gfx;

int		main(int ac, char** av);
int		usage(void);
int		coreGFX(char *ip, int port);
void		initStruct(t_gfx* s);
int		initWindow(t_gfx* s);
int		initNetwork(t_gfx* s, char *ip, int port);
int		eventHandler(t_gfx *s);
char		*client_read();
char		*client_write();

int             my_write(int fd, char *str);
int		server_read(t_gfx *s);
int		gfx_loop(t_gfx *s);
int		save_srv_cmd(t_gfx *s, char *buffer);
int		handleCmd(t_gfx *s);
int		initMap(t_gfx *s, char *str, char *token, char *end_str);
void		initFctTab(t_gfx *s);
int		initCmdTab(t_gfx *s);
int		initCmdTab2(t_gfx *s);
void		initDrawTab(t_gfx *s);
int		allocMap(t_gfx *s);
int		getCmd(t_gfx *s, char *token);
int		welcomeServ(t_gfx *s);
int		setPlayerParam(t_player *new, char *token);
t_player	*getPlayer(t_gfx *s, int id);
t_player	*getPrevPlayer(t_gfx *s, int id);
int		draw(t_gfx *s);
int		initSprites(t_gfx *s);
void		applySurface(t_pos pos, t_gfx *s, SDL_Surface *src, SDL_Rect *clip);
void		freeStruct(t_gfx *s);
int		initFonts(t_gfx *s);
int		drawInventory(t_gfx *s);
int		fillInv(t_gfx *s, t_player *p);
int		writeText(t_gfx *s, char *msg, int x, int y);
int		drawInfos(t_gfx *s);
int		cmd_msz(t_gfx *s, char *token);
int		cmd_bct(t_gfx *s, char *token);
int		cmd_tna(t_gfx *s, char *token);
int		cmd_pnw(t_gfx *s, char *token);
int		cmd_ppo(t_gfx *s, char *token);
int		cmd_plv(t_gfx *s, char *token);
int		cmd_pin(t_gfx *s, char *token);
int		cmd_pex(t_gfx *s, char *token);
int		cmd_pbc(t_gfx *s, char *token);
int		cmd_pic(t_gfx *s, char *token);
int		cmd_pie(t_gfx *s, char *token);
int		cmd_pfk(t_gfx *s, char *token);
int		cmd_pdr(t_gfx *s, char *token);
int		cmd_pgt(t_gfx *s, char *token);
int		cmd_pdi(t_gfx *s, char *token);
int		cmd_enw(t_gfx *s, char *token);
int		cmd_eht(t_gfx *s, char *token);
int		cmd_ebo(t_gfx *s, char *token);
int		cmd_edi(t_gfx *s, char *token);
int		cmd_sgt(t_gfx *s, char *token);
int		cmd_seg(t_gfx *s, char *token);
int		cmd_smg(t_gfx *s, char *token);
int		cmd_suc(t_gfx *s, char *token);
int		cmd_sbp(t_gfx *s, char *token);
int		cmd_pdi2(t_gfx *s, int id);
int		draw_food(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_linemate(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_deraumere(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_sibur(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_mendiane(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_phiras(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_thystame(t_gfx *s, SDL_Surface *img, t_pos pos);
int		draw_p1(t_gfx *s, t_pos pos, t_player *p);
int		draw_p2(t_gfx *s, t_pos pos, t_player *p);
int		draw_p3(t_gfx *s, t_pos pos, t_player *p);
int		draw_p4(t_gfx *s, t_pos pos, t_player *p);
int		draw_p5(t_gfx *s, t_pos pos, t_player *p);
int		draw_p6(t_gfx *s, t_pos pos, t_player *p);
int		draw_p7(t_gfx *s, t_pos pos, t_player *p);
int		draw_p8(t_gfx *s, t_pos pos, t_player *p);
int		draw_stand(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p);
int		draw_broadcast(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p);
int		draw_incant(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p);
int		draw_fork(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p);
int		draw_crouch(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p);
int		draw_die(t_gfx *s, t_pos pos, SDL_Surface *img, t_player *p);
int		get_ori(eOrientation ori);
int		get_act(eAction act);

#endif

