/*
** main.c for  in /home/bourma_m/Projet/SystemUnix/PSU_2014_myftp/sources/serveur
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Mar  9 09:42:17 2015 Mathieu Bourmaud
** Last update Tue Jun 23 17:06:21 2015 Martin Porrès
*/

#include	"serveur.h"
#include	<ncurses.h>
#include	<term.h>
#include	<termios.h>

void			init_term()
{
  char			*name_term;
  struct termios	curse;

  if ((name_term = getenv("TERM")) == NULL)
    exit(EXIT_FAILURE);
  if (tgetent(NULL, name_term) == ERR)
    exit(EXIT_FAILURE);
  if (tcgetattr(0, &curse) == -1)
    exit(EXIT_FAILURE);
  curse.c_lflag &= ~(ECHO);
  curse.c_cc[VMIN] = 1;
  curse.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, &curse) == -1)
    exit(EXIT_FAILURE);
}

void			end_term()
{
  struct termios	curse;

  if (tcgetattr(0, &curse) == -1)
    exit(EXIT_FAILURE);
  curse.c_lflag = (ECHO);
  if (tcsetattr(0, 0, &curse) == -1)
    exit(EXIT_FAILURE);
}

void			handle_ctrl_c(int sig)
{
  char			c;

  signal(sig, SIG_IGN);
  puts(BOLD RED "Do you want to quit ? [Y/N]" END);
  c = getchar();
  if (c == 'Y' || c == 'y')
    exit(0);
}

void		display_game_configuration(t_serv *serv)
{
  char		*str;
  char		*tmp;

  tmp = strdup(serv->settings->teams);
  puts(BOLD BLUE ERR_USAGE_SRV END);
  printf(BOLD GREEN "\nListening on port %d...\nConfiguration : Max(%d) WorldX(%d)\
 WorldY(%d) T(%d)\nTeams :\n" END,serv->settings->port,
	 serv->settings->nb_clients,
	 serv->settings->width, serv->settings->height, serv->settings->delay);
  str = NULL;
  str = strtok(tmp, ";");
  while (str != NULL)
    {
      printf(BOLD GREEN "\tName(%s) Max(%d)\n" END, str, serv->settings->nb_clients);
      str = strtok(NULL, ";"); 
    }
  free(str);
  free(tmp);
  puts(BOLD GREEN "Generating world...done" END);
}

int		main(UNUSED int ac, char **av)
{
  t_serv	serv;

  av[ac + 1] = NULL;
  srand(time(NULL));
  init_term();
  signal(SIGINT, handle_ctrl_c);
  end_term();
  if ((serv.settings = parse_args(av)) == NULL)
    return (my_error(ERR_USAGE_SRV));
  if (map_generation(&serv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (init_server(&serv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
