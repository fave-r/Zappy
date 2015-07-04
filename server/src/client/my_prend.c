/*
** my_prend.c for my_prend in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 17:55:21 2015 Thibaut Lopez
*/

#include "server.h"

int	get_sibur(t_content *cnt, uint16_t **val)
{
  *val = &cnt->sibur;
  return (0);
}

int	get_mendiane(t_content *cnt, uint16_t **val)
{
  *val = &cnt->mendiane;
  return (0);
}

int	get_phiras(t_content *cnt, uint16_t **val)
{
  *val = &cnt->phiras;
  return (0);
}

int	get_thystame(t_content *cnt, uint16_t **val)
{
  *val = &cnt->thystame;
  return (0);
}

int	my_prend(char **com, t_zap *data, t_user *usr)
{
  int		i;
  uint16_t	*inv;
  uint16_t	*cell;
  t_com		*ptr;
  t_tv		now;

  gettimeofday(&now, NULL);
  if ((ptr = ptrs_get()) == NULL || sstrlen(com) != 2 ||
      (i = find_ptr(ptr, com[1])) == -1)
    {
      free(ptr);
      xfill_cb(usr, &usr->wr, "ko\n");
      return ((sstrlen(com) != 2) ? -1 : 0);
    }
  ptr[i].ptr(&(GET_INV(usr)), &inv);
  ptr[i].ptr(&(data->map[GET_X(usr)][GET_Y(usr)]), &cell);
  free(ptr);
  xfill_cb(usr, &usr->wr, (*cell > 0) ? "ok\n" : "ko\n");
  if (*cell > 0)
    {
      (*cell)--;
      (*inv)++;
    }
  xpush_q(usr, &usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  return (send_prend(usr, i, &data->map[GET_X(usr)][GET_Y(usr)]));
}
