/*
** tv.c for tv in /home/lopez_t/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 26 18:31:09 2015 Thibaut Lopez
** Last update Mon Jun 29 17:46:13 2015 Thibaut Lopez
*/

#include "utils.h"

void	*clone_tv(void *to_clone)
{
  t_tv	*tv;
  t_tv	*new;

  tv = (t_tv *)to_clone;
  new = xmalloc(sizeof(t_tv));
  new->tv_sec = tv->tv_sec;
  new->tv_usec = tv->tv_usec;
  return ((void *)new);
}

t_tv	*add_tv(t_tv *tv, int to_add)
{
  int	sign;

  sign = (to_add < 0) ? -1 : 1;
  tv->tv_usec += (ABS(to_add) % 1000000) * sign;
  tv->tv_sec += to_add / 1000000;
  if (tv->tv_usec < 0)
    {
      tv->tv_usec += 1000000;
      tv->tv_sec--;
    }
  else if (tv->tv_usec > 1000000)
    {
      tv->tv_usec -= 1000000;
      tv->tv_sec++;
    }
  return (tv);
}

int	cmp_tv(t_tv *t1, t_tv *t2)
{
  if (t1 == NULL && t2 == NULL)
    return (0);
  if (t1 == NULL)
    return (-1);
  if (t2 == NULL)
    return (1);
  if (t1->tv_sec < t2->tv_sec)
    return (-1);
  if (t1->tv_sec > t2->tv_sec)
    return (1);
  if (t1->tv_usec < t2->tv_usec)
    return (-1);
  if (t1->tv_usec > t2->tv_usec)
    return (1);
  return (0);
}
