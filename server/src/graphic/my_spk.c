/*
** my_spk.c for spk in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Sat Jul  4 17:58:39 2015 Thibaut Lopez
*/

#include "server.h"

void		spk_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  tmp = get_by_nb(*usr, my_strtol(ask->args[0]), AI);
  send_death(usr, &tmp, data);
}

void		spk_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  char		str[64];

  (void)data;
  bzero(str, 64);
  sprintf(str, "Player #%d successfuly killed", my_strtol(ask->args[0]));
  my_smg(usr, str);
}

void		spk_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  char		str[64];

  (void)data;
  bzero(str, 64);
  sprintf(str, "Player #%d will stay alive", my_strtol(ask->args[0]));
  my_smg(usr, str);
}

int		my_spk(char **com, t_zap *data, t_user *usr)
{
  int		val;
  char		*str;
  t_ask		ask;

  if (sstrlen(com) != 2 || (val = my_strtol(com[1])) == -1
      || get_by_nb(usr, val, AI) == NULL)
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = spk_ok;
  ask.changes = spk_data;
  ask.ko = spk_ko;
  find_ask(&ask, data->asking);
  if (count_type(usr, GRAPHIC) == 1 || data->wait == 1)
    gettimeofday(&ask.wait, NULL);
  xpush_q(usr, (t_que **)&usr->info, &ask, clone_ask);
  if (data->wait == 1)
    return (0);
  str = flat_ask(com, usr->nb, q_len((t_que *)usr->info) - 1);
  str[0] = 'a';
  alert_graphic(str, usr);
  free(str);
  verbose_ask(usr, "player killing", data);
  return (0);
}
