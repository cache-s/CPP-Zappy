/*
** gfx.h for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:44:33 2015 Jordan Chazottes
** Last update Tue Jun 23 19:30:55 2015 Jordan Chazottes
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
# include	<netdb.h>
/* /NETWORK/ */

# include	"commons_fcts.h"

/* /INCLUDE/ */

# define		MAX_FD		1000
typedef			char*(*fct)();
/* STRUCT */

/* NETWORK */

typedef struct		s_network
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  struct sockaddr_in	sin_client;
  int			socket;
  fd_set		readfd;
  fd_set		writefd;
}			t_network;

typedef struct		s_server
{
  int			fd;
  fct			fct_read;
  fct			fct_write;
  char			need_write;
}			t_server;

/* DISPLAY*/

typedef struct		s_ressources
{
  int			no;
  int			li;
  int			de;
  int			si;
  int			me;
  int			ph;
  int			th;
}			t_ressources;

typedef struct		s_player
{
  int			posX;
  int			posY;
  struct s_player	*next;
  struct s_player	*prev;
}			t_player; 

typedef struct		s_map
{
  t_ressources		resList;
}			t_map;

typedef struct		s_gfx
{
  SDL_Surface*		screen;
  int			width;
  int			height;
  t_network		network;
  t_server		*server;
}			t_gfx;

int		main(int ac, char** av);
int		usage(void);
void		coreGFX(void);
void		initStruct(t_gfx* s);
void		initWindow(t_gfx* s);
int		initNetwork(t_gfx* s);
int		eventHandler();
char		*client_read();
char		*client_write();

int             my_write(int fd, char *str);
char		*client_read();
char		*client_write();
int		create_client(t_gfx*, int);
int		welcome_msg(int);

#endif
