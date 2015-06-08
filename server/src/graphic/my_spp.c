/*
** my_spp.c for spp in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Mon Jun  8 17:43:04 2015 Thibaut Lopez
*/

#include "server.h"

void		spp_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  (void)data;
  tmp = get_by_nb(*usr, my_strtol(ask->args[0] + 1), AI);
  GET_X(tmp) = my_strtol(ask->args[1]);
  GET_Y(tmp) = my_strtol(ask->args[2]);
  GET_DIR(tmp) = my_strtol(ask->args[3]);
}

void		spp_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  t_user	*tmp;

  (void)data;
  tmp = get_by_nb(usr, my_strtol(ask->args[0] + 1), AI);
  my_send_ppo(usr, tmp);
}

void		spp_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  (void)ask;
  (void)usr;
  (void)data;
}

int		my_spp(char **com, t_zap *data, t_user *usr)
{
  int		val;
  char		*str;
  t_ask		ask;

  if (sstrlen(com) != 5 || com[1][0] != '#' ||
      (val = my_strtol(com[1] + 1)) == -1 || get_by_nb(usr, val, AI) == NULL ||
      (val = my_strtol(com[2])) == -1 || val >= data->length ||
      (val = my_strtol(com[3])) == -1 || val >= data->width ||
      (val = my_strtol(com[4])) == -1 || val >= 4)
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = spp_ok;
  ask.changes = spp_data;
  ask.ko = spp_ko;
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
