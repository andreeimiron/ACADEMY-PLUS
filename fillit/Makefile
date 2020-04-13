# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/27 18:11:43 by anmiron           #+#    #+#              #
#    Updated: 2017/02/23 19:46:29 by anmiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = fillit.c solver.c verificare.c salvare.c
OBJ = fillit.o solver.o verificare.o salvare.o
INCL = -I fillit.h -I ./libft/libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(INCL) -c $(SRC)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
