/*
** circular_buffer.c for circular_buffer in /home/lopez_t/Zappy/src/CircularBuffer
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 14:18:39 2015 Thibaut Lopez
** Last update Thu May 14 12:39:12 2015 Thibaut Lopez
*/

#include "cb.h"

void	init_cb(t_cb *cb, int cap, int sz)
{
  cb->buff = xmalloc((cap + 1) * sz);
  cb->cap = cap + 1;
  cb->sz = sz;
  cb->beg = 0;
  cb->end = 0;
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
  buff = xmalloc((len + 1) * cb->sz);
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

void	extend_cb(t_cb *cb, int new)
{
  void	*buff;
  int	len;

  if (cb->cap >= new)
    return ;
  len = cb_taken(cb);
  buff = xmalloc((new + 51) * cb->sz);
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
}

void	fill_cb(t_cb *cb, void *to_add, int len)
{
  if (cb_available(cb) < len)
    extend_cb(cb, cb->cap + len);
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
}
