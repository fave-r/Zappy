##
## Makefile for zappy in /home/fave_r/rendu/Zappy/src
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue May  5 14:40:23 2015 romaric
## Last update Tue May 12 17:19:57 2015 romaric
##

CC=		gcc

RM=		rm -f

INCLUDES=	-I ./includes

CFLAGS=		-W -Wall -Wextra -g3

S_NAME=		zappy

U_SRC=		src/utils/common_func.c				\
		src/utils/str.c					\
		src/utils/sstr.c				\
		src/utils/stwt.c				\
		src/utils/xfunction.c				\
                src/utils/CircularBuffer/circular_buffer.c	\
                src/utils/CircularBuffer/get_value.c		\
                src/utils/CircularBuffer/read_cb.c

S_SRC=		src/data.c					\
		src/fd_func.c					\
		src/main.c					\
		src/parser.c					\
		src/setter.c					\
		src/while_serv.c				\
		src/x_tcp.c					\
		src/graphic/my_bct.c				\
		src/graphic/my_ebo.c				\
		src/graphic/my_edi.c				\
		src/graphic/my_eht.c				\
		src/graphic/my_enw.c				\
		src/graphic/my_graphic.c			\
		src/graphic/my_mct.c				\
		src/graphic/my_msz.c				\
		src/graphic/my_pbc.c				\
		src/graphic/my_pdi.c				\
		src/graphic/my_pdr.c				\
		src/graphic/my_pex.c				\
		src/graphic/my_pfk.c				\
		src/graphic/my_pgt.c				\
		src/graphic/my_pic.c				\
		src/graphic/my_pie.c				\
		src/graphic/my_pin.c				\
		src/graphic/my_plv.c				\
		src/graphic/my_pnw.c				\
		src/graphic/my_ppo.c				\
		src/graphic/my_sbp.c				\
		src/graphic/my_seg.c				\
		src/graphic/my_sgt.c				\
		src/graphic/my_smg.c				\
		src/graphic/my_sst.c				\
		src/graphic/my_suc.c				\
		src/graphic/my_tna.c				\
		src/command_func.c

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
