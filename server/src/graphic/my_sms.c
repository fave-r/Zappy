/*
** my_sms.c for sms in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Mon Jun  8 11:55:01 2015 Thibaut Lopez
*/

#include "server.h"

void		map_resize(t_zap *data, int x, int y)
{
  int		i;
  int		j;
  t_content	**map;

  map = xmalloc(y * sizeof(t_content *));
  i = -1;
  while (++i < y)
    {
      map[i] = xmalloc(x * sizeof(t_content));
      j = -1;
      while (++j < x)
	fill_cell(i, j, map, data);
      if (i < data->width)
	free(data->map[i]);
    }
  free(data->map);
  data->map = map;
  data->length = x;
  data->width = y;
}

void		sms_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  map_resize(data, my_strtol(ask->args[0]), my_strtol(ask->args[1]));
  tmp = *usr;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	{
	  GET_X(tmp) %= data->length;
	  GET_Y(tmp) %= data->width;
	}
      tmp = tmp->next;
    }
}

void		sms_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  t_user	*tmp;

  (void)ask;
  my_send_msz(data, usr);
  my_send_mct(data, usr);
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	my_send_ppo(usr, tmp);
      tmp = tmp->next;
    }
}

void		sms_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  (void)ask;
  (void)usr;
  (void)data;
}

int		my_sms(char **com, t_zap *data, t_user *usr)
{
  char		*str;
  t_ask		ask;
  int		val;

  if (sstrlen(com) != 3 || (val = my_strtol(com[1])) <= 0 ||
      (val = my_strtol(com[2])) <= 0)
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = sms_ok;
  ask.changes = sms_data;
  ask.ko = sms_ko;
  find_ask(&ask, data->asking);
  if (count_type(usr, GRAPHIC) == 1)
    gettimeofday(&ask.wait, NULL);
  push_q((t_que **)&usr->info, &ask, clone_ask);
  str = strflat(com, " ", usr->nb, q_len((t_que *)usr->info) - 1);
  str[0] = 'a';
  alert_graphic(str, usr);
  free(str);
  return (0);
}