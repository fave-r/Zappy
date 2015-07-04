/*
** circular_buffer.c for circular_buffer in /home/lopez_t/Zappy/src/CircularBuffer
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 14:18:39 2015 Thibaut Lopez
** Last update Sat Jul  4 16:19:21 2015 Thibaut Lopez
*/

#include "cb.h"

int	init_cb(t_cb *cb, int cap, int sz)
{
  if ((cb->buff = malloc((cap + 1) * sz)) == NULL)
    return (-1);
  cb->cap = cap + 1;
  cb->sz = sz;
  cb->beg = 0;
  cb->end = 0;
  return (0);
}

void	free_cb(t_cb *cb)
{
  free(cb->buff);
}

void	*get_cb(t_cb *cb, int len)
{
  void	*buff;

  if (cb->beg == cb->end)
    return (NULL);
  else if (cb_taken(cb) < len)
    len = cb_taken(cb);
  if ((buff = malloc((len + 1) * cb->sz)) == NULL)
    return (NULL);
  bzero(buff, (len + 1) * cb->sz);
  if (cb->beg < cb->end || cb->cap - cb->beg >= len)
    memcpy(buff, cb_begin(cb), len * cb->sz);
  else
    {
      memcpy(buff, cb_begin(cb), (cb->cap - cb->beg) * cb->sz);
      memcpy((char *)buff + (cb->cap - cb->beg) * cb->sz,
	     cb->buff, (len - cb->cap + cb->beg) * cb->sz);
    }
  cb->beg += len;
  cb->beg %= cb->cap + 1;
  return (buff);
}

int	extend_cb(t_cb *cb, int new)
{
  void	*buff;
  int	len;

  if (cb->cap >= new)
    return (0);
  len = cb_taken(cb);
  if ((buff = malloc((new + 51) * cb->sz)) == NULL)
    return (-1);
  bzero(buff, (new + 51) * cb->sz);
  if (cb->beg < cb->end)
    memcpy(buff, cb_begin(cb), len * cb->sz);
  else
    {
      memcpy(buff, cb_begin(cb), (cb->cap - cb->beg) * cb->sz);
      memcpy((char *)buff + (cb->cap - cb->beg) * cb->sz,
	     cb->buff, (len - cb->cap + cb->beg) * cb->sz);
    }
  cb->beg = 0;
  cb->end = len;
  free(cb->buff);
  cb->buff = buff;
  cb->cap = new + 50;
  return (0);
}

int	fill_cb(t_cb *cb, void *to_add, int len)
{
  if (cb_available(cb) < len)
    if (extend_cb(cb, cb->cap + len) != 0)
      return (-1);
  if (len < cb->cap - cb->end)
    memcpy(cb_end(cb), to_add, (len * cb->sz));
  else
    {
      memcpy(cb_end(cb), to_add, (cb->cap - cb->end) * cb->sz);
      memcpy(cb->buff, (char *)to_add + (cb->cap - cb->end) * cb->sz,
	     (len - cb->cap + cb->end) * cb->sz);
    }
  cb->end += len;
  cb->end %= cb->cap;
  return (0);
}
