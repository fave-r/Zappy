/*
** my_connect_nbr.c for my_connect_nbr in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 17:09:08 2015 Thibaut Lopez
*/

#include "server.h"

int	my_connect_nbr(char **com, t_zap *data, t_user *usr)
{
  t_tv	now;
  int	count;
  char	tmp[10];

  (void)data;
  gettimeofday(&now, NULL);
  if (sstrlen(com) != 1)
    return (-1);
  count = GET_TEAM(usr)->count;
  bzero(tmp, 10);
  sprintf(tmp, "%d\n", count - count_in_team(GET_TEAM(usr), usr));
  xfill_cb(usr, &usr->wr, tmp);
  push_q(&usr->queue, &now, clone_tv);
  return (0);
}
