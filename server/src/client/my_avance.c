/*
** my_avance.c for my_avance in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 17:05:14 2015 Thibaut Lopez
*/

#include "server.h"

int	my_avance(char **com, t_zap *data, t_user *usr)
{
  t_pair	pos;
  t_tv		now;
  char		tmp[256];

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  bzero(tmp, 256);
  if (check_nb_in_cell(1, usr) == 1)
    sprintf(tmp, "pie %d %d %d\n", GET_X(usr), GET_Y(usr), 0);
  pos.f = GET_X(usr);
  pos.s = GET_Y(usr);
  gofo[GET_DIR(usr)](&pos, 1);
  GET_X(usr) = smod(pos.f, data->width);
  GET_Y(usr) = smod(pos.s, data->length);
  xfill_cb(usr, &usr->wr, "ok\n");
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  sprintf(tmp + strlen(tmp), "ppo %d %d %d %d\n", usr->nb,
	  GET_X(usr), GET_Y(usr), GET_DIR(usr) + 1);
  send_to_graphic(tmp, usr);
  GET_CAST(usr).tv_usec = 0;
  GET_CAST(usr).tv_sec = 0;
  return (0);
}
