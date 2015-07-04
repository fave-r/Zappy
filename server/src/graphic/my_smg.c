/*
** my_smg.c for my_smg in /home/lopez_t/Zappy/server/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jul  2 00:47:18 2015 Thibaut Lopez
** Last update Sat Jul  4 16:48:35 2015 Thibaut Lopez
*/

#include "server.h"

int	my_smg(t_user *usr, char *msg)
{
  xfill_cb(usr, &usr->wr, "smg ");
  xfill_cb(usr, &usr->wr, msg);
  xfill_cb(usr, &usr->wr, "\n");
  return (0);
}
