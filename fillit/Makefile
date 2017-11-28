# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruaud <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:44:25 by eruaud            #+#    #+#              #
#    Updated: 2017/11/27 15:46:29 by eruaud      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft/includes/
FUNC = reading sthandling engine main
OBJ = $(addsuffix .o, $(FUNC))
SRC = $(addsuffix .c, $(FUNC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft

clibft:
	make -C libft

$(OBJ) : clibft
	$(CC) $(CFLAGS) -c $(SRC)

clibftclean:
	make -C libft/ clean

clean: clibftclean
	/bin/rm -f $(OBJ)

clibftfclean:
	make -C libft/ fclean

fclean: clean clibftfclean
	/bin/rm -f $(NAME)

re: fclean $(NAME)
