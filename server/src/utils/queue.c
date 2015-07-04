/*
** queue.c for queue in /home/lopez_t/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 15 14:41:50 2015 Thibaut Lopez
** Last update Sat Jul  4 15:13:26 2015 Thibaut Lopez
*/

#include "utils.h"

void	push_q(t_que **q, void *e, void *(*clone)(void *))
{
  t_que	*new;
  t_que	*tmp;

  if (e == NULL)
    return ;
  new = malloc(sizeof(t_que));
  new->e = clone(e);
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
    {
      free(tmp->e);
      free(tmp);
    }
}

void	*front_q(t_que *q)
{
  if (q == NULL)
    return (NULL);
  return (q->e);
}

int	q_len(t_que *q)
{
  int	i;

  i = 0;
  while (q != NULL)
    {
      i++;
      q = q->next;
    }
  return (i);
}
