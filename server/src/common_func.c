/*
** common_func.c for common_func in /home/lopez_t/Zappy/server/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Sat Jul  4 16:41:44 2015 Thibaut Lopez
** Last update Sat Jul  4 20:38:10 2015 Thibaut Lopez
*/

#include "server.h"

void	xfill_cb(t_user *usr, t_cb *cb, char *str)
{
  if (usr->tokill == 0 && fill_cb(cb, str, strlen(str)) != 0)
    usr->tokill = 1;
}

void	xpush_q(t_user *usr, t_que **q, void *e, void *(*clone)(void *))
{
  if (usr->tokill == 0 && push_q(q, e, clone) != 0)
    usr->tokill = 1;
}

int	map_free(t_content **map, int width)
{
  int	i;

  i = 0;
  while (i < width || map[i] != NULL)
    {
      free(map[i]);
      i++;
    }
  return (-1);
}
