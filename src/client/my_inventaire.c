/*
** my_inventaire.c for my_inventaire in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Thu May 14 19:16:00 2015 Thibaut Lopez
*/

#include "server.h"

int		my_inventaire(char **com, t_zap *data, t_user *usr)
{
  t_content	cnt;
  char		tmp[150];

  (void)com;
  (void)data;
  cnt = GET_INV(usr);
  bzero(tmp, 150);
  sprintf(tmp, "{nourriture %d, linemate %d, deraumere %d,\
sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	  (int)cnt.food,
	  (int)cnt.linemate,
	  (int)cnt.deraumere,
	  (int)cnt.sibur,
	  (int)cnt.mendiane,
	  (int)cnt.phiras,
	  (int)cnt.thystame);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}
