/*
** my_spl.c for spl in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Thu Jul  2 03:32:46 2015 Thibaut Lopez
*/

#include "server.h"

void		spl_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;
  int		check;
  t_tv		now;
  char		str[50];

  tmp = get_by_nb(*usr, my_strtol(ask->args[0] + 1), AI);
  GET_LVL(tmp) = my_strtol(ask->args[1]);
  if (IS_CASTING(tmp))
    {
      GET_CAST(tmp).tv_sec = 0;
      GET_CAST(tmp).tv_usec = 0;
    }
  bzero(str, 50);
  sprintf(str, "niveau actuel : %d\n", GET_LVL(tmp));
  fill_cb(&tmp->wr, str, strlen(str));
  check = team_winning(tmp, GET_TEAM(tmp));
  if (check == 1)
    {
      gettimeofday(&now, NULL);
      push_q(&data->end, &now, clone_tv);
      data->winner = GET_TEAM(tmp);
    }
}

void		spl_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  t_user	*tmp;
  char		str[64];

  (void)data;
  tmp = get_by_nb(usr, my_strtol(ask->args[0] + 1), AI);
  bzero(str, 64);
  sprintf(str, "Player #%d is now level %d", tmp->nb, GET_LVL(tmp));
  my_smg(usr, str);
  my_send_plv(usr, tmp);
}

void		spl_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  char		str[64];

  (void)data;
  bzero(str, 64);
  sprintf(str, "Player #%d won't level up by the asking",
	  my_strtol(ask->args[0] + 1));
  my_smg(usr, str);
}

int		my_spl(char **com, t_zap *data, t_user *usr)
{
  int		val;
  char		*str;
  t_ask		ask;

  if (sstrlen(com) != 3 || com[1][0] != '#' ||
      (val = my_strtol(com[1] + 1)) == -1 || get_by_nb(usr, val, AI) == NULL ||
      (val = my_strtol(com[2])) <= 0 || val > 8)
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = spl_ok;
  ask.changes = spl_data;
  ask.ko = spl_ko;
  find_ask(&ask, data->asking);
  if (count_type(usr, GRAPHIC) == 1)
    gettimeofday(&ask.wait, NULL);
  push_q((t_que **)&usr->info, &ask, clone_ask);
  str = flat_ask(com, usr->nb, q_len((t_que *)usr->info) - 1);
  str[0] = 'a';
  alert_graphic(str, usr);
  free(str);
  return (0);
}
