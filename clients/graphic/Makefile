##
## Makefile for zappy in /home/fave_r/rendu/Zappy/clients/graphic
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Jun  8 12:54:25 2015 romaric
## Last update Mon Jun  8 13:01:09 2015 romaric
##

CXX=		g++

RM=		rm -f

INCLUDES=	-I ./includes

CPPFLAGS=	-W -Wall -Wextra -std=c++11

NAME=		graphic

SRC=		src/main.cpp						\
                src/file

OBJ=		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[32m[Building] \033[0;m" | tr -d '\n'
		$(CXX) -o $@ $(OBJ) $(CPPFLAGS)

%.o:		%.cpp
		@echo -e "\033[33m[Doing object] \033[0;m" | tr -d '\n'
		$(CXX) $(CPPFLAGS) $(INCLUDES) -c -o $@ $<

clean:
		@echo -e "\033[31m[Cleaning] \033[0;m" | tr -d '\n'
		$(RM) $(OBJ)

fclean:		clean
		@echo -e "\033[31m[Filecleaning] \033[0;m" | tr -d '\n'
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re
