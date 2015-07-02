/*
** inc_to_graphic.c for zappy in /home/fave_r/rendu/Zappy/src/client
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon May 25 17:31:52 2015 romaric
** Last update Wed Jul  1 21:30:41 2015 Thibaut Lopez
*/

#include "server.h"

void		send_inc_to_graph(t_user *usr, t_zap *data)
{
  char		tmp[100];
  t_content	*cnt;

  bzero(tmp, 100);
  cnt = &(data->map[GET_X(usr)][GET_Y(usr)]);
  sprintf(tmp, "bct %d %d %d %d %d %d %d %d %d\n", GET_X(usr), GET_Y(usr)
	  , cnt->food, cnt->linemate, cnt->deraumere
	  , cnt->sibur, cnt->mendiane, cnt->phiras
	  , cnt->thystame);
  send_to_graphic(tmp, usr);
}

void		cast_loop(t_user *cur, t_tv *time, int check, t_tv *now)
{
  char		tr[100];
  char		str[50];

  if (cmp_tv(&GET_CAST(cur), time) == 0)
    {
      GET_CAST(cur).tv_sec = 0;
      GET_CAST(cur).tv_usec = 0;
      if (check == 1)
	GET_LVL(cur)++;
      bzero(tr, 100);
      sprintf(tr, "plv %d %d\n", cur->nb, GET_LVL(cur));
      send_to_graphic(tr, cur);
      bzero(str, 50);
      sprintf(str, "niveau actuel : %d\n", GET_LVL(cur));
      fill_cb(&cur->wr, str, strlen(str));
      push_q(&cur->queue, now, clone_tv);
    }
}

void		send_elev_in(t_user *usr)
{
  t_user	*tmp;
  char		str[100];

  bzero(str, 100);
  tmp = usr;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  sprintf(str, "pic %d %d %d", GET_X(usr), GET_Y(usr), GET_LVL(usr));
  while ((tmp = in_this_cell(GET_X(usr), GET_Y(usr), tmp)) != NULL)
    {
      if (GET_LVL(usr) == GET_LVL(tmp) && !IS_CASTING(tmp))
	sprintf(str + strlen(str), " %d", tmp->nb);
      tmp = tmp->next;
    }
  sprintf(str + strlen(str), "\n");
  send_to_graphic(str, usr);
}
