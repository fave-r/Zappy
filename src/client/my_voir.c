/*
** my_voir.c for my_voir in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue May 26 18:39:39 2015 Thibaut Lopez
*/

#include "server.h"

void		(*gofo[4])(t_pair *, int) =
{
  north_gofo,
  east_gofo,
  south_gofo,
  west_gofo
};

static void	(*gole[4])(t_pair *, int) =
{
  north_gole,
  east_gole,
  south_gole,
  west_gole
};

void		analyse_cell(t_content **cnt, t_pair *cone, t_user *usr)
{
  t_user	*tmp;

  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while ((tmp = in_this_cell(cone->f, cone->s, tmp)) != NULL)
    {
      fill_cb(&usr->wr, " player", 7);
      tmp = tmp->next;
    }
  if (cnt[cone->f][cone->s].food > 0)
    fill_cb(&usr->wr, " nourriture", 11);
  if (cnt[cone->f][cone->s].linemate > 0)
    fill_cb(&usr->wr, " linemate", 9);
  if (cnt[cone->f][cone->s].deraumere > 0)
    fill_cb(&usr->wr, " deraumere", 10);
  if (cnt[cone->f][cone->s].sibur > 0)
    fill_cb(&usr->wr, " sibur", 6);
  if (cnt[cone->f][cone->s].mendiane > 0)
    fill_cb(&usr->wr, " mendiane", 9);
  if (cnt[cone->f][cone->s].phiras > 0)
    fill_cb(&usr->wr, " phiras", 7);
  if (cnt[cone->f][cone->s].thystame > 0)
    fill_cb(&usr->wr, " thystame", 9);
}

void		vert_view(int i, t_user *usr, t_pair *cone, t_zap *data)
{
  int		j;

  gole[GET_DIR(usr)](cone, i);
  j = i;
  while (j != -i)
    {
      cone->f = S_MOD(cone->f, data->width);
      cone->s = S_MOD(cone->s, data->length);
      analyse_cell(data->map, cone, usr);
      gole[GET_DIR(usr)](cone, -1);
      j--;
    }
  cone->f = S_MOD(cone->f, data->width);
  cone->s = S_MOD(cone->s, data->length);
  analyse_cell(data->map, cone, usr);
  gole[GET_DIR(usr)](cone, -i);
}

int		my_voir(char **com, t_zap *data, t_user *usr)
{
  int		i;
  t_pair	cone;
  t_tv		now;

  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
  cone.f = GET_X(usr);
  cone.s = GET_Y(usr);
  fill_cb(&usr->wr, "{", 1);
  i = 0;
  while (i < GET_LVL(usr))
    {
      if (i > 0)
	fill_cb(&usr->wr, ",", 1);
      vert_view(i, usr, &cone, data);
      gofo[GET_DIR(usr)](&cone, 1);
      i++;
    }
  fill_cb(&usr->wr, "}\n", 2);
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  return (0);
}
