/*
** map_generation.c for  in /home/mathieu/rendu/PSU_2014_zappy
** 
** Made by Mathieu
** Login   <mathieu@epitech.net>
** 
** Started on  Wed Jun 24 18:40:00 2015 Mathieu
** Last update Thu Jul  2 18:11:28 2015 Martin Porrès
*/

#include		"serveur.h"

int			map_generation(t_serv *serv)
{
  int			i;
  int			j;
  
  i = 0;
  if ((serv->map = (t_map *)malloc(sizeof(t_map *))) == NULL)
    return (my_error(ERR_MALLOC));
  if ((serv->map->blocks = malloc(serv->settings->height * sizeof(t_block *))) == NULL)
    return (my_error(ERR_MALLOC));
  while (i < serv->settings->height)
    {
      if ((serv->map->blocks[i] = malloc(serv->settings->width * sizeof(t_block))) == NULL)
	return (my_error(ERR_MALLOC));
      i++;
    }
  j = 0;
  while (j < serv->settings->width)
    {
      i = 0;
      while (i < serv->settings->height)
	{
	  jewels_food_generation(&(serv->map->blocks[i][j]), i, j);
	  ++i;
	}
      ++j;
    }
  return (EXIT_SUCCESS);
}

int			jewels_food_generation(t_block *block, int i, int j)
{
  int			k;

  k = 0;
  k++;
  while (k < 7)
    {
      block->items[k] = 0;
      k++;
    }
  block->x = i;
  block->y = j;
  if (rand() % 10 <= 4)
    {
      block->items[rand() % 7] += 1;
      block->items[rand() % 7] += 1;
      block->items[rand() % 7] += 1;
      if (rand() % 1 == 1)
      	block->items[0] += 1;
    }
  return (EXIT_SUCCESS);
}

int			generate_random_item(t_serv *serv, int item, int nb)
{
  int			x;
  int			y;
  int			i;

  i = 0;
  while (i < nb)
    {
      x = rand() % serv->settings->width;
      y = rand() % serv->settings->height;
      serv->map->blocks[x][y].items[item] += 1;
      if (write_bct_gfx(serv->gfx, &(serv->map->blocks[x][y])) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}

int			generate_all_item(t_serv *serv, int nb)
{
  int			i;
  int			ret;

  ret = EXIT_SUCCESS;
  i = 0;
  while (i < 7)
    if (generate_random_item(serv, i++, nb) == EXIT_FAILURE)
      ret = EXIT_FAILURE;
  return (ret);
}
