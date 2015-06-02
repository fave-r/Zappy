/*
** my_apr.c for apr in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Tue Jun  2 18:28:15 2015 Thibaut Lopez
*/

#include "server.h"

int	my_apr(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) > 3)
    return (my_sbp(usr));
  (void)data;
  (void)usr;
  return (0);
}
