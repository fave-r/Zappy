##
## Makefile for zappy in /home/fave_r/rendu/Zappy
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Jun  8 13:24:05 2015 romaric
## Last update Mon Jun 29 10:40:30 2015 romaric
##

SRV_N=		server/

IG_N=		clients/graphic/

all:
		make -C $(SRV_N)
		make -C $(IG_N)
		@test -d bin || mkdir bin
		@cp $(SRV_N)zappy_server bin/
		@printf "\033[1;32mBinaries in bin repertory\033[0;m\n"

zappy_server:
		make -C $(SRV_N)
		@test -d bin || mkdir bin
		@cp $(SRV_N)zappy_server bin/
		@printf "\033[1;32mBinaries in bin repertory\033[0;m\n"



clean:
		make clean -C $(SRV_N)
		make clean -C $(IG_N)

fclean:		clean
		make fclean -C $(SRV_N)
		make fclean -C $(IG_N)
		@rm -rf bin

re:		fclean all
