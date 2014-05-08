# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollin <acollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/08 15:18:07 by acollin           #+#    #+#              #
#    Updated: 2014/05/08 15:18:53 by acollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bit_philo
VERSION=1.0.0
CFLAGS=-Wall -Werror -Wextra -g

SRC=main.c \

OBJ=$(SRC:.c=.o)

all: $(NAME) finish

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c philo.h
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

