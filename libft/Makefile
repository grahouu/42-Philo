# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 13:34:21 by glovichi          #+#    #+#              #
#    Updated: 2014/05/04 12:25:38 by glovichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c			\
  	  ft_putstr.c			\
	  ft_putnbr.c			\
	  ft_cmpstr.c

HEAD = ../includes/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Libft is okay

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

re:	fclean all
