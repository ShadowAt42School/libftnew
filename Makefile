# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:51:41 by maghayev          #+#    #+#              #
#    Updated: 2020/02/11 19:13:46 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
GREEN = "\033[32m\c"
RED = "\033[31m\c"
YELLOW = "\033[33m\c"
UNDERLINE = "\033[4m\c"
PURPLE = "\033[35m\c"
NC="\033[0m\c"
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC  = $(wildcard modules/*/*.c)
LIBA = -Iheaders/

OBJECT = $(SRC:.c=.o)

%.o: %.c
	@echo $(PURPLE)
	$(CC) $(CFLAGS) $(LIBA) -g -o $@ -c $<
	@echo $(NC)

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $@ $^
	@ranlib $@
	@echo $(GREEN)
	@echo "Finished Building libft!"
	@echo $(NC)

objects: $(OBJECT)
	@echo $(GREEN)
	@echo "Finished Building libft objects!"
	@echo $(NC)

clean:
	@echo $(YELLOW)
	@echo "libft clean started"
	@/bin/rm -f $(OBJECT)
	@echo $(NC)
	@echo ".........."
	@echo $(YELLOW)
	@echo "libft clean finished"
	@echo $(NC)

fclean: clean
	@echo $(RED)
	@/bin/rm -f $(NAME)
	@echo "libft libriary has been cleaned."
	@echo $(NC)

re: fclean all

.PHONY: all clean fclean re
