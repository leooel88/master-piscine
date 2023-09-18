####
## ETNA PROJECT, 2021
## First program in C
## File description:
##              Exercise #1 of day #16 : Makefile of the exercise
####


CC = gcc
NAME = libmy.a
LIB_DIR = ./lib/
MY_DIR = ./lib/my/
LIB_FLAGS = -L$(LIB_DIR) -l$(NAME)
COMPILEFLAGS = -Wall -Wextra -Werror -std=c11 $(LIB_FLAGS)
SRC = $(MY_DIR)my_putchar.c \
	  $(MY_DIR)my_putstr.c  \
	  $(MY_DIR)my_strlen.c  \
	  $(MY_DIR)my_getnbr.c  \
	  $(MY_DIR)my_putnbr.c  \
	  $(MY_DIR)my_isneg.c   \
	  $(MY_DIR)my_swap.c    \
	  $(MY_DIR)my_strcpy.c  \
	  $(MY_DIR)my_strncpy.c \
	  $(MY_DIR)my_strcmp.c  \
	  $(MY_DIR)my_strncmp.c \
	  $(MY_DIR)my_strcat.c  \
	  $(MY_DIR)my_strncat.c \
	  $(MY_DIR)my_strstr.c  \
	  $(MY_DIR)my_strdup.c  

OBJ = $(SRC:%.c=%.o)
LIB_CMD = ar r $(LIB_DIR)$(NAME) $(OBJ)
RM = rm -f

$(NAME):	$(OBJ)
		@echo "\033[01m\033[32mBuilding library ===>\033[00m"
		$(LIB_CMD)
		ranlib $(LIB_DIR)$(NAME)
		@echo "\033[01m\033[32mDONE\033[00m"

all:	$(NAME)

clean:	
		@echo "\033[01m\033[31mRemoving objects ...\033[00m"
		$(RM) $(OBJ)
		@echo "\033[01m\033[31mDONE\033[00m"

fclean: clean
		@echo "\033[01m\033[31mRemoving library ...\033[00m"
		$(RM) $(LIB_DIR)$(NAME)
		@echo "\033[01m\033[31mDONE\033[00m"

re:	fclean all

.PHONY:	all clean fclean re