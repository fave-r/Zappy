/*
** my_sst.c for my_sst in /home/lopez_t/Zappy/src/sst
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Sat Jul  4 20:26:03 2015 Thibaut Lopez
*/

#include "server.h"

void		sst_data(t_user **usr, t_zap *data, t_ask *ask)
{
  (void)usr;
  data->delay = my_strtol(ask->args[0]);
}

void		sst_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  (void)ask;
  my_send_sgt(data, usr);
}

void		sst_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  (void)ask;
  my_send_sgt(data, usr);
}

int		my_sst(char **com, t_zap *data, t_user *usr)
{
  t_ask		ask;
  char		*str;

  if (sstrlen(com) != 2 || my_strtol(com[1]) <= 0)
    return (my_sbp(usr));
  if ((ask.args = sstrdup(com + 1)) == NULL)
    {
      usr->tokill = 1;
      return (0);
    }
  ask.ok = sst_ok;
  ask.changes = sst_data;
  ask.ko = sst_ko;
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
  verbose_ask(usr, "time delay editing", data);
  return (0);
}
