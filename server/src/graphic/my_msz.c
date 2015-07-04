/*
** my_msz.c for my_msz in /home/lopez_t/Zappy/src/msz
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Sat Jul  4 16:57:21 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_msz(t_zap *data, t_user *usr)
{
  char	tmp[50];

  bzero(tmp, 50);
  sprintf(tmp, "msz %d %d\n", data->width, data->length);
  xfill_cb(usr, &usr->wr, tmp);
  return (0);
}

int	my_msz(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) != 1)
    return (my_sbp(usr));
  return (my_send_msz(data, usr));
}
