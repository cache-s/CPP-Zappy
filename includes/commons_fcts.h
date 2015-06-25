/*
** commons_fcts.h for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp/includes
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 15:20:23 2015 Mathieu Bourmaud
** Last update Tue Jun 16 13:04:17 2015 Sebastien Cache-Delanos
*/

#ifndef			_COMMONS_FCTS_H_
#define			_COMMONS_FCTS_H_

#include		"errors.h"

char			*itoa(int val);
int			my_regex(const char *val, const char *good);
void			rm_spaces(char *src);

#endif
