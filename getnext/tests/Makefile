# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruaud <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:44:25 by eruaud            #+#    #+#              #
#    Updated: 2017/12/27 13:43:40 by eruaud      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  ../get_next_line.c
TESTS = 00_launcher.c \
		01_test.c \
		02_test.c \
		03_test.c \
		04_test.c \
		05_test.c

TESTS_PATH = $(addprefix get_next_line/, $(TESTS))
TESTS_OBJ = $(TESTS_PATH:.c = .o)
# Combine tests
ALL_SRC = $(SRC) $(TESTS_PATH)
ALL_OBJ = $(ALL_SRC:.c=.o)
# CC parameters
NAME = run_test
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I ../tests/includes/ -I ../libft/includes/ -I ../framework/includes/
LDLIBS = -lft -lunit
LDFLAGS = -L ../libft/ -L ../framework/

# rules

all: $(NAME)

lib:
	@echo "\033[1;31mCompiling libft..."
	@make -C ../libft
	@echo "\033[1;92mSuccess !"

framework: lib
	@echo "\033[1;31mCompiling libunit..."
	@make -C ../framework
	@echo "\033[1;92mSuccess !"

$(NAME): framework $(ALL_OBJ)
	@echo "\033[1;31mCompiling project..."
	@$(CC) $(CFLAGS) -o $(NAME) $(ALL_OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "\033[1;92mSuccess !"

test: fclean $(NAME)
	@./$(NAME)

norm :
	@norminette $(SRC)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

clean:
	@/bin/rm -f $(ALL_OBJ)
	@make -C ../libft clean
	@make -C ../framework clean
	@echo "\033[34;1mProject has been cleaned !"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ../libft fclean
	@make -C ../framework fclean
	@echo "\033[33;1mProject has been removed !"

re: fclean $(NAME)

.PHONY = all framework clean fclean re norm lib
