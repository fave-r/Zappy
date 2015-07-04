/*
** my_voir.c for my_voir in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 17:04:24 2015 Thibaut Lopez
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

void		loop_ressource(t_user *usr, uint16_t goal, char *str_to_add)
{
  int		i;

  i = 0;
  while (i < goal)
    {
      xfill_cb(usr, &usr->wr, str_to_add);
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
      xfill_cb(usr, &usr->wr, " joueur");
      tmp = tmp->next;
    }
  loop_ressource(usr, cnt[cone->f][cone->s].food, " nourriture");
  loop_ressource(usr, cnt[cone->f][cone->s].linemate, " linemate");
  loop_ressource(usr, cnt[cone->f][cone->s].deraumere, " deraumere");
  loop_ressource(usr, cnt[cone->f][cone->s].sibur, " sibur");
  loop_ressource(usr, cnt[cone->f][cone->s].mendiane, " mendiane");
  loop_ressource(usr, cnt[cone->f][cone->s].phiras, " phiras");
  loop_ressource(usr, cnt[cone->f][cone->s].thystame, " thystame");
}

void		vert_view(int i, t_user *usr, t_pair *cone, t_zap *data)
{
  int		j;

  gole[GET_DIR(usr)](cone, i);
  j = i;
  while (j != -i)
    {
      if (j != i)
	xfill_cb(usr, &usr->wr, ",");
      cone->f = smod(cone->f, data->width);
      cone->s = smod(cone->s, data->length);
      analyse_cell(data->map, cone, usr);
      gole[GET_DIR(usr)](cone, -1);
      j--;
    }
  if (j != i)
    xfill_cb(usr, &usr->wr, ",");
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
  xfill_cb(usr, &usr->wr, "{");
  i = 0;
  while (i < GET_LVL(usr) + 1)
    {
      if (i > 0)
	xfill_cb(usr, &usr->wr, ",");
      vert_view(i, usr, &cone, data);
      gofo[GET_DIR(usr)](&cone, 1);
      i++;
    }
  xfill_cb(usr, &usr->wr, "}\n");
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  return (0);
}
