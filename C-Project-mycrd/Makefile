##
## ETNA PROJECT, 2021
## My_crd
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -f

NAME		=	my_crd

RELEASE_DIR = ./Release/

SRC_DIR = ./srcs/

COMPILEFLAG	=	-Wall -Wextra -Werror -std=c11 -g3

SRC		=	main.c								\
			$(SRC_DIR)my_readline.c				\
			$(SRC_DIR)my_putchar.c				\
			$(SRC_DIR)my_strlen.c				\
			$(SRC_DIR)my_structure_converter.c	\
			$(SRC_DIR)binary_tree_struct.c

OBJ		=	$(SRC:%.c=%.o)

$(NAME):	$(OBJ)
			@echo "\033[01m\033[32mBuilding binary ===>\033[00m"
			$(CC) $(COMPILEFLAG) $(OBJ) -o $(RELEASE_DIR)$(NAME)
			@echo "\033[01m\033[32mDONE\033[00m"

all:	$(NAME)

clean:
		@echo "\033[01m\033[31mRemoving objects ...\033[00m"
		$(RM) $(OBJ)
		@echo  "\033[01m\033[31mDONE\033[00m"

fclean:	clean
		@echo "\033[01m\033[31mRemoving binary : {${NAME}} ...\033[00m"
		$(RM) $(RELEASE_DIR)$(NAME)
		@echo "\033[01m\033[31mDONE\033[00m"

re:	fclean all

.PHONY:	all clean fclean re
