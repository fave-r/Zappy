/*
** my_pose.c for my_pose in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Sat Jul  4 20:42:02 2015 Thibaut Lopez
*/

#include "server.h"

int		get_food(t_content *cnt, uint16_t **val)
{
  *val = &cnt->food;
  return (0);
}

int		get_linemate(t_content *cnt, uint16_t **val)
{
  *val = &cnt->linemate;
  return (0);
}

int		get_deraumere(t_content *cnt, uint16_t **val)
{
  *val = &cnt->deraumere;
  return (0);
}

t_com		*ptrs_get()
{
  t_com	*ptrs;

  if ((ptrs = malloc(8 * sizeof(t_com))) == NULL)
    return (NULL);
  ptrs[0].com = "nourriture";
  ptrs[0].ptr = get_food;
  ptrs[1].com = "linemate";
  ptrs[1].ptr = get_linemate;
  ptrs[2].com = "deraumere";
  ptrs[2].ptr = get_deraumere;
  ptrs[3].com = "sibur";
  ptrs[3].ptr = get_sibur;
  ptrs[4].com = "mendiane";
  ptrs[4].ptr = get_mendiane;
  ptrs[5].com = "phiras";
  ptrs[5].ptr = get_phiras;
  ptrs[6].com = "thystame";
  ptrs[6].ptr = get_thystame;
  ptrs[7].com = NULL;
  ptrs[7].ptr = NULL;
  return (ptrs);
}

int		my_pose(char **com, t_zap *data, t_user *usr)
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
  xfill_cb(usr, &usr->wr, (*inv > 0) ? "ok\n" : "ko\n");
  if (*inv > 0)
    {
      (*inv)--;
      (*cell)++;
    }
  xpush_q(usr, &usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  return (send_pose(usr, i, &data->map[GET_X(usr)][GET_Y(usr)]));
}
