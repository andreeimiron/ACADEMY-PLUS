# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 14:06:59 by anmiron           #+#    #+#              #
#    Updated: 2018/02/08 14:14:32 by anmiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = Colleen
NAME2 = Grace
NAME3 = Sully

SRC1 = Colleen.c
SRC2 = Grace.c
SRC3 = Sully.c

OBJ1 = Colleen.o
OBJ2 = Grace.o
OBJ3 = Sully.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME1)/$(NAME1) $(NAME2)/$(NAME2) $(NAME3)/$(NAME3)

$(NAME1)/$(NAME1):
	clang $(FLAGS) -c $(NAME1)/$(SRC1) -o $(NAME1)/$(OBJ1)
	clang $(NAME1)/$(OBJ1) -o $(NAME1)/$(NAME1)

$(NAME2)/$(NAME2):
	clang $(FLAGS) -c $(NAME2)/$(SRC2) -o $(NAME2)/$(OBJ2)
	clang $(NAME2)/$(OBJ2) -o $(NAME2)/$(NAME2)

$(NAME3)/$(NAME3):
	clang $(FLAGS) -c $(NAME3)/$(SRC3) -o $(NAME3)/$(OBJ3)
	clang $(NAME3)/$(OBJ3) -o $(NAME3)/$(NAME3)

clean:
	rm -rf $(NAME1)/$(OBJ1)
	rm -rf $(NAME2)/$(OBJ2)
	rm -rf $(NAME3)/$(OBJ3)

fclean: clean
	rm -rf $(NAME1)/$(NAME1)
	rm -rf $(NAME2)/$(NAME2)
	rm -rf $(NAME3)/$(NAME3)

re: fclean all
