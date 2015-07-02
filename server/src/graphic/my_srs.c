/*
** my_srs.c for srs in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Thu Jul  2 03:22:59 2015 Thibaut Lopez
*/

#include "server.h"

void		srs_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  (void)ask;
  my_reset_map(usr, data, ask);
  tmp = *usr;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	send_death(usr, &tmp, data);
      else
	tmp = tmp->next;
    }
}

void		srs_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  (void)ask;
  my_smg(usr, "The server is being reset: replacing ressources and kicking players");
  my_send_mct(data, usr);
}

void		srs_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  (void)ask;
  (void)data;
  my_smg(usr, "The server won't be reseted");
}

int		my_srs(char **com, t_zap *data, t_user *usr)
{
  char		*str;
  t_ask		ask;

  if (sstrlen(com) != 1)
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = srs_ok;
  ask.changes = srs_data;
  ask.ko = srs_ko;
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
