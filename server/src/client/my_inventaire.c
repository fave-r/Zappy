/*
** my_inventaire.c for my_inventaire in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue Jun 16 16:27:49 2015 Thibaut Lopez
*/

#include "server.h"

int		my_inventaire(char **com, t_zap *data, t_user *usr)
{
  t_content	cnt;
  char		tmp[150];
  t_tv		now;

  (void)data;
  if (sstrlen(com) != 1)
    return (-1);
  gettimeofday(&now, NULL);
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
  push_q(&usr->queue, add_tv(&now, 7000000 / data->delay), clone_tv);
  return (0);
}
