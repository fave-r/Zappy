/*
** my_tna.c for my_tna in /home/lopez_t/Zappy/src/tna
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Sat Jul  4 16:58:18 2015 Thibaut Lopez
*/

#include "server.h"

int		my_send_tna(t_zap *data, t_user *usr)
{
  t_team	*cur;

  cur = data->teams;
  while (cur != NULL)
    {
      xfill_cb(usr, &usr->wr, "tna ");
      xfill_cb(usr, &usr->wr, cur->name);
      xfill_cb(usr, &usr->wr, "\n");
      cur = cur->next;
    }
  return (0);
}

int		my_tna(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) != 1)
    return (my_sbp(usr));
  return (my_send_tna(data, usr));
}
