/*
** my_prend.c for my_prend in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Thu May 14 15:13:16 2015 Thibaut Lopez
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

  ptr = NULL;
  if (sstrlen(com) != 2 || (ptr = ptrs_get()) == NULL ||
      (i = find_ptr(ptr, com[1])) == -1)
    {
      if (ptr != NULL)
	free(ptr);
      fill_cb(&usr->wr, "ko\n", 3);
      return (0);
    }
  ptr[i].ptr(&(usr->inv), &inv);
  ptr[i].ptr(&(data->map[usr->x][usr->y]), &cell);
  free(ptr);
  fill_cb(&usr->wr, (*cell > 0) ? "ok\n" : "2ko\n", 3);
  if (*cell > 0)
    {
      (*cell)--;
      (*inv)++;
    }
  return (0);
}
