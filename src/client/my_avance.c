/*
** my_avance.c for my_avance in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue May 19 18:02:48 2015 Thibaut Lopez
*/

#include "server.h"

int	my_avance(char **com, t_zap *data, t_user *usr)
{
  t_pair	pos;
  t_tv		now;
  char		tmp[100];

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  pos.f = GET_X(usr);
  pos.s = GET_Y(usr);
  gofo[GET_DIR(usr)](&pos, 1);
  GET_X(usr) = S_MOD(pos.f, data->length);
  GET_Y(usr) = S_MOD(pos.s, data->width);
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay));
  sprintf(tmp, "ppo #%d %d %d %d\n", GET_NB(usr),
	  GET_X(usr), GET_Y(usr), GET_DIR(usr) + 1);
  send_to_graphic(tmp, usr);
  return (0);
}
