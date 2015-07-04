/*
** my_plv.c for my_plv in /home/lopez_t/Zappy/src/plv
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Sat Jul  4 16:48:55 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_plv(t_user *usr, t_user *player)
{
  char	tmp[50];

  if (player == NULL)
    return (my_sbp(usr));
  bzero(tmp, 50);
  sprintf(tmp, "plv %d %d\n", player->nb, GET_LVL(player));
  xfill_cb(usr, &usr->wr, tmp);
  return (0);
}

int	my_plv(char **com, t_zap *data, t_user *usr)
{
  int		nb;
  t_user	*player;

  (void)data;
  if (sstrlen(com) != 2)
    return (my_sbp(usr));
  nb = my_strtol(com[1]);
  if (nb == -1)
    return (my_sbp(usr));
  player = usr;
  while (player != NULL && player->prev != NULL)
    player = player->prev;
  while (player != NULL)
    {
      if (player->type == AI && player->nb == nb)
	return (my_send_plv(usr, player));
      player = player->next;
    }
  return (0);
}
