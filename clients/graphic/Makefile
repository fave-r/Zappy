##
## Makefile for zappy in /home/fave_r/rendu/Zappy/clients/graphic
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Jun  8 12:54:25 2015 romaric
## Last update Sat Jun 27 01:28:21 2015 jean_c
##

CXX =		g++

CXXFLAGS =	-W -Wall -Werror -Wextra -std=gnu++11
CXXFLAGS +=	-I./Includes -I./Library/includes

LDFLAGS =	-Wl,--rpath=./Library/libs -lgdl_gl -lrt -lfbxsdk -lSDL2 -lSDL2_ttf
LDFLAGS +=	-lSDL2_image -ldl -lGLU -lX11 -lGLEW -lGL -lX11 -lXi -lXrandr
LDFLAGS +=	-lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -Ofast

LDLIBS =	-L./Library/libs -Wl,--rpath=./Library/fmod
LDLIBS +=	./Library/fmod/libfmod.so

NAME =		graphic
RM =		rm -rf

SRC =		Sources

SRCS =		$(SRC)/Button.cpp		\
		$(SRC)/Client.cpp		\
		$(SRC)/Command.cpp		\
		$(SRC)/Input.cpp		\
		$(SRC)/IRefreshable.cpp		\
		$(SRC)/main.cpp			\
		$(SRC)/Map.cpp			\
		$(SRC)/Menu.cpp			\
		$(SRC)/Music.cpp		\
		$(SRC)/Option.cpp		\
		$(SRC)/RadioBox.cpp		\
		$(SRC)/Rectangle.cpp		\
		$(SRC)/RingBuffer.cpp		\
		$(SRC)/ScreenTitle.cpp		\
		$(SRC)/SlideBar.cpp		\
		$(SRC)/Socket.cpp		\
		$(SRC)/Timeval.cpp		\
		$(SRC)/Content.cpp		\
		$(SRC)/Graphic.cpp		\
                $(SRC)/AObject.cpp            	\
                $(SRC)/Ground.cpp             	\
                $(SRC)/ModelPool.cpp          	\
                $(SRC)/TexturePool.cpp        	\
                $(SRC)/Camera.cpp             	\
                $(SRC)/APlayer.cpp            	\
		$(SRC)/TextBox.cpp		\
		$(SRC)/Food.cpp			\
		$(SRC)/Linemate.cpp		\
		$(SRC)/Deraumere.cpp		\
		$(SRC)/Sibur.cpp		\
		$(SRC)/Mendiane.cpp		\
		$(SRC)/Phiras.cpp		\
		$(SRC)/Thystame.cpp		\

OBJS =		$(SRCS:.cpp=.o)

all:		$(NAME)

%.o:		%.cpp
		@echo -e "\033[33m[Doing object] \033[0m" | tr -d '\n'
		$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME):	$(OBJS)
		@echo -e "\033[32m[Building] \033[0m" | tr -d '\n'
		$(CXX) $(OBJS) -o $(NAME) $(LDLIBS) $(LDFLAGS)

clean:
		@echo -e "\033[31m[Cleaning] \033[0m" | tr -d '\n'
		$(RM) $(OBJS)

fclean:		clean
		@echo -e "\033[31m[Filecleaning] \033[0m" | tr -d '\n'
		$(RM) $(NAME)

re:		fclean all

.PHONY:		fclean clean $(NAME) all
