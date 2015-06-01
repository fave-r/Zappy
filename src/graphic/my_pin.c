/*
** my_pin.c for my_pin in /home/lopez_t/Zappy/src/pin
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Fri May 29 14:10:44 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_pin(t_user *usr, t_user *player)
{
  char	tmp[100];

  if (player == NULL)
    return (my_sbp(usr));
  bzero(tmp, 100);
  sprintf(tmp, "pin #%d %d %d %d %d %d %d %d %d %d\n",
	  player->nb, GET_X(player), GET_Y(player),
	  GET_INV(player).food, GET_INV(player).linemate,
	  GET_INV(player).deraumere, GET_INV(player).sibur,
	  GET_INV(player).mendiane, GET_INV(player).phiras,
	  GET_INV(player).thystame);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int	my_pin(char **com, t_zap *data, t_user *usr)
{
  int		nb;
  t_user	*player;

  (void)data;
  if (sstrlen(com) != 2 || com[1][0] != '#')
    return (my_sbp(usr));
  nb = my_strtol(com[1] + 1);
  if (nb == -1)
    return (my_sbp(usr));
  player = usr;
  while (player != NULL && player->prev != NULL)
    player = player->prev;
  while (player != NULL)
    {
      if (player->type == AI && player->nb == nb)
	return (my_send_pin(usr, player));
      player = player->next;
    }
  return (0);
}
