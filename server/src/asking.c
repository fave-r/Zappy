/*
** asking.c for asking in /home/lopez_t/BONUS/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 28 13:49:58 2015 Thibaut Lopez
** Last update Thu Jul  2 05:08:08 2015 Thibaut Lopez
*/

#include "server.h"

void		alert_graphic(char *com, t_user *usr)
{
  t_user	*cur;

  cur = usr;
  while (cur != NULL && cur->prev != NULL)
    cur = cur->prev;
  while (cur != NULL)
    {
      if (cur->type == GRAPHIC && cur != usr)
	fill_cb(&cur->wr, com, strlen(com));
      cur = cur->next;
    }
}

void		find_ask(t_ask *ask, float asking)
{
  time_t	sec;
  suseconds_t	usec;

  sec = floorf(asking);
  usec = (asking - sec) * 1000000;
  gettimeofday(&ask->wait, NULL);
  ask->wait.tv_sec += sec;
  ask->wait.tv_usec += usec;
  ask->res = APR;
}

int		check_asking(t_user **usr, t_zap *data, t_ask *ask)
{
  t_tv		now;
  t_user	*tmp;

  gettimeofday(&now, NULL);
  if (ask == NULL || !IS_ASKING(ask) || cmp_tv(&ask->wait, &now) > 0)
    return (0);
  if (ask->res == APR)
    ask->changes(usr, data, ask);
  tmp = *usr;
  while (tmp != NULL)
    {
      if (tmp->type == GRAPHIC && ask->res == APR)
	ask->ok(ask, tmp, data);
      else if (tmp->type == GRAPHIC)
	ask->ko(ask, tmp, data);
      tmp = tmp->next;
    }
  ask->wait.tv_sec = 0;
  ask->wait.tv_usec = 0;
  if (ask->args != NULL)
    sfree(ask->args);
  return (ask->res);
}

void		*clone_ask(void *to_clone)
{
  t_ask		*ask;
  t_ask		*new;

  ask = (t_ask *)to_clone;
  new = xmalloc(sizeof(t_ask));
  new->wait.tv_sec = ask->wait.tv_sec;
  new->wait.tv_usec = ask->wait.tv_usec;
  new->res = ask->res;
  new->args = ask->args;
  new->ok = ask->ok;
  new->changes = ask->changes;
  new->ko = ask->ko;
  return ((void *)new);
}
