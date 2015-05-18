/*
** my_pnw.c for my_pnw in /home/lopez_t/Zappy/src/pnw
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Mon May 18 17:33:41 2015 Thibaut Lopez
*/

#include "server.h"

int		my_pnw(t_user *usr, t_user *player)
{
  t_user	*tmp;
  int		nbr;
  char		str[200];

  nbr = 0;
  tmp = player;
  while (tmp->prev != NULL)
    {
      if (tmp->type == AI && tmp != player)
	nbr++;
      tmp = tmp->prev;
    }
  if (tmp->type == AI && tmp != player)
    nbr++;
  bzero(str, 200);
  sprintf(str, "pnw #%d %d %d %d %d %s\n",
	  nbr, GET_X(player), GET_Y(player), GET_DIR(player) + 1,
	  GET_LVL(player), GET_TEAM(player));
  fill_cb(&usr->wr, str, strlen(str));
  return (0);
}
