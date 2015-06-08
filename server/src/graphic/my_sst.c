/*
** my_sst.c for my_sst in /home/lopez_t/Zappy/src/sst
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Mon May 25 18:15:32 2015 Thibaut Lopez
*/

#include "server.h"

int	my_sst(char **com, t_zap *data, t_user *usr)
{
  int		nb;

  if (sstrlen(com) != 2)
    return (my_sbp(usr));
  nb = my_strtol(com[1]);
  if (nb == -1 || nb == 0)
    return (my_sbp(usr));
  data->delay = nb;
  return (my_send_sgt(data, usr));
}
