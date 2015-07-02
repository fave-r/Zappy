/*
** my_sct.c for sct in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Thu Jul  2 03:23:25 2015 Thibaut Lopez
*/

#include "server.h"

void		sct_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_content	*cnt;

  (void)usr;
  cnt = &(data->map[my_strtol(ask->args[0])][my_strtol(ask->args[1])]);
  cnt->food = my_strtol(ask->args[2]);
  cnt->linemate = my_strtol(ask->args[3]);
  cnt->deraumere = my_strtol(ask->args[4]);
  cnt->sibur = my_strtol(ask->args[5]);
  cnt->mendiane = my_strtol(ask->args[6]);
  cnt->phiras = my_strtol(ask->args[7]);
  cnt->thystame = my_strtol(ask->args[8]);
}

void		sct_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  char		tmp[64];

  bzero(tmp, 64);
  sprintf(tmp, "Content of %dx%d cell successfully changed",
	  my_strtol(ask->args[0]), my_strtol(ask->args[1]));
  my_smg(usr, tmp);
  my_send_bct(data, usr, my_strtol(ask->args[0]), my_strtol(ask->args[1]));
}

void		sct_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  char		tmp[64];

  (void)data;
  bzero(tmp, 64);
  sprintf(tmp, "Editing of content of %dx%d cell refused",
	  my_strtol(ask->args[0]), my_strtol(ask->args[1]));
  my_smg(usr, tmp);
}

int		check_sct(char **com, t_zap *data)
{
  int		val;

  return (sstrlen(com) != 10 ||
	  (val = my_strtol(com[1])) == -1 || val >= data->length ||
	  (val = my_strtol(com[2])) == -1 || val >= data->width ||
	  my_strtol(com[3]) == -1 || my_strtol(com[4]) == -1 ||
	  my_strtol(com[5]) == -1 || my_strtol(com[6]) == -1 ||
	  my_strtol(com[7]) == -1 || my_strtol(com[8]) == -1 ||
	  my_strtol(com[9]) == -1);
}

int		my_sct(char **com, t_zap *data, t_user *usr)
{
  char		*str;
  t_ask		ask;

  if (check_sct(com, data))
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = sct_ok;
  ask.changes = sct_data;
  ask.ko = sct_ko;
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
