/*
** timer.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Tue Jun 30 11:33:39 2015 Mathieu
** Last update Tue Jun 30 11:33:39 2015 Mathieu
*/

#include	"serveur.h"

void		get_elapsed_time(t_serv *serv)
{
  serv->timer.elapsed = serv->timer.start - serv->timer.end;
}
