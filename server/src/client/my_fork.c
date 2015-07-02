/*
** my_fork.c for my_fork in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed Jul  1 21:29:30 2015 Thibaut Lopez
*/

#include "server.h"

int	my_fork(char **com, t_zap *data, t_user *usr)
{
  char	tmp[16];
  t_tv	now;
  t_egg	egg;

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  egg.nb = find_egg_nb(data->teams);
  egg.dad = usr->nb;
  egg.son = -1;
  bzero(tmp, 16);
  sprintf(tmp, "pfk %d\n", usr->nb);
  send_to_graphic(tmp, usr);
  add_tv(&now, 42000000 / data->delay);
  egg.lay.tv_sec = now.tv_sec;
  egg.lay.tv_usec = now.tv_usec;
  egg.pos.f = GET_X(usr);
  egg.pos.s = GET_Y(usr);
  egg.hatch.tv_sec = now.tv_sec;
  egg.hatch.tv_usec = now.tv_usec;
  add_tv(&egg.hatch, 600000000 / data->delay);
  push_q(&GET_TEAM(usr)->eggs, &egg, clone_egg);
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, &now, clone_tv);
  return (0);
}
