# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruaud <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:44:25 by eruaud            #+#    #+#              #
#    Updated: 2017/12/22 13:23:12 by eruaud      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -I includes -Wall -Wextra -Werror -c
FUNC = putchar strcpy strstr strnstr strncpy strncmp strncat \
strlcat strcat putstr putnbr isprint isdigit isalpha isalnum tolower \
toupper atoi strlen strcmp strdup memset bzero memcpy memccpy isascii \
memmove memchr memcmp strchr strrchr memalloc memdel strnew strdel \
strclr striter striteri strmap strmapi strequ strnequ strsub strjoin\
putchar_fd putstr_fd putendl putendl_fd putnbr_fd strtrim strsplit\
itoa lstnew lstdelone lstdel lstadd lstiter lstmap abs itoa_base \
swap isspace strupcase strlowcase strcapitalize isupper islower \
isblank strndup puttab_fd
HEADER = -I includes/
NFUNC = $(addprefix ft_, $(FUNC))
OBJ = $(addsuffix .o, $(NFUNC))
SRC = $(addsuffix .c, $(NFUNC))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

norm :
	@norminette $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean norm re
