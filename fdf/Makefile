# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:47:21 by anmiron           #+#    #+#              #
#    Updated: 2017/03/22 19:07:41 by anmiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework Appkit -framework OpenGL
SRC = desenare.c conversie.c citire.c keys.c
OBJ = desenare.o conversie.o citire.o keys.o
INCL = -I fdf.h -I ./libft/libft.h -I ./get_next_line/get_next_line.h

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) $(INCL) -c $(SRC)
	gcc $(OBJ) libft/libft.a -o $(NAME) $(MLX)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)


fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
