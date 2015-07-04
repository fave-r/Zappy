/*
** cb.h for cb in /home/lopez_t/Zappy/src/CircularBuffer
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May  5 14:14:46 2015 Thibaut Lopez
** Last update Sat Jul  4 16:17:26 2015 Thibaut Lopez
*/

#ifndef	CB_H
#define CB_H

#include <strings.h>
#include "utils.h"

typedef struct	s_cb
{
  void		*buff;
  int		cap;
  int		sz;
  int		beg;
  int		end;
}		t_cb;

int	init_cb(t_cb *, int, int);
void	free_cb(t_cb *);
void	*get_cb(t_cb *, int);
int	extend_cb(t_cb *, int);
int	fill_cb(t_cb *, void *, int);
int	cb_taken(t_cb *);
int	cb_available(t_cb *);
void	*cb_begin(t_cb *);
void	*cb_end(t_cb *);
void	*flush_cb(t_cb *);
int	cbchr(t_cb *, void *);
char	*get_line_cb(t_cb *);

#endif
