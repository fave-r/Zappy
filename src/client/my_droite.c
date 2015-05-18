/*
** my_droite.c for my_droite in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Mon May 18 13:09:54 2015 Thibaut Lopez
*/

#include "server.h"

int	my_droite(__attribute__((unused)) char **com
		  , __attribute((unused)) t_zap *data
		  , t_user *usr)
{
  t_tv		now;

  gettimeofday(&now, NULL);
  GET_DIR(usr) = S_MOD((int)(GET_DIR(usr) + 1), 4);
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay));
  return (0);
}
