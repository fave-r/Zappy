/*
** my_sgt.c for my_sgt in /home/lopez_t/Zappy/src/sgt
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Mon May 25 18:14:37 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_sgt(t_zap *data, t_user *usr)
{
  char	tmp[25];

  bzero(tmp, 25);
  sprintf(tmp, "sgt %d\n", data->delay);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int	my_sgt(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) != 1)
    return (my_sbp(usr));
  return (my_send_sgt(data, usr));
}