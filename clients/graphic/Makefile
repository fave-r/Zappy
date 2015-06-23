##
## Makefile for zappy in /home/fave_r/rendu/Zappy/clients/graphic
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Jun  8 12:54:25 2015 romaric
## Last update Tue Jun 23 16:49:25 2015 Thibaut Lopez
##

CXX=		g++

RM=		rm -f

INCLUDES=	-I ./includes

CPPFLAGS=	-W -Wall -Wextra -std=c++11 -g3 -lSDL2 -lSDL2_ttf -lSDL2_image

FMOD=		-Wl,--rpath=./tools/lib/fmod ./tools/lib/fmod/libfmod.so

NAME=		graphic

SRC=		src/Button.cpp		\
		src/Client.cpp		\
		src/Command.cpp		\
		src/Input.cpp		\
		src/IRefreshable.cpp	\
		src/main.cpp		\
		src/Map.cpp		\
		src/Menu.cpp		\
		src/Music.cpp		\
		src/Option.cpp		\
		src/RadioBox.cpp	\
		src/Rectangle.cpp	\
		src/RingBuffer.cpp	\
		src/ScreenTitle.cpp	\
		src/SlideBar.cpp	\
		src/Socket.cpp		\
		src/Timeval.cpp

OBJ=		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[32m[Building] \033[0;m" | tr -d '\n'
		$(CXX) -o $@ $(OBJ) $(CPPFLAGS) $(FMOD)

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
