/*
** my_sms.c for sms in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Sat Jul  4 20:28:10 2015 Thibaut Lopez
*/

#include "server.h"

int		map_resize(t_zap *data, int x, int y)
{
  int		i;
  t_content	**map;

  if ((map = malloc(y * sizeof(t_content *))) == NULL)
    return (-1);
  i = -1;
  while (++i < y)
    {
      if ((map[i] = malloc(x * sizeof(t_content))) == NULL)
	{
	  map_free(map, data->width);
	  map_free(data->map, data->width);
	  return (-1);
	}
      fill_cell(i, x, map, data);
      if (i < data->width)
	free(data->map[i]);
    }
  map_free(data->map, data->width);
  data->map = map;
  data->length = x;
  data->width = y;
  return (0);
}

void		sms_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  if ((map_resize(data, my_strtol(ask->args[0]),
		  my_strtol(ask->args[1]))) != 0)
    {
      ask->res = ANR;
      return ;
    }
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
  my_smg(usr, "Map successfuly resized");
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
  (void)data;
  my_smg(usr, "The map won't be resized");
}

int		my_sms(char **com, t_zap *data, t_user *usr)
{
  char		*str;
  t_ask		ask;
  int		val;

  if (sstrlen(com) != 3 || (val = my_strtol(com[1])) <= 0 ||
      (val = my_strtol(com[2])) <= 0)
    return (my_sbp(usr));
  if ((ask.args = sstrdup(com + 1)) == NULL)
    {
      usr->tokill = 1;
      return (0);
    }
  ask.ok = sms_ok;
  ask.changes = sms_data;
  ask.ko = sms_ko;
  find_ask(&ask, data->asking);
  if (count_type(usr, GRAPHIC) == 1 || data->wait == 1)
    gettimeofday(&ask.wait, NULL);
  xpush_q(usr, (t_que **)&usr->info, &ask, clone_ask);
  if (data->wait == 1)
    return (0);
  if ((str = flat_ask(com, usr->nb, q_len((t_que *)usr->info) - 1)) == NULL)
    return (0);
  str[0] = 'a';
  alert_graphic(str, usr);
  free(str);
  verbose_ask(usr, "map size editing", data);
  return (0);
}
