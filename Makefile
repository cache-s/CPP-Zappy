##
## Makefile for  in /home/bourma_m/Projet/SystemUnix/zappy
## 
## Made by Mathieu Bourmaud
## Login   <bourma_m@epitech.net>
## 
## Started on  Thu May  7 14:17:43 2015 Mathieu Bourmaud
## Last update Tue Jun 16 18:54:09 2015 Martin Porrès
##

NAME_SERVEUR	=	server

NAME_CLIENT	=	client

CC		=	gcc

RM		=	rm -f

CFLAGS		+=	-g -W -Wall -Wextra -Werror -pedantic
CFLAGS		+=	-I./includes

SRCS_SERVEUR	=	sources/serveur/main.c			\
			sources/serveur/init_serv.c		\
			sources/serveur/init_tabs.c		\
			sources/serveur/checkfds.c		\
			sources/serveur/read_write.c		\
			sources/serveur/call_cmds.c		\
			sources/serveur/welcome_msg.c		\
			sources/serveur/cmd_move_forward.c	\
			sources/serveur/cmd_right.c		\
			sources/serveur/cmd_left.c		\
			sources/serveur/cmd_see.c		\
			sources/serveur/cmd_inventory.c		\
			sources/serveur/cmd_take.c		\
			sources/serveur/cmd_drop.c		\
			sources/serveur/cmd_kick.c		\
			sources/serveur/cmd_broadcast.c		\
			sources/serveur/cmd_incantation.c	\
			sources/serveur/cmd_fork.c		\
			sources/serveur/cmd_connect_nbr.c	\
			$(SRCS_COMMONS)

SRCS_CLIENT	=	sources/client/main.c		\
			sources/client/parsing.c	\
			sources/client/parsing_fct.c	\
			sources/client/zappy.c		\
			$(SRCS_COMMONS)

SRCS_COMMONS	=	sources/misc/errors.c		\
			sources/misc/my_regex.c		\
			sources/misc/rm_spaces.c	\
			sources/misc/count_char.c	\
			sources/misc/my_write.c		\

OBJS_SERVEUR	=	$(SRCS_SERVEUR:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

all		:	$(NAME_SERVEUR) $(NAME_CLIENT)

$(NAME_SERVEUR)	:	$(OBJS_SERVEUR)
			$(CC) $(OBJS_SERVEUR) -o $(NAME_SERVEUR)

$(NAME_CLIENT)	:	$(OBJS_CLIENT)
			$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean		:
			$(RM) $(OBJS_SERVEUR)
			$(RM) $(OBJS_CLIENT)

fclean		:	clean
			$(RM) $(NAME_SERVEUR)
			$(RM) $(NAME_CLIENT)

re		:	fclean all
