/*
** my_spp.c for spp in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Sat Jul  4 20:25:31 2015 Thibaut Lopez
*/

#include "server.h"

void		spp_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  (void)data;
  tmp = get_by_nb(*usr, my_strtol(ask->args[0]), AI);
  GET_X(tmp) = my_strtol(ask->args[1]);
  GET_Y(tmp) = my_strtol(ask->args[2]);
  GET_DIR(tmp) = my_strtol(ask->args[3]);
}

void		spp_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  t_user	*tmp;
  char		str[128];
  char		*dir;

  (void)data;
  tmp = get_by_nb(usr, my_strtol(ask->args[0]), AI);
  dir = (GET_DIR(tmp) == 0) ? "north" : (GET_DIR(tmp) == 1) ? "east" :
    (GET_DIR(tmp) == 2) ? "south" : "west";
  sprintf(str, "The player #%d has been moved: %dx%d, looking at %s",
	  tmp->nb, GET_X(tmp), GET_Y(tmp), dir);
  my_smg(usr, str);
  my_send_ppo(usr, tmp);
}

void		spp_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  char		str[64];

  (void)data;
  bzero(str, 64);
  sprintf(str, "The player #%d won't move", my_strtol(ask->args[0]));
  my_smg(usr, str);
}

int		my_spp(char **com, t_zap *data, t_user *usr)
{
  int		val;
  char		*str;
  t_ask		ask;

  if (sstrlen(com) != 5 || (val = my_strtol(com[1])) == -1 ||
      get_by_nb(usr, val, AI) == NULL || (val = my_strtol(com[2])) == -1 ||
      val >= data->length || (val = my_strtol(com[3])) == -1 ||
      val >= data->width || (val = my_strtol(com[4])) == -1 || val >= 4)
    return (my_sbp(usr));
  if ((ask.args = sstrdup(com + 1)) == NULL)
    {
      usr->tokill = 1;
      return (0);
    }
  ask.ok = spp_ok;
  ask.changes = spp_data;
  ask.ko = spp_ko;
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
  verbose_ask(usr, "player position and/or editing", data);
  return (0);
}
