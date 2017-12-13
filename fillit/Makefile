# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruaud <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:44:25 by eruaud            #+#    #+#              #
#    Updated: 2017/12/13 14:57:02 by eruaud      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FUNC = reading sthandling engine main
SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))
HEADER = -I libft/includes/
LDLIBS = -lft
LDFLAGS = -L libft/

all: $(NAME)

lib:
	make -C libft

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)

.PHONY = all clean fclean re lib
