/*
** my_bct.c for my_bct in /home/lopez_t/Zappy/src/bct
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Mon May 25 18:10:40 2015 Thibaut Lopez
*/

#include "server.h"

int		my_send_bct(t_zap *data, t_user *usr, int x, int y)
{
  t_content	cnt;
  char		tmp[150];

  cnt = data->map[x][y];
  bzero(tmp, 150);
  sprintf(tmp, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	  (int)cnt.food, (int)cnt.linemate, (int)cnt.deraumere,
	  (int)cnt.sibur, (int)cnt.mendiane, (int)cnt.phiras, (int)cnt.thystame);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int		my_bct(char **com, t_zap *data, t_user *usr)
{
  int	x;
  int	y;

  if (sstrlen(com) < 3)
    return (my_sbp(usr));
  if ((x = my_strtol(com[1])) < 0 || x >= data->length)
    return (my_sbp(usr));
  if ((y = my_strtol(com[2])) < 0 || y >= data->width)
    return (my_sbp(usr));
  return (my_send_bct(data, usr, x, y));
}
