/*
** my_droite.c for my_droite in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Fri May 15 17:36:23 2015 Thibaut Lopez
*/

#include "server.h"

int	my_droite(__attribute__((unused)) char **com
		  , __attribute((unused)) t_zap *data
		  , t_user *usr)
{
  GET_DIR(usr) = S_MOD((int)(GET_DIR(usr) + 1), 4);
  fill_cb(&usr->wr, "ok\n", 3);
  return (0);
}
