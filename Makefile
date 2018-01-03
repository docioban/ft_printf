# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: docioban <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/22 00:40:57 by docioban          #+#    #+#              #
#    Updated: 2017/12/24 12:32:17 by docioban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = *.c function/*.c flags/*.c flags/flags_print/*.c
OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC) -I.

makeprog: $(NAME) $(OBJ)
	$(CC) -c main/main.c
	$(CC) $(FLAGS) -L. $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all
