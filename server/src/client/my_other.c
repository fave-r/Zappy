/*
** my_other.c for my_other in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed Jul  1 19:19:22 2015 Thibaut Lopez
*/

#include "server.h"

void		send_new_player(t_user *usr)
{
  char		str[256];

  bzero(str, 256);
  sprintf(str, "pnw %d %d %d %d %d %s\n", usr->nb, GET_X(usr), // "pnw #%d %d %d %d %d %s\n"
	  GET_Y(usr), GET_DIR(usr) + 1, GET_LVL(usr), GET_TEAM(usr)->name);
  send_to_graphic(str, usr);
  bzero(str, 256);
  sprintf(str, "pin %d %d %d %d %d %d %d %d %d %d\n", usr->nb, GET_X(usr), // "pin #%d %d %d %d %d %d %d %d %d %d\n"
	  GET_Y(usr), GET_INV(usr).food, GET_INV(usr).linemate,
	  GET_INV(usr).deraumere, GET_INV(usr).sibur, GET_INV(usr).mendiane,
	  GET_INV(usr).phiras, GET_INV(usr).thystame);
  send_to_graphic(str, usr);
}

void		send_client_info(t_team *team, t_zap *data, t_user *usr)
{
  int		count;
  char		tmp[512];

  count = GET_TEAM(usr)->count;
  bzero(tmp, 512);
  sprintf(tmp, "%d\n%d %d\n",
	  count - count_in_team(team, usr), data->length, data->width);
  fill_cb(&usr->wr, tmp, strlen(tmp));
}

t_plr		*player_info(t_team *team, t_pair *pos)
{
  t_plr		*plr;

  plr = xmalloc(sizeof(t_plr));
  plr->team = team;
  plr->x = pos->f;
  plr->y = pos->s;
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

int		hatching_egg(t_pair *pos, t_user *usr, t_zap *data, t_team *cur)
{
  t_egg		*frt;
  char		tmp[16];
  int		nb;

  frt = front_q(cur->eggs);
  if (frt == NULL || data->count > count_in_team(cur, usr))
    {
      pos->f = rand() % data->length;
      pos->s = rand() % data->width;
      return (-1);
    }
  pos->f = frt->pos.f;
  pos->s = frt->pos.s;
  bzero(tmp, 16);
  nb = frt->nb;
  sprintf(tmp, "ebo %d\n", nb); // "ebo #%d\n"
  send_to_graphic(tmp, usr);
  push_q(&usr->queue, &frt->hatch, clone_tv);
  frt->son = find_nb(usr, AI);
  return (nb);
}

int		my_other(char **com, t_zap *data, t_user *usr)
{
  t_team	*cur;
  t_user	*tmp;
  t_pair	pos;
  int		is_hatching;

  cur = data->teams;
  while (cur != NULL && strcmp(cur->name, com[0]) != 0)
    cur = cur->next;
  if (cur == NULL || count_in_team(cur, usr) == cur->count)
    {
      dprintf(usr->fd, "ko\n");
      usr->tokill = 1;
      return (-1);
    }
  is_hatching = hatching_egg(&pos, usr, data, cur);
  usr->info = player_info(cur, &pos);
  usr->nb = find_nb(usr, AI);
  usr->type = AI;
  GET_GHOST(usr) = (is_hatching != -1) ? 1 : 0;
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  send_client_info(cur, data, usr);
  send_new_player(usr);
  return (0);
}
