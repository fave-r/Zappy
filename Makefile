##
## Makefile for makefile in /home/thibaut.lopez/Corewar
##
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
##
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Mon Jun  8 13:18:53 2015 Thibaut Lopez
##

SRV_N=		server/

IG_N=		clients/graphic/

all:		
		make -C $(SRV_N)
		make -C $(IG_N)
clean:
		make clean -C $(SRV_N)
		make clean -C $(IG_N)

fclean:		clean
		make fclean -C $(SRV_N)
		make fclean -C $(IG_N)

re:		fclean all
