/*
** my_suc.c for my_suc in /home/lopez_t/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Mon May 25 17:31:08 2015 Thibaut Lopez
** Last update Sat Jul  4 16:57:36 2015 Thibaut Lopez
*/

#include "server.h"

int	my_suc(char **com, t_zap *data, t_user *usr)
{
  (void)com;
  (void)data;
  xfill_cb(usr, &usr->wr, "suc\n");
  return (0);
}
