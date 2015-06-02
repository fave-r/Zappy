/*
** my_anr.c for anr in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Tue Jun  2 18:36:26 2015 Thibaut Lopez
*/

#include "server.h"

int	aeg_response(t_zap *data, t_user *usr)
{
  if (data->end_game.wait.tv_sec == 0 &&
      data->end_game.wait.tv_usec == 0)
    return (my_sbp(usr));
  data->end_game.res |= ANR;
  return (0);
}

int	my_anr(char **com, t_zap *data, t_user *usr)
{
  if (sstrlen(com) > 3)
    return (my_sbp(usr));
  if (sstrlen(com) == 1)
    return (aeg_response(data, usr));
  return (0);
}
