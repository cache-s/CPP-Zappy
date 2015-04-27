##
## Makefile for zappy in /home/cache-_s/rendu/tmpZAPPY
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Fri Apr 24 13:39:47 2015 Sebastien Cache-Delanos
## Last update Fri Apr 24 13:39:48 2015 Sebastien Cache-Delanos
##

NAME	= zappy

SRCS	= ./sources/main.c			\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -g -W -Wall -Wextra -Werror -I ./includes

CC	= g++

RM	= rm -rf

GREEN	= "\\033[1;32m"

NORMAL	= "\\033[0;39m"

YELLOW	= "\\033[1;33m"

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	$(CC) -lpthread -o $@ $^
	@echo -n 'Finished building target:'
	@echo -e $(GREEN) '$@'
	@echo -e $(NORMAL) ' '

%.o: %.c
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo -n 'Finished building: '
	@echo -e $(YELLOW) '$<'
	@echo -e $(NORMAL) ' '

clean:
	$(RM) $(OBJS)
	@find ./ -name '*~' -exec rm '{}' \;
	@find ./ -name '*#' -exec rm '{}' \;

fclean: clean
	$(RM) $(NAME)

re: fclean all
