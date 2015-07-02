/*
** my_pnw.c for my_pnw in /home/lopez_t/Zappy/src/pnw
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 14 01:07:32 2015 Thibaut Lopez
** Last update Fri Jul  3 00:58:48 2015 Thibaut Lopez
*/

#include "server.h"

int		my_pnw(t_user *usr, t_user *player)
{
  int		nbr;
  char		str[200];

  bzero(str, 200);
  nbr = player->nb;
  sprintf(str, "pnw %d %d %d %d %d %s\n",
	  nbr, GET_X(player), GET_Y(player), GET_DIR(player) + 1,
	  GET_LVL(player), GET_TEAM(player)->name);
  fill_cb(&usr->wr, str, strlen(str));
  return (0);
}
