/*
** my_expulse.c for my_expulse in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue May 19 16:32:28 2015 Thibaut Lopez
*/

#include "server.h"

int     my_go(t_zap *data, t_user *tmp, t_user *usr, int *bool)
{
  t_pair        pos;
  char          str[100];

  if (++(*bool) == 1)
    {
      bzero(str, 20);
      sprintf(str, "pex #%d\n", GET_NB(usr));
      fill_cb(&usr->wr, str, strlen(str));
    }
  pos.f = GET_X(tmp);
  pos.s = GET_Y(tmp);
  gofo[GET_DIR(usr)](&pos, 1);
  GET_X(tmp) = S_MOD(pos.f, data->length);
  GET_Y(tmp) = S_MOD(pos.s, data->width);
  sprintf(str, "ppo #%d %d %d %d\n", GET_NB(tmp),
          GET_X(tmp), GET_Y(tmp), GET_DIR(tmp));
  send_to_graphic(str, usr);
  bzero(str, 20);
  sprintf(str, "deplacement: %d\n", get_direction(usr, tmp, data));
  fill_cb(&tmp->wr, str, strlen(str));
  return (0);
}

int		my_expulse(__attribute__((unused)) char **com,
			   t_zap *data, t_user *usr)
{
  t_user	*tmp;
  t_tv		now;
  int		bool;

  gettimeofday(&now, NULL);
  bool = 0;
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->next;
  while ((tmp = in_this_cell(GET_X(usr), GET_Y(usr), tmp)) != NULL)
    {
      if (tmp != usr)
	{
	  my_go(data, tmp, usr, &bool);
	  push_q(&tmp->queue, add_tv(&now, 7000000 / data->delay));
	  add_tv(&now, -(7000000 / data->delay));
	}
    }
  fill_cb(&usr->wr, (bool == 0) ? "ko\n" : "ok\n", 3);
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay));
  return (0);
}
