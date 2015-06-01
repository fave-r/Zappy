/*
** my_agt.c for agt in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Fri May 29 17:36:42 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_agt(t_zap *data, t_user *usr)
{
  char	tmp[32];

  bzero(tmp, 32);
  sprintf(tmp, "agt %f\n", data->asking);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int	my_agt(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) != 1)
    return (my_sbp(usr));
  return (my_send_agt(data, usr));
}
