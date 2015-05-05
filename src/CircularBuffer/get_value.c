/*
** get_value.c for get_value in /home/lopez_t/Zappy/src/CircularBuffer
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 14:18:51 2015 Thibaut Lopez
** Last update Tue May  5 14:22:52 2015 Thibaut Lopez
*/

#include "cb.h"

int	cb_taken(t_cb *cb)
{
  int	ret;

  if (cb->beg <= cb->end)
    ret = cb->end - cb->beg;
  else
    ret = cb->cap - (cb->beg - cb->end);
  return (ret);
}

int	cb_available(t_cb *cb)
{
  int	ret;

  if (cb->beg > cb->end)
    ret = cb->beg - cb->end;
  else
    ret = cb->cap - (cb->end - cb->beg);
  ret -= 1;
  return (ret);
}

void	*cb_begin(t_cb *cb)
{
  return ((char *)cb->buff + cb->beg * cb->sz);
}

void	*cb_end(t_cb *cb)
{
  return ((char *)cb->buff + cb->end * cb->sz);
}
