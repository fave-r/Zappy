/*
** my_msz.c for my_msz in /home/lopez_t/Zappy/src/msz
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Mon May 25 18:11:39 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_msz(t_zap *data, t_user *usr)
{
  char	tmp[50];

  bzero(tmp, 50);
  sprintf(tmp, "msz %d %d\n", data->length, data->width);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int	my_msz(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) != 1)
    return (my_sbp(usr));
  return (my_send_msz(data, usr));
}
