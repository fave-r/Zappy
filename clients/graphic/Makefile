##
## Makefile for zappy in /home/fave_r/rendu/Zappy/clients/graphic
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Jun  8 12:54:25 2015 romaric
<<<<<<< HEAD
## Last update Fri Jun 26 16:53:41 2015 Thibaut Lopez
=======
## Last update Fri Jun 26 17:09:21 2015 romaric
>>>>>>> 421e7ae76cb64e4b918c43bf43eda6382e846dad
##

CXX =		g++

CXXFLAGS =	-W -Wall -Werror -Wextra -std=gnu++11 -g3
CXXFLAGS +=	-I./Includes -I./Library/includes

LDFLAGS =	-Wl,--rpath=./Library/libs -lgdl_gl -lrt -lfbxsdk -lSDL2 -lSDL2_ttf
LDFLAGS +=	-lSDL2_image -ldl -lGLU -lX11 -lGLEW -lGL -lX11 -lXi -lXrandr
LDFLAGS +=	-lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

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
                $(SRC)/ARessources.cpp		\
		$(SRC)/TextBox.cpp

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
