##
## Makefile for zappy in /home/fave_r/rendu/Zappy/src
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue May  5 14:40:23 2015 romaric
## Last update Tue May  5 14:50:21 2015 Thibaut Lopez
##

CC=		gcc

RM=		rm -f

INCLUDES=	-I ./include

CFLAGS=		-W -Wall -Wextra

S_NAME=		zappy

U_SRC=		

S_SRC=		

U_OBJ=		$(U_SRC:.c=.o)

S_OBJ=		$(S_SRC:.c=.o)

all:		$(U_OBJ) $(S_NAME)

serveur:	$(U_OBJ) $(S_NAME)

$(S_NAME):	$(U_OBJ) $(S_OBJ)
		@echo -e "\033[32m[Building] \033[0;m" | tr -d '\n'
		$(CC) -o $@ $(U_OBJ) $(S_OBJ) $(CFLAGS)

%.o:		%.c
		@echo -e "\033[33m[Doing object] \033[0;m" | tr -d '\n'
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
		@echo -e "\033[31m[Cleaning] \033[0;m" | tr -d '\n'
		$(RM) $(U_OBJ)
		@echo -e "\033[31m[Cleaning] \033[0;m" | tr -d '\n'
		$(RM) $(S_OBJ)

fclean:		clean
		@echo -e "\033[31m[Filecleaning] \033[0;m" | tr -d '\n'
		$(RM) $(S_NAME)

re:		fclean all

.PHONY:		all fclean re
