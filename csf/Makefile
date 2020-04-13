.PHONY: all, fclean, clean, re

SRC_PATH = src/

SRC_NAME = src/fractol.c			\
		   src/mandelbrot.c		\
		   src/julia.c				\
		   src/tricorn.c			\
		   src/burning_ship.c	\
		   src/sword.c				\
		   src/chameleon.c		\
		   src/key_mouse.c		\
		   src/key_hook.c			\
		   src/key_hook_2.c		\

OBJ_PATH	=	obj/

INCLUDE 	= -Iinclude -Ilibft/includes

LDFLAGS		=	-Llibft -Lminilibx
LDLIBS 		= -lft

NAME 			=	fractol

CC 				=	clang

CFLAGS 		=	-Wall -Wextra -Werror -O3
LIBGRPH 	= -lmlx -framework OpenGL -framework Appkit

OBJ_NAME 	=	$(addsuffix .o, $(basename $(SRC_NAME)))

SRC 			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ 			=	$(addprefix $(OBJ_PATH),$(notdir $(OBJ_NAME)))

VPATH			=	$(shell find $(SRC_PATH) -type d)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "\033[33mProject compilation\033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(LIBGRPH) $^ -o $@
	@echo "\033[32mCompilation SUCCESS\033[0m"

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@echo "\033[33m.o's cleaning\033[0m"
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
