/*
** my_connect_nbr.c for my_connect_nbr in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue May 26 18:11:25 2015 Thibaut Lopez
*/

#include "server.h"

int	my_connect_nbr(char **com, t_zap *data, t_user *usr)
{
  int	count;
  char	tmp[10];

  (void)data;
  if (sstrlen(com) != 1)
    return (-1);
  count = GET_TEAM(usr)->count;
  bzero(tmp, 10);
  sprintf(tmp, "%d\n", count - count_in_team(GET_TEAM(usr), usr));
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}
