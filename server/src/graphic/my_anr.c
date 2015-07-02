/*
** my_anr.c for anr in /home/lopez_t/BONUS/Zappy/src/graphic
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Fri May 29 15:07:54 2015 Thibaut Lopez
** Last update Fri Jul  3 00:47:46 2015 Thibaut Lopez
*/

#include "server.h"

int		aeg_response(t_zap *data, t_user *usr, e_rsp res)
{
  if (!IS_ASKING(&data->end_game))
    return (my_sbp(usr));
  data->end_game.res |= res;
  return (0);
}

int		my_anr(char **com, t_zap *data, t_user *usr)
{
  int		ig;
  int		ask_nb;
  t_ask		*ask;

  if (sstrlen(com) > 3 || sstrlen(com) == 1)
    return (my_sbp(usr));
  if (sstrlen(com) == 1)
    return (aeg_response(data, usr, ANR));
  if ((ig = my_strtol(com[1])) == -1 ||
      (ask_nb = my_strtol(com[2])) == -1)
    return (my_sbp(usr));
  if ((ask = get_asking(usr, ig, ask_nb)) == NULL)
    return (my_sbp(usr));
  ask->res |= ANR;
  return (0);
}
