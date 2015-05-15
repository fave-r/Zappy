/*
** my_other.c for my_other in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Fri May 15 14:19:24 2015 Thibaut Lopez
*/

#include "server.h"

void	send_client_info(char *team, t_zap *data, t_user *usr)
{
  char	tmp[512];

  bzero(tmp, 512);
  sprintf(tmp, "%d\n%d %d\n",
	  data->count - count_in_team(team, usr), data->length, data->width);
  fill_cb(&usr->wr, tmp, strlen(tmp));
}

t_plr	*player_info(char *team, int length, int width)
{
  t_plr	*plr;

  plr = xmalloc(sizeof(t_plr));
  plr->team = team;
  plr->x = rand() % length;
  plr->y = rand() % width;
  plr->dir = rand() % 4;
  plr->inv.food = 10;
  plr->inv.linemate = 0;
  plr->inv.deraumere = 0;
  plr->inv.sibur = 0;
  plr->inv.mendiane = 0;
  plr->inv.phiras = 0;
  plr->inv.thystame = 0;
  plr->level = 1;
  gettimeofday(&plr->time, NULL);
  return (plr);
}

int	my_other(char **com, t_zap *data, t_user *usr)
{
  int	i;

  i = 0;
  while (data->team[i] != NULL && strcmp(data->team[i], com[0]) != 0)
    i++;
  if (data->team[i] == NULL ||
      count_in_team(data->team[i], usr) == data->count)
    return (0);
  usr->plr = player_info(data->team[i], data->length, data->width);
  usr->type = AI;
  send_client_info(data->team[i], data, usr);
  return (0);
}
