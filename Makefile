##
## Makefile for zappy in /home/fave_r/rendu/Zappy/src
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue May  5 14:40:23 2015 romaric
## Last update Thu Jun  4 17:34:01 2015 Thibaut Lopez
##

CC=		gcc

RM=		rm -f

INCLUDES=	-I ./includes

CFLAGS=		-W -Wall -Wextra -g3 -lm

S_NAME=		zappy

U_SRC=		src/utils/common_func.c				\
		src/utils/queue.c				\
		src/utils/str.c					\
		src/utils/sstr.c				\
		src/utils/stwt.c				\
		src/utils/tv.c					\
		src/utils/xfunction.c				\
                src/utils/CircularBuffer/circular_buffer.c	\
                src/utils/CircularBuffer/get_value.c		\
                src/utils/CircularBuffer/read_cb.c

S_SRC=		src/asking.c					\
		src/base_team.c					\
		src/command_func.c				\
		src/data.c					\
		src/fd_func.c					\
		src/getter.c					\
		src/graphic_ptr.c				\
		src/main.c					\
		src/manage.c					\
		src/parser.c					\
		src/ptrs_to_function.c				\
		src/read_com.c					\
		src/setter.c					\
		src/team.c					\
		src/while_serv.c				\
		src/x_tcp.c					\
		src/client/cone_x.c				\
		src/client/cone_y.c				\
		src/client/my_avance.c				\
		src/client/my_broadcast.c			\
		src/client/my_connect_nbr.c			\
		src/client/my_droite.c				\
		src/client/my_expulse.c				\
		src/client/my_fork.c				\
		src/client/my_gauche.c				\
		src/client/my_incantation.c			\
		src/client/my_inventaire.c			\
		src/client/my_other.c				\
		src/client/my_pose.c				\
		src/client/my_prend.c				\
		src/client/my_voir.c				\
		src/client/func_level.c				\
		src/client/inc_to_graphic.c			\
		src/graphic/my_agt.c				\
		src/graphic/my_anr.c				\
		src/graphic/my_apr.c				\
		src/graphic/my_bct.c				\
		src/graphic/my_graphic.c			\
		src/graphic/my_mct.c				\
		src/graphic/my_msz.c				\
		src/graphic/my_pin.c				\
		src/graphic/my_plv.c				\
		src/graphic/my_pnw.c				\
		src/graphic/my_ppo.c				\
		src/graphic/my_sbp.c				\
		src/graphic/my_sct.c				\
		src/graphic/my_sgt.c				\
		src/graphic/my_sms.c				\
		src/graphic/my_spi.c				\
		src/graphic/my_spk.c				\
		src/graphic/my_spl.c				\
		src/graphic/my_spp.c				\
		src/graphic/my_srs.c				\
		src/graphic/my_sst.c				\
		src/graphic/my_stn.c				\
		src/graphic/my_suc.c				\
		src/graphic/my_tna.c

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
