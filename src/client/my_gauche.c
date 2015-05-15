/*
** my_gauche.c for my_gauche in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Fri May 15 16:47:27 2015 romaric
*/

#include "server.h"

int	my_gauche(__attribute__((unused)) char **com
		  , __attribute__((unused)) t_zap *data
		  , t_user *usr)
{
  GET_DIR(usr) = S_MOD(GET_DIR(usr) - 1, 4);
  fill_cb(&usr->wr, "ok\n", 3);
  return (0);
}
