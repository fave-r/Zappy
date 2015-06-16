/*
** read_cb.c for read_cb in /home/lopez_t/PSU_2014_myirc/utils/CircularBuffer
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri Apr 10 10:17:56 2015 Thibaut Lopez
** Last update Tue Jun 16 02:46:24 2015 Thibaut Lopez
*/

#include "cb.h"

void	*flush_cb(t_cb *cb)
{
  bzero(cb->buff, cb->cap * cb->sz);
  cb->beg = 0;
  cb->end = 0;
  return (NULL);
}

int	cbchr(t_cb *cb, void *c)
{
  int	i;

  i = cb->beg;
  while (i % cb->cap != cb->end &&
	 memcmp((char *)cb->buff + (i % cb->cap) * cb->sz, c, cb->sz) != 0)
    i++;
  if (i % cb->cap == cb->end)
    return (-1);
  return (i - cb->beg);
}

char	*get_line_cb(t_cb *cb)
{
  int	ret;
  char	*str;

  str = NULL;
  if ((ret = cbchr(cb, "\r")) != -1 || (ret = cbchr(cb, "\n")) != -1)
    {
      str = get_cb(cb, ret + 1);
      str[ret] = 0;
    }
  return (str);
}

int	read_cb(t_cb *cb, int fd)
{
  int	rl;
  char	*str;

  str = xmalloc(500 * sizeof(char));
  rl = read(fd, str, 499);
  str[rl] = 0;
  if (rl > 0)
    fill_cb(cb, str, rl);
  free(str);
  return (rl);
}

int	write_cb(t_cb *cb, int fd, t_que **queue)
{
  int	wl;
  char	*str;
  t_tv	now;
  t_tv	*tmp;

  gettimeofday(&now, NULL);
  if (queue == NULL || cmp_tv(front_q(*queue), &now) <= 0)
    {
      if ((str = get_line_cb(cb)) == NULL)
	return (0);
      printf("%d -> %s\n", fd, str);
      str[strlen(str)] = '\n';
      tmp = front_q(*queue);
      if (tmp == NULL)
	tmp = &now;
      wl = write(fd, str, strlen(str));
      if (queue != NULL && wl == (int)strlen(str))
	pop_q(queue);
      fill_cb(cb, str + wl, strlen(str) - wl);
      free(str);
    }
  return (0);
}
