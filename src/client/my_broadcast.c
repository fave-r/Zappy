/*
** my_broadcast.c for my_broadcast in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue May 26 18:37:50 2015 Thibaut Lopez
*/

#include "server.h"

t_pair		get_closest(t_user *src, t_user *dest, t_zap *data)
{
  int		i;
  t_pair	sign;
  t_pair	dirs[3];
  int		p[3];

  dirs[0].f = GET_X(dest) - GET_X(src);
  dirs[0].s = GET_Y(dest) - GET_Y(src);
  sign.f = (dirs[0].f < 0) ? 1 : -1;
  sign.s = (dirs[0].s < 0) ? 1 : -1;
  dirs[1].f = dirs[0].f;
  dirs[1].s = sign.s * (data->width - ABS(dirs[0].s));
  dirs[2].f = sign.f * (data->length - ABS(dirs[0].f));
  dirs[2].s = dirs[0].s;
  p[0] = ABS(dirs[0].f) + ABS(dirs[0].s);
  p[1] = ABS(dirs[1].f) + ABS(dirs[1].s);
  p[2] = ABS(dirs[2].f) + ABS(dirs[2].s);
  i = (p[0] < p[1]) ? (p[0] < p[2]) ? 0 : 2 : (p[1] < p[2]) ? 1 : 2;
  return (dirs[i]);
}

int		get_dir(t_pair dir, int *dirs)
{
  if (dir.f > 0 && dir.f == dir.s)
    return (dirs[7]);
  if (dir.f == dir.s)
    return (dirs[3]);
  if (dir.f < 0 && -dir.f == dir.s)
    return (dirs[1]);
  if (dir.f == -dir.s)
    return (dirs[5]);
  if (dir.f > 0 && dir.f > ABS(dir.s))
    return (dirs[6]);
  if (dir.f < 0 && ABS(dir.f) > ABS(dir.s))
    return (dirs[2]);
  if (dir.s > 0 && dir.s > ABS(dir.f))
    return (dirs[0]);
  return (dirs[4]);
}

int		get_direction(t_user *src, t_user *dest, t_zap *data)
{
  t_pair	dir;
  int		dirs[8];

  if (GET_X(src) == GET_X(dest) && GET_Y(src) == GET_Y(dest))
    return (0);
  dir = get_closest(src, dest, data);
  dirs[0] = GET_DIR(dest) * 2 + 1;
  dirs[1] = S_MOD(dirs[0] + 1, 4);
  dirs[2] = S_MOD(dirs[1] + 1, 4);
  dirs[3] = S_MOD(dirs[2] + 1, 4);
  dirs[4] = S_MOD(dirs[3] + 1, 4);
  dirs[5] = S_MOD(dirs[4] + 1, 4);
  dirs[6] = S_MOD(dirs[5] + 1, 4);
  dirs[7] = S_MOD(dirs[6] + 1, 4);
  return (get_dir(dir, dirs));
}

int		my_broadcast(char **com, t_zap *data, t_user *usr)
{
  char		str[100];
  t_tv		now;
  t_user	*tmp;

  if (sstrlen(com) != 2)
    return (-1);
  gettimeofday(&now, NULL);
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp != usr && tmp->type == AI)
	{
	  sprintf(str, "message %d,%s\n", get_direction(usr, tmp, data), com[1]);
	  fill_cb(&tmp->wr, str, strlen(str));
	  push_q(&tmp->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
	  add_tv(&now, -(7000000 / data->delay));
	}
      tmp = tmp->next;
    }
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  return (0);
}
