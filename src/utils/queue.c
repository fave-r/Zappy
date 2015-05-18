/*
** queue.c for queue in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 15 14:41:50 2015 Thibaut Lopez
** Last update Mon May 18 13:04:03 2015 Thibaut Lopez
*/

#include "utils.h"

void	push_q(t_que **q, t_tv *tv)
{
  t_que	*new;
  t_que	*tmp;

  new = xmalloc(sizeof(t_que));
  new->e = *tv;
  new->next = NULL;
  tmp = *q;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp != NULL)
    tmp->next = new;
  else
    *q = new;
}

void	pop_q(t_que **q)
{
  t_que	*tmp;

  tmp = *q;
  if (*q != NULL)
    *q = (*q)->next;
  if (tmp != NULL)
    free(tmp);
}

t_tv	*front_q(t_que *q)
{
  if (q == NULL)
    return (NULL);
  return (&q->e);
}

t_tv	*add_tv(t_tv *tv, int to_add)
{
  tv->tv_usec += to_add % 1000000;
  tv->tv_sec += to_add / 1000000;
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
