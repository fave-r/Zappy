/*
** my_tna.c for my_tna in /home/lopez_t/Zappy/src/tna
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Thu May 14 11:39:29 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_tna(t_zap *data, t_user *usr)
{
  int	i;

  i = 0;
  while (data->team[i] != NULL)
    {
      fill_cb(&usr->wr, "tna ", 4);
      fill_cb(&usr->wr, data->team[i], strlen(data->team[i]));
      fill_cb(&usr->wr, "\n", 1);
      i++;
    }
  return (0);
}

int	my_tna(char **com, t_zap *data, t_user *usr)
{
  (void)com;
  return (my_send_tna(data, usr));
}
