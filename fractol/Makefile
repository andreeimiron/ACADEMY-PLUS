# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 19:10:34 by anmiron           #+#    #+#              #
#    Updated: 2017/05/25 18:32:11 by anmiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework Appkit -framework OpenGL
SRC = draw.c init.c main.c keys.c extra.c
OBJ = draw.o init.o main.o keys.o extra.o
INCL = -I fractol.h -I ./libft/libft.h

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
