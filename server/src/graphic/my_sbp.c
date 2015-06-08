/*
** my_sbp.c for my_sbp in /home/lopez_t/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Mon May 25 17:31:08 2015 Thibaut Lopez
** Last update Mon May 25 18:09:44 2015 Thibaut Lopez
*/

#include "server.h"

int	my_sbp(t_user *usr)
{
  fill_cb(&usr->wr, "sbp\n", 4);
  return (0);
}
