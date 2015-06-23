##
## Makefile for  in /home/bourma_m/Projet/SystemUnix/zappy
## 
## Made by Mathieu Bourmaud
## Login   <bourma_m@epitech.net>
## 
## Started on  Thu May  7 14:17:43 2015 Mathieu Bourmaud
## Last update Tue Jun 23 17:05:21 2015 Martin Porrès
##

NAME_SERVEUR	=	server

NAME_CLIENT	=	client

NAME_GFX	=	gfx

CC		=	gcc

CXX		=	g++

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra -Werror -I./includes

CXXFLAGS	+=	 -std=c++11 -W -Wall -Wextra -Werror -I./includes

GFXFLAGS	+=	-lSDLmain -lSDL -lSDL_image

SRCS_SERVEUR	=	sources/serveur/main.c			\
			sources/serveur/parsing.c		\
			sources/serveur/fill_settings.c		\
			$(SRCS_COMMONS)

SRCS_CLIENT	=	sources/client/main.c		\
			sources/client/parsing.c	\
			sources/client/parsing_fct.c	\
			sources/client/connect.c	\
			$(SRCS_COMMONS)

SRCS_GFX	=	sources/GFX/main.c		\
			sources/GFX/usage.c		\
			sources/GFX/coreGFX.c		\
			sources/GFX/initStruct.c	\
			sources/GFX/eventHandler.c	\
			$(SRCS_COMMONS)

SRCS_COMMONS	=	sources/misc/errors.c		\
			sources/misc/my_regex.c		\
			sources/misc/rm_spaces.c	\
			sources/misc/count_char.c	\
			sources/misc/my_write.c		\

OBJS_SERVEUR	=	$(SRCS_SERVEUR:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

OBJS_GFX	=	$(SRCS_GFX:.c=.o)

GREEN		=	"\\033[1;32m"

NORMAL		=	"\\033[0;39m"

YELLOW		=	"\\033[1;33m"

all		:	$(NAME_SERVEUR) $(NAME_CLIENT) $(NAME_GFX)

$(NAME_SERVEUR)	:	$(OBJS_SERVEUR)
			@echo ' '
			@echo 'Building target: $@'
			@echo 'Invoking: GCC C Linker'
			$(CC) $(OBJS_SERVEUR) -o $(NAME_SERVEUR)
			@echo -n 'Finished building target:'
			@echo -e $(GREEN) '$@'
			@echo -e $(NORMAL) ' '

$(NAME_CLIENT)	:	$(OBJS_CLIENT)
			@echo ' '
			@echo 'Building target: $@'
			@echo 'Invoking: GCC C Linker'
			$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT)
			@echo -n 'Finished building target:'
			@echo -e $(GREEN) '$@'
			@echo -e $(NORMAL) ' '

$(NAME_GFX)	:	$(OBJS_GFX)
			@echo ' '
			@echo 'Building target: $@'
			@echo 'Invoking: GCC C Linker'
			$(CC) $(GFXFLAGS) $(OBJS_GFX) -o $(NAME_GFX)
			@echo -n 'Finished building target:'
			@echo -e $(GREEN) '$@'
			@echo -e $(NORMAL) ' '

%.o: %.c
			@echo ' '
			@echo 'Building file: $<'
			@echo 'Invoking: GCC C Compiler'
			$(CC) $(CFLAGS) -c -o $@ $<
			@echo -n 'Finished building: '
			@echo -e $(YELLOW) '$<'
			@echo -e $(NORMAL) ' '

%.o: %.cpp
			@echo ' '
			@echo 'Building file: $<'
			@echo 'Invoking: GCC C++ Compiler'
			$(CXX) $(CXXFLAGS) -c -o $@ $<
			@echo -n 'Finished building: '
			@echo -e $(YELLOW) '$<'
			@echo -e $(NORMAL) ' '

clean		:
			$(RM) $(OBJS_SERVEUR)
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_GFX)
			@find ./ -name '*~' -exec rm '{}' \;
			@find ./ -name '*#' -exec rm '{}' \;

fclean		:	clean
			$(RM) $(NAME_SERVEUR)
			$(RM) $(NAME_CLIENT)
			$(RM) $(NAME_GFX)

dbg		:	CFLAGS += -g
dbg		:	re

re		:	fclean all

cl		:	CXX = clang++ -Qunused-arguments
cl		:	re
