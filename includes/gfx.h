/*
** gfx.h for zappy in /home/chazot_a/rendu/PSU_2014_zappy
** 
** Made by Jordan Chazottes
** Login   <chazot_a@epitech.net>
** 
** Started on  Tue Jun 16 13:44:33 2015 Jordan Chazottes
** Last update Tue Jun 16 14:49:41 2015 Jordan Chazottes
*/

#ifndef		_GFX_H_
# define	_GFX_H_

# include	<stdio.h>

/* INCLUDE SDL */
# include	<SDL/SDL.h>
# include	<SDL/SDL_image.h>

/* STRUCT */

typedef struct	s_gfx
{
  SDL_Surface*	screen;
  int		width;
  int		height;
}		t_gfx;

int		main(int ac, char** av);
int		usage(void);
void		coreGFX(void);
void		initStruct(t_gfx* s);
int		eventHandler();

#endif
