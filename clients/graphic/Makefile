##
## Makefile for zappy in /home/fave_r/rendu/Zappy/clients/graphic
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Jun  8 12:54:25 2015 romaric
## Last update Wed Jun 24 12:22:32 2015 jean_c
##

CXX =		g++

CXXFLAGS =	-W -Wall -Werror -Wextra -std=gnu++11 -g3
CXXFLAGS +=	-I./Includes -I./Library/includes

LDFLAGS =	-Wl,--rpath=./Library/libs -lgdl_gl -lrt -lfbxsdk -lSDL2 -lSDL2_ttf
LDFLAGS +=	-lSDL2_image -ldl -lGLU -lX11 -lGLEW -lGL -lX11 -lXi -lXrandr
LDFLAGS +=	-lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

LDLIBS =	-L./Library/libs -Wl,--rpath=./Library/libs/fmod
LDLIBS +=	./Library/libs/fmod/libfmod.so

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

OBJS =		$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDLIBS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		fclean clean $(NAME) all
