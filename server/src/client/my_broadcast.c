/*
** my_broadcast.c for my_broadcast in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 10:56:57 2015 Thibaut Lopez
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
  dirs[1].s = sign.s * (data->length - ABS(dirs[0].s));
  dirs[2].f = sign.f * (data->width - ABS(dirs[0].f));
  dirs[2].s = dirs[0].s;
  p[0] = ABS(dirs[0].f) + ABS(dirs[0].s);
  p[1] = ABS(dirs[1].f) + ABS(dirs[1].s);
  p[2] = ABS(dirs[2].f) + ABS(dirs[2].s);
  i = (p[0] < p[1]) ? (p[0] < p[2]) ? 0 : 2 : (p[1] < p[2]) ? 1 : 2;
  return (dirs[i]);
}

int		get_dir(t_pair dir, int *dirs)
{
  if (dir.f < 0 && dir.s < 0 && dir.f == dir.s)
    return (dirs[5]);
  else if (dir.f > 0 && dir.s > 0 && dir.f == dir.s)
    return (dirs[1]);
  else if (dir.f < 0 && dir.s > 0 && ABS(dir.f) == ABS(dir.s))
    return (dirs[7]);
  else if (dir.f > 0 && dir.s < 0 && ABS(dir.f) == ABS(dir.s))
    return (dirs[3]);
  else if (dir.s < 0 && ABS(dir.f) < ABS(dir.s))
    return (dirs[4]);
  else if (dir.s > 0 && ABS(dir.f) < ABS(dir.s))
    return (dirs[0]);
  else if (dir.f < 0 && ABS(dir.s) < ABS(dir.f))
    return (dirs[6]);
  else if (dir.f > 0 && ABS(dir.s) < ABS(dir.f))
    return (dirs[2]);
  dprintf(2, "WTF ?! %d%d\n", dir.f, dir.s);
  exit(1);
  return (0);
}

int		get_direction(t_user *src, t_user *dest, t_zap *data)
{
  t_pair	dir;
  int		dirs[8];

  if (GET_X(src) == GET_X(dest) && GET_Y(src) == GET_Y(dest))
    return (0);
  dir = get_closest(src, dest, data);
  dirs[0] = GET_DIR(dest) * 2 + 1;
  dirs[1] = smod(dirs[0], 8) + 1;
  dirs[2] = smod(dirs[1], 8) + 1;
  dirs[3] = smod(dirs[2], 8) + 1;
  dirs[4] = smod(dirs[3], 8) + 1;
  dirs[5] = smod(dirs[4], 8) + 1;
  dirs[6] = smod(dirs[5], 8) + 1;
  dirs[7] = smod(dirs[6], 8) + 1;
  return (get_dir(dir, dirs));
}

void		broadcast_graphic(t_user *usr, char *msg)
{
  char		*tmp;

  tmp = xmalloc((16 + strlen(msg)) * sizeof(char));
  bzero(tmp, 16 + strlen(msg));
  sprintf(tmp, "pbc %d %s\n", usr->nb, msg);
  send_to_graphic(tmp, usr);
  free(tmp);
}

int		my_broadcast(char **com, t_zap *data, t_user *usr)
{
  char		str[100];
  t_tv		now;
  t_user	*tmp;

  if (sstrlen(com) != 2)
    return (-1);
  gettimeofday(&now, NULL);
  add_tv(&now, 7000000 / data->delay);
  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp != usr && tmp->type == AI && GET_GHOST(tmp) == 0)
	{
	  sprintf(str, "message %d,%s\n", get_direction(usr, tmp, data), com[1]);
	  fill_cb(&tmp->wr, str, strlen(str));
	  push_q(&tmp->queue, &now, clone_tv);
	}
      tmp = tmp->next;
    }
  fill_cb(&usr->wr, "ok\n", 3);
  push_q(&usr->queue, &now, clone_tv);
  broadcast_graphic(usr, com[1]);
  return (0);
}
