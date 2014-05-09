# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollin <acollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/08 21:22:20 by acollin           #+#    #+#              #
#    Updated: 2014/05/09 09:59:16 by glovichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bit_philo
VERSION=1.0.4
CFLAGS= -Wall -Werror -Wextra -g

SRC =	main.c					\
		global_philo.c			\
		./libft/ft_putstr.c		\
		./libft/ft_putnbr.c		\
		./libft/ft_putchar.c


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

