/*
** my_avance.c for my_avance in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Mon May 18 13:07:53 2015 Thibaut Lopez
*/

#include "server.h"

int	my_avance(__attribute__((unused))char **com,
		  t_zap *data, t_user *usr)
{
  t_pair	pos;
  t_tv		now;

  gettimeofday(&now, NULL);
  pos.f = GET_X(usr);
  pos.s = GET_Y(usr);
  gofo[GET_DIR(usr)](&pos, 1);
  GET_X(usr) = S_MOD(pos.f, data->length);
  GET_Y(usr) = S_MOD(pos.s, data->width);
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay));
  return (0);
}
