/*
** my_voir.c for my_voir in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed Jul  1 20:08:12 2015 Thibaut Lopez
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

void		loop_ressource(t_cb *wr, uint16_t goal, char *str_to_add)
{
  int		i;

  i = 0;
  while (i < goal)
    {
      fill_cb(wr, str_to_add, strlen(str_to_add));
      i++;
    }
}

void		analyse_cell(t_content **cnt, t_pair *cone, t_user *usr)
{
  t_user	*tmp;

  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while ((tmp = in_this_cell(cone->f, cone->s, tmp)) != NULL)
    {
      fill_cb(&usr->wr, " joueur", 7);
      tmp = tmp->next;
    }
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].food, " nourriture");
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].linemate, " linemate");
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].deraumere, " deraumere");
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].sibur, " sibur");
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].mendiane, " mendiane");
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].phiras, " phiras");
  loop_ressource(&usr->wr, cnt[cone->f][cone->s].thystame, " thystame");
}

void		vert_view(int i, t_user *usr, t_pair *cone, t_zap *data)
{
  int		j;

  gole[GET_DIR(usr)](cone, i);
  j = i;
  while (j != -i)
    {
      if (j != i)
	fill_cb(&usr->wr, ",", 1);
      cone->f = smod(cone->f, data->width);
      cone->s = smod(cone->s, data->length);
      analyse_cell(data->map, cone, usr);
      gole[GET_DIR(usr)](cone, -1);
      j--;
    }
  if (j != i)
    fill_cb(&usr->wr, ",", 1);
  cone->f = smod(cone->f, data->width);
  cone->s = smod(cone->s, data->length);
  analyse_cell(data->map, cone, usr);
  gole[GET_DIR(usr)](cone, i);
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
  while (i < GET_LVL(usr) + 1)
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
