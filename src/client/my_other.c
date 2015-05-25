/*
** my_other.c for my_other in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Mon May 25 14:10:49 2015 Thibaut Lopez
*/

#include "server.h"

void		send_client_info(char *team, t_zap *data, t_user *usr)
{
  char		tmp[512];

  bzero(tmp, 512);
  sprintf(tmp, "%d\n%d %d\n",
	  data->count - count_in_team(team, usr), data->length, data->width);
  fill_cb(&usr->wr, tmp, strlen(tmp));
}

t_plr		*player_info(char *team, int length, int width)
{
  t_plr		*plr;

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
  plr->cast.tv_sec = 0;
  plr->cast.tv_usec = 0;
  return (plr);
}

int		my_other(char **com, t_zap *data, t_user *usr)
{
  int		i;
  char		str[256];
  t_user	*tmp;

  i = 0;
  while (data->team[i] != NULL && strcmp(data->team[i], com[0]) != 0)
    i++;
  if (data->team[i] == NULL ||
      count_in_team(data->team[i], usr) == data->count)
    return (-1);
  usr->plr = player_info(data->team[i], data->length, data->width);
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  GET_NB(usr) = find_nb(tmp);
  usr->type = AI;
  send_client_info(data->team[i], data, usr);
  sprintf(str, "pnw #%d %d %d %d %d %s\n", GET_NB(usr),
	  GET_X(usr), GET_Y(usr), GET_DIR(usr) + 1, GET_LVL(usr), GET_TEAM(usr));
  send_to_graphic(str, usr, NULL);
  return (0);
}
