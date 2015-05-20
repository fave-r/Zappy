/*
** my_plv.c for my_plv in /home/lopez_t/Zappy/src/plv
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Wed May 20 16:26:41 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_plv(t_user *usr, t_user *player)
{
  char	tmp[50];

  if (player == NULL)
    return (0);
  bzero(tmp, 50);
  sprintf(tmp, "plv #%d %d\n", GET_NB(player), GET_LVL(player));
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int	my_plv(char **com, t_zap *data, t_user *usr)
{
  int		nb;
  t_user	*player;

  (void)data;
  if (sstrlen(com) != 2 || com[1][0] != '#')
    return (0);
  nb = my_strtol(com[1] + 1);
  if (nb == -1)
    return (0);
  player = usr;
  while (player != NULL && player->prev != NULL)
    player = player->prev;
  while (player != NULL)
    {
      if (player->type == AI && GET_NB(player) == nb)
	return (my_send_plv(usr, player));
      player = player->next;
    }
  return (0);
}
