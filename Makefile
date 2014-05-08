# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollin <acollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/08 21:22:20 by acollin           #+#    #+#              #
#    Updated: 2014/05/08 22:16:44 by acollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bit_philo
VERSION=1.0.4
CFLAGS= -Wall -Werror -Wextra -g

SRC=global_philo.c \
	main.c \

OBJ=$(SRC:.c=.o)

all: $(NAME) finish

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS) -lpthread

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

