/*
** my_spi.c for spi in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Thu Jul  2 04:22:23 2015 Thibaut Lopez
*/

#include "server.h"

void		spi_data(t_user **usr, t_zap *data, t_ask *ask)
{
  t_user	*tmp;

  (void)data;
  tmp = get_by_nb(*usr, my_strtol(ask->args[0] + 1), AI);
  GET_INV(tmp).food = my_strtol(ask->args[3]);
  GET_INV(tmp).linemate = my_strtol(ask->args[4]);
  GET_INV(tmp).deraumere = my_strtol(ask->args[5]);
  GET_INV(tmp).sibur = my_strtol(ask->args[6]);
  GET_INV(tmp).mendiane = my_strtol(ask->args[7]);
  GET_INV(tmp).phiras = my_strtol(ask->args[8]);
  GET_INV(tmp).thystame = my_strtol(ask->args[9]);
}

void		spi_ok(t_ask *ask, t_user *usr, t_zap *data)
{
  t_user	*tmp;
  char		str[64];

  (void)data;
  tmp = get_by_nb(usr, my_strtol(ask->args[0] + 1), AI);
  bzero(str, 64);
  sprintf(str, "Inventory of player #%d changed", tmp->nb);
  my_smg(usr, str);
  my_send_pin(usr, tmp);
}

void		spi_ko(t_ask *ask, t_user *usr, t_zap *data)
{
  char		str[64];

  (void)data;
  bzero(str, 64);
  sprintf(str, "Inventory of player #%d will stay the same",
	  my_strtol(ask->args[0] + 1));
  my_smg(usr, str);
}

int		check_spi(char **com, t_zap *data, t_user *usr)
{
  int		val;

  return (sstrlen(com) != 11 || com[1][0] != '#' ||
	  (val = my_strtol(com[1] + 1)) == -1 ||
	  get_by_nb(usr, val, AI) == NULL ||
	  (val = my_strtol(com[2])) == -1 || val >= data->length ||
	  (val = my_strtol(com[3])) == -1 || val >= data->width ||
	  my_strtol(com[4]) == -1 || my_strtol(com[5]) == -1 ||
	  my_strtol(com[6]) == -1 || my_strtol(com[7]) == -1 ||
	  my_strtol(com[8]) == -1 || my_strtol(com[9]) == -1 ||
	  my_strtol(com[10]) == -1);
}

int		my_spi(char **com, t_zap *data, t_user *usr)
{
  char		*str;
  t_ask		ask;

  if (check_spi(com, data, usr))
    return (my_sbp(usr));
  ask.args = sstrdup(com + 1);
  ask.ok = spi_ok;
  ask.changes = spi_data;
  ask.ko = spi_ko;
  find_ask(&ask, data->asking);
  if (count_type(usr, GRAPHIC) == 1 || data->wait == 1)
    gettimeofday(&ask.wait, NULL);
  push_q((t_que **)&usr->info, &ask, clone_ask);
  if (data->wait == 1)
    return (0);
  str = flat_ask(com, usr->nb, q_len((t_que *)usr->info) - 1);
  str[0] = 'a';
  alert_graphic(str, usr);
  free(str);
  return (0);
}
