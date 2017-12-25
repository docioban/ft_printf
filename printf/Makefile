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
#NAME = libftprintf.a
UNTILIB = libft/libft.a
SRC = ft_printf.c ft_put/*.c
OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

#$(UNTILIB):
#	cd libft; make;

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

makeprog: $(NAME) $(OBJ)
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -L. $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ) main.o
#	@cd libft; make clean;
#	cd ft_put; make clean;

fclean: clean
	@rm -f $(NAME) $(PROG)
#	@cd libft; make fclean; cd ..;

re: fclean all
