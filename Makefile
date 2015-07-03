##
## Makefile for  in /home/bourma_m/Projet/SystemUnix/zappy
## 
## Made by Mathieu Bourmaud
## Login   <bourma_m@epitech.net>
## 
## Started on  Thu May  7 14:17:43 2015 Mathieu Bourmaud
## Last update Fri Jul  3 11:37:45 2015 Martin Porrès
##

NAME_AI		=	./libs/libAI.so

NAME_CONNECTOR	=	./libs/libAI_c_connector.so

NAME_SERVEUR	=	zappy_server

NAME_CLIENT	=	zappy_ai

NAME_GFX	=	gfx

CC		=	gcc

CXX		=	g++

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra -Werror -I./includes -L./libs -Wl,-rpath=./libs -lncurses

CXXFLAGS	+=	-std=c++11 -W -Wall -Wextra -Werror -I./includes -L./libs -Wl,-rpath=./libs

LIBSH		+=	-lAI -lAI_c_connector

GFXFLAGS	+=	-lSDLmain -lSDL -lSDL_image -lpthread

DYNLIB		+=	-fpic -shared

SRCS_AI		=	sources/AI/AI.cpp			\

SRCS_CONNECTOR	=	sources/AI/AI_c_connector.cpp		\

SRCS_SERVEUR	=	sources/serveur/main.c			\
			sources/serveur/parsing.c		\
			sources/serveur/fill_settings.c		\
			sources/serveur/map_generation.c	\
			sources/serveur/init_serv.c		\
			sources/serveur/call_cmds.c		\
			sources/serveur/checkfds.c		\
			sources/serveur/cmd_connect_nbr.c	\
			sources/serveur/welcome_msg.c		\
			sources/serveur/init_tabs.c		\
			sources/serveur/cmd_broadcast.c		\
			sources/serveur/cmd_broadcast_end.c	\
			sources/serveur/cmd_graphic.c		\
			sources/serveur/cmd_kick.c		\
			sources/serveur/cmd_inventory.c		\
			sources/serveur/cmd_incantation.c	\
			sources/serveur/cmd_right.c		\
			sources/serveur/cmd_move_forward.c	\
			sources/serveur/cmd_drop.c		\
			sources/serveur/cmd_fork.c		\
			sources/serveur/cmd_left.c		\
			sources/serveur/cmd_see.c		\
			sources/serveur/see_with_orientation.c	\
			sources/serveur/cmd_take.c		\
			sources/serveur/read_write.c		\
			sources/serveur/check_team.c		\
			sources/serveur/delay.c			\
			sources/serveur/inc_lvl_1_4.c		\
			sources/serveur/inc_lvl_5_7.c		\
			sources/serveur/write_gfx_bct_pin_pgt_pdr.c	\
			sources/serveur/write_pbc_pnw_pdi_pic.c		\
			sources/serveur/write_pie_plv_pex_pfk_enw.c	\
			sources/serveur/write_eht_ok.c		\
			$(SRCS_COMMONS)

SRCS_CLIENT	=	sources/client/main.c		\
			sources/client/parsing.c	\
			sources/client/parsing_fct.c	\
			sources/client/connect.c	\
			sources/client/welcome.c	\
			$(SRCS_COMMONS)

SRCS_GFX	=	sources/GFX/main.c		\
			sources/GFX/usage.c		\
			sources/GFX/coreGFX.c		\
			sources/GFX/gfx_loop.c		\
			sources/GFX/initStruct.c	\
			sources/GFX/initWindow.c	\
			sources/GFX/server_read.c	\
			sources/GFX/initNetwork.c	\
			sources/GFX/save_srv_cmd.c	\
			sources/GFX/eventHandler.c	\
			sources/GFX/handleCmd.c		\
			sources/GFX/getCmd.c		\
			sources/GFX/initCmdTab.c	\
			sources/GFX/welcomeServ.c	\
			sources/GFX/cmdList.c		\
			sources/GFX/allocMap.c		\
			sources/GFX/getPlayer.c		\
			sources/GFX/draw.c		\
			sources/GFX/freeStruct.c	\
			$(SRCS_COMMONS)

SRCS_COMMONS	=	sources/misc/errors.c		\
			sources/misc/my_regex.c		\
			sources/misc/rm_spaces.c	\
			sources/misc/count_char.c	\
			sources/misc/my_write.c		\
			sources/misc/itoa.c		\

OBJS_AI		=	$(SRCS_AI:.cpp=.o)

OBJS_SERVEUR	=	$(SRCS_SERVEUR:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

OBJS_GFX	=	$(SRCS_GFX:.c=.o)

GREEN		=	"\\033[1;32m"

NORMAL		=	"\\033[0;39m"

YELLOW		=	"\\033[1;33m"

CYAN		=	"\\033[1;36m"

all		:	$(NAME_AI) $(NAME_CONNECTOR) $(NAME_SERVEUR) $(NAME_CLIENT) $(NAME_GFX)

$(NAME_AI)	:
			@echo ' '
			@echo 'Building target: $@'
			@echo 'Invoking: GCC C++ Linker'
			$(CXX) $(DYNLIB) $(CXXFLAGS) $(SRCS_AI) -o $(NAME_AI)
			@echo -n 'Finished building target:'
			@echo -e $(CYAN) '$@'
			@echo -e $(NORMAL) ' '

$(NAME_CONNECTOR):
			@echo ' '
			@echo 'Building target: $@'
			@echo 'Invoking: GCC C++ Linker'
			$(CXX) $(DYNLIB) $(CXXFLAGS) $(SRCS_CONNECTOR) -o $(NAME_CONNECTOR) -L./libs/ -lAI
			@echo -n 'Finished building target:'
			@echo -e $(CYAN) '$@'
			@echo -e $(NORMAL) ' '

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
			$(CC) $(OBJS_CLIENT) $(CFLAGS) $(LIBSH) -o $(NAME_CLIENT)
			@echo -n 'Finished building target:'
			@echo -e $(GREEN) '$@'
			@echo -e $(NORMAL) ' '

$(NAME_GFX)	:	$(OBJS_GFX)
			@echo ' '
			@echo 'Building target: $@'
			@echo 'Invoking: GCC C Linker'
			$(CC) $(OBJS_GFX) -o $(NAME_GFX) $(GFXFLAGS) 
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

clean		:
			$(RM) $(OBJS_SERVEUR)
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_GFX)
			@find ./ -name '*~' -exec rm '{}' \;
			@find ./ -name '*#' -exec rm '{}' \;

fclean		:	clean
			$(RM) $(NAME_AI)
			$(RM) $(NAME_CONNECTOR)
			$(RM) $(NAME_SERVEUR)
			$(RM) $(NAME_CLIENT)
			$(RM) $(NAME_GFX)

dbg		:	CFLAGS += -g
dbg		:	re

re		:	fclean all

cl		:	CXX = clang++ -Qunused-arguments
cl		:	re
