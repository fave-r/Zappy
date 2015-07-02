/*
** my_smg.c for my_smg in /home/lopez_t/Zappy/server/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu Jul  2 00:47:18 2015 Thibaut Lopez
** Last update Thu Jul  2 00:52:30 2015 Thibaut Lopez
*/

#include "server.h"

int	my_smg(t_user *usr, char *msg)
{
  fill_cb(&usr->wr, "smg ", 4);
  fill_cb(&usr->wr, msg, strlen(msg));
  fill_cb(&usr->wr, "\n", 1);
  return (0);
}
