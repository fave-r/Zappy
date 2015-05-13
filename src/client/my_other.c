/*
** my_other.c for my_other in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Thu May 14 01:17:00 2015 Thibaut Lopez
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

int	my_other(char **com, t_zap *data, t_user *usr)
{
  int	i;

  i = 0;
  if (usr->team != NULL)
    return (0);
  while (data->team[i] != NULL && strcmp(data->team[i], com[0]) != 0)
    i++;
  if (data->team[i] == NULL ||
      count_in_team(data->team[i], usr) == data->count)
    return (0);
  usr->team = data->team[i];
  usr->x = rand() % data->length;
  usr->y = rand() % data->width;
  usr->dir = rand() % 4; 
  usr->inv.food = 10;
  usr->inv.linemate = 0;
  usr->inv.deraumere = 0;
  usr->inv.sibur = 0;
  usr->inv.mendiane = 0;
  usr->inv.phiras = 0;
  usr->inv.thystame = 0;
  usr->level = 1;
  usr->type = AI;
  send_client_info(data->team[i], data, usr);
  return (0);
}
