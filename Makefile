# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:51:41 by maghayev          #+#    #+#              #
#    Updated: 2019/09/24 20:39:30 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
PURPLE = "\033[35m\c"
RED = "\033[31m\c"
NC="\033[0m\c"
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = headers/libft.h headers/get_next_line.h
SRC  = $(wildcard modules/*/*.c)

OBJECT = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	@echo $(PURPLE)
	$(CC) $(CFLAGS) -g -c -o $@ $<
	@echo $(NC)

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $@ $^
	@ranlib $@
	@echo "Finished Building LibFT!"

clean:
	@echo $(RED)
	@echo "*sadly* Cleanning LibFT... Wait... *sniffs*"
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned LibFT! Bye Bye! *without intusiasm*"
	@echo $(NC)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "LibFT .a has been deleted! *sign*"

re: fclean all

.PHONY: all clean fclean re
