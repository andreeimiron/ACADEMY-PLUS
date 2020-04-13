# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 16:37:57 by anmiron           #+#    #+#              #
#    Updated: 2017/03/22 19:32:12 by anmiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -c -I.
NAME = libft.a
SRCS = ft_atoi.c ft_itoa.c ft_putchar.c ft_strequ.c ft_strrchr.c ft_bzero.c \
	   ft_lstadd.c ft_putchar_fd.c ft_striter.c ft_strsplit.c ft_isalnum.c \
	   ft_lstdel.c ft_putendl.c ft_striteri.c ft_strstr.c ft_isalpha.c \
	   ft_lstdelone.c ft_putendl_fd.c ft_strjoin.c ft_strsub.c ft_isascii.c \
	   ft_lstiter.c ft_putnbr.c ft_strlcat.c ft_strtrim.c ft_isupper.c \
	   ft_memset.c ft_strdup.c ft_strnstr.c ft_lstmap.c ft_putnbr_fd.c \
	   ft_strlen.c ft_strupr.c ft_iscntrl.c ft_lstnew.c ft_putstr.c \
	   ft_strlwr.c ft_swap.c ft_isdigit.c ft_memalloc.c \
	   ft_putstr_fd.c ft_strmap.c ft_tolower.c ft_isgraph.c ft_memccpy.c \
	   ft_strcat.c ft_strmapi.c ft_toupper.c ft_islower.c ft_memchr.c \
	   ft_strchr.c ft_strncat.c ft_isprime.c ft_memcmp.c ft_strclr.c \
	   ft_strncmp.c ft_isprint.c ft_memcpy.c ft_strcmp.c ft_strncpy.c \
	   ft_ispunct.c ft_memdel.c ft_strcpy.c ft_strnequ.c ft_isspace.c \
	   ft_memmove.c ft_strdel.c ft_strnew.c get_next_line.c

OBJ = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
