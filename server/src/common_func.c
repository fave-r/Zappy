/*
** common_func.c for common_func in /home/lopez_t/Zappy/server/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Sat Jul  4 16:41:44 2015 Thibaut Lopez
** Last update Sat Jul  4 16:45:09 2015 Thibaut Lopez
*/

#include "server.h"

void	xfill_cb(t_user *usr, t_cb *cb, char *str)
{
  if (usr->tokill == 0 && fill_cb(cb, str, strlen(str)) != 0)
    usr->tokill = 1;
}
