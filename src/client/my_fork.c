/*
** my_fork.c for my_fork in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed May 27 17:38:30 2015 Thibaut Lopez
*/

#include "server.h"

int	my_fork(char **com, t_zap *data, t_user *usr)
{
  t_tv	now;
  t_egg	egg;

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  add_tv(&now, 42000000 / data->delay);
  egg.pos.f = GET_X(usr);
  egg.pos.s = GET_Y(usr);
  egg.hatch.tv_sec = now.tv_sec;
  egg.hatch.tv_usec = now.tv_usec;
  add_tv(&egg.hatch, 600000000 / data->delay);
  push_q(&GET_TEAM(usr)->eggs, &egg, clone_egg);
  GET_TEAM(usr)->count++;
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, &now, clone_tv);
  return (0);
}
