/*
** my_expulse.c for my_expulse in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 10:53:08 2015 Thibaut Lopez
*/

#include "server.h"

int	send_expulse(int *bool, t_user *usr, t_user *tmp)
{
  char          str[256];

  if (++(*bool) == 1)
    {
      bzero(str, 128);
      sprintf(str, "pex %d\n", usr->nb);
      send_to_graphic(str, usr);
    }
  bzero(str, 256);
  sprintf(str, "ppo %d %d %d %d\n", tmp->nb,
          GET_X(tmp), GET_Y(tmp), GET_DIR(tmp) + 1);
  GET_CAST(tmp).tv_usec = 0;
  GET_CAST(tmp).tv_sec = 0;
  send_to_graphic(str, usr);
  return (0);
}

int     my_go(t_zap *data, t_user *tmp, t_user *usr)
{
  t_pair        pos;
  char          str[128];

  if (check_nb_in_cell(1, tmp) == 1)
    {
      bzero(str, 128);
      sprintf(str, "pie %d %d %d\n", GET_X(tmp), GET_Y(tmp), 0);
      send_to_graphic(str, tmp);
    }
  pos.f = GET_X(tmp);
  pos.s = GET_Y(tmp);
  gofo[GET_DIR(usr)](&pos, 1);
  GET_X(tmp) = smod(pos.f, data->width);
  GET_Y(tmp) = smod(pos.s, data->length);
  bzero(str, 128);
  sprintf(str, "deplacement: %d\n", get_direction(usr, tmp, data));
  fill_cb(&tmp->wr, str, strlen(str));
  return (0);
}

int		my_expulse(char **com, t_zap *data, t_user *usr)
{
  t_user	*tmp;
  t_tv		now;
  int		bool;

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  bool = 0;
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->next;
  add_tv(&now, 7000000 / data->delay);
  while ((tmp = in_this_cell(GET_X(usr), GET_Y(usr), tmp)) != NULL)
    {
      if (tmp != usr)
	{
	  my_go(data, tmp, usr);
	  send_expulse(&bool, usr, tmp);
	  push_q(&tmp->queue, &now, clone_tv);
	}
    }
  fill_cb(&usr->wr, (bool == 0) ? "ko\n" : "ok\n", 3);
  push_q(&usr->queue, &now, clone_tv);
  return (0);
}
