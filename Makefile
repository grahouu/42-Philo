# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollin <acollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/08 21:22:20 by acollin           #+#    #+#              #
#    Updated: 2014/05/11 12:07:38 by glovichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
VERSION = 1.0.4
CFLAGS = -Wall -Werror -Wextra -g

SRC =	main.c					\
		global_philo.c			\
		./libft/ft_putstr.c		\
		./libft/ft_putnbr.c		\
		./libft/ft_putchar.c	\
		./libft/ft_atoi.c		\
		./libft/ft_itoa.c		\
		ft_eaters.c

OBJ = $(SRC:.c=.o)

all: $(NAME) finish

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS) -lpthread
	@echo This Job is Done sir !

%.o: %.c philo.h
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

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

