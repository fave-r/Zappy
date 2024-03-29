/*
** my_droite.c for my_droite in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 17:48:35 2015 Thibaut Lopez
*/

#include "server.h"

int	my_droite(char **com, __attribute((unused)) t_zap *data
		  , t_user *usr)
{
  t_tv		now;
  char		tmp[100];

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  GET_DIR(usr) = smod((int)(GET_DIR(usr) + 1), 4);
  xfill_cb(usr, &usr->wr, "ok\n");
  xpush_q(usr, &usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  sprintf(tmp, "ppo %d %d %d %d\n", usr->nb,
	  GET_X(usr), GET_Y(usr), GET_DIR(usr) + 1);
  send_to_graphic(tmp, usr);
  return (0);
}
