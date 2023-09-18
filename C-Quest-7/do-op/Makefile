##
## ETNA PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC              =       gcc

RM              =       rm -f

NAME            =       do-op

COMPILEFLAG     =       -ggdb3 -Wall -Wextra -Werror -pedantic -std=c99 -g -g3

INCLUDE         =       -Iinclude/

USELESS_F       =       *~

U_F_SRC         =       srcs/*~

U_F_INC         =       include/*~

U_F_VG          =       vgcore.*

DEBUG           =       with debug

CFLAGS          =       $(COMPILEFLAG) $(INCLUDE)

SRC             =       main.c                  \
                        srcs/do-op.c

OBJ             =       $(SRC:.c=.o)

$(OBJDIR)%.o:%.c
			@$(CC) $(CFLAGS) -o $@ -c $<
			@if test -s $*.c; then \
			echo -e "\033[01m\033[35m Compiling $(DEBUG)\033[00m\
                        \033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
                        else \
                        echo -e "\033[01m\033[33m Compiling $(DEBUG)\033[00m\
                        \033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

$(NAME):                $(OBJ)
			@echo -e "\033[01m\033[31mLinking ...\033[00m"
			@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
			@echo -e "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

all:                    $(NAME)

clean:
			@$(RM) $(OBJ)
			@$(RM) $(USELESS_F)
			@$(RM) $(U_F_SRC)
			@$(RM) $(U_F_INC)
			@$(RM) $(U_F_UTEST)
			@$(RM) $(U_F_VG)
			@echo -e "\033[01m\033[31mRemoving objects ...\033[00m"

fclean:                 clean
			@$(RM) $(NAME)
			@echo -e "\033[01m\033[31mRemoving binary : {${NAME}} ...\033[00m"

re:                     fclean all

.PHONY:                 all clean fclean re
