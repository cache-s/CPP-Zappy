/*
** gfx.h for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:44:33 2015 Jordan Chazottes
** Last update Sun Jun 28 10:49:26 2015 Jordan Chazottes
*/

#ifndef		_GFX_H_
# define	_GFX_H_

# include	<stdio.h>

/* INCLUDE */
/* SDL */
# include	<SDL/SDL.h>
# include	<SDL/SDL_image.h>

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
# define                BUFF_SIZE       8
# define		WELCOME		"BIENVENUE\n"
# define		GRAPHIC		"GRAPHIC\n"
# define		NB_CMDS		24

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

typedef struct		s_player
{
  int			posX;
  int			posY;
  struct s_player	*next;
  struct s_player	*prev;
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

typedef struct		s_gfx
{
  int			width;
  int			height;
  int			time;
  SDL_Surface*		screen;
  t_network		network;
  t_map			*map;

  char			**cmdTab;
  tabFcts		cmds[NB_CMDS];
}			t_gfx;

int		main(int ac, char** av);
int		usage(void);
int		coreGFX(char *ip, int port);
void		initStruct(t_gfx* s);
void		initWindow(t_gfx* s);
int		initNetwork(t_gfx* s, char *ip, int port);
int		eventHandler();
char		*client_read();
char		*client_write();

int             my_write(int fd, char *str);
/* char		*client_read(); */
/* char		*client_write(); */
/* int		create_client(t_gfx*, int); */
/* int		welcome_msg(int); */
int		server_read(t_gfx *s);
int		gfx_loop(t_gfx *s);
int		save_srv_cmd(t_gfx *s, char *buffer);
int		handleCmd(t_gfx *s);
int		initConnection(t_gfx *s);
int		initMap(t_gfx *s, char *str, char *token, char *end_str);
void		initFctTab(t_gfx *s);
int		initCmdTab(t_gfx *s);
int		allocMap(t_gfx *s);
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
#endif

