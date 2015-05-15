/*
** queue.c for queue in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 15 14:41:50 2015 Thibaut Lopez
** Last update Fri May 15 15:39:45 2015 Thibaut Lopez
*/

#include "utils.h"

void	push_q(t_que **q, t_tv tv)
{
  t_que	*new;
  t_que	*tmp;

  new = xmalloc(sizeof(t_que));
  new->e = tv;
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

t_tv	front_q(t_que *q)
{
  return (q->e);
}
