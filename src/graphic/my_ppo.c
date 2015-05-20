/*
** my_ppo.c for my_ppo in /home/lopez_t/Zappy/src/ppo
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Wed May 20 16:17:43 2015 Thibaut Lopez
*/

#include "server.h"

int	my_send_ppo(t_user *usr, t_user *player)
{
  char	tmp[50];

  if (player == NULL)
    return (0);
  bzero(tmp, 50);
  sprintf(tmp, "ppo #%d %d %d %d\n", GET_NB(player),
	  GET_X(player), GET_Y(player), GET_DIR(player) + 1);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}

int	my_ppo(char **com, t_zap *data, t_user *usr)
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
	return (my_send_ppo(usr, player));
      player = player->next;
    }
  return (0);
}
