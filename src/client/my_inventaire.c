/*
** my_inventaire.c for my_inventaire in /home/lopez_t/Zappy/src/client
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Wed May 13 18:25:24 2015 Thibaut Lopez
*/

#include "server.h"

int	my_inventaire(char **com, t_zap *data, t_user *usr)
{
  char	tmp[150];

  (void)com;
  (void)data;
  bzero(tmp, 150);
  sprintf(tmp, "{nourriture %d, linemate %d, deraumere %d,\
sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	  (int)usr->inv.food,
	  (int)usr->inv.linemate,
	  (int)usr->inv.deraumere,
	  (int)usr->inv.sibur,
	  (int)usr->inv.mendiane,
	  (int)usr->inv.phiras,
	  (int)usr->inv.thystame);
  fill_cb(&usr->wr, tmp, strlen(tmp));
  return (0);
}
