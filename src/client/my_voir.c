/*
** my_voir.c for my_voir in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed May 13 14:10:13 2015 Thibaut Lopez
*/

#include "server.h"

t_pair		*get_cone(t_user *usr)
{
  t_pair	*cone;
  void		(*ptr[4])(t_pair *, t_user *) =
    {
      north_cone,
      east_cone,
      south_cone,
      west_cone
    };

  cone = xmalloc(16 * sizeof(t_pair));
  ptr[usr->dir](cone, usr);
  return (cone);
}

void		analyse_cell(t_content *cnt, t_cb *wr)
{
  if (cnt->food > 0)
    fill_cb(wr, " nourriture", 11);
  if (cnt->linemate > 0)
    fill_cb(wr, " linemate", 9);
  if (cnt->deraumere > 0)
    fill_cb(wr, " deraumere", 10);
  if (cnt->sibur > 0)
    fill_cb(wr, " sibur", 6);
  if (cnt->mendiane > 0)
    fill_cb(wr, " mendiane", 9);
  if (cnt->phiras > 0)
    fill_cb(wr, " phiras", 7);
  if (cnt->thystame > 0)
    fill_cb(wr, " thystame", 8);
}

int		my_voir(char **com, t_zap *data, t_user *usr)
{
  int		i;
  t_pair	*cone;

  (void)com;
  (void)data;
  cone = get_cone(usr);
  i = 0;
  fill_cb(&usr->wr, "{", 1);
  while (i < 16)
    {
      cone[i].f = S_MOD(cone[i].f, data->width);
      cone[i].s = S_MOD(cone[i].s, data->length);
      if (i > 0)
	fill_cb(&usr->wr, ",", 1);
      if (in_this_cell(cone[i].f, cone[i].s, usr) != NULL)
	fill_cb(&usr->wr, " player", 1);
      analyse_cell(&(data->map[cone[i].f][cone[i].s]), &usr->wr);
      i++;
    }
  fill_cb(&usr->wr, "}\n", 2);
  free(cone);
  return (0);
}
