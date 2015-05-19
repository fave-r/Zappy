/*
** my_expulse.c for my_expulse in /home/lopez_t/Zappy/src/client
**
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
**
** Started on  Tue May 12 14:56:11 2015 Thibaut Lopez
** Last update Tue May 19 11:37:40 2015 romaric
*/

#include "server.h"

int     my_go(t_zap *data, t_user *usr)
{
  t_pair        pos;
  char          tmp[100];

  pos.f = GET_X(usr);
  pos.s = GET_Y(usr);
  gofo[GET_DIR(usr)](&pos, 1);
  GET_X(usr) = S_MOD(pos.f, data->length);
  GET_Y(usr) = S_MOD(pos.s, data->width);
  sprintf(tmp, "ppo #%d %d %d %d\n", find_nb(usr),
          GET_X(usr), GET_Y(usr), GET_DIR(usr));
  send_to_graphic(tmp, usr);
  return (0);
}

int		my_expulse(__attribute__((unused)) char **com,
			   t_zap *data, t_user *usr)
{
  t_user	*tmp;
  e_dir		tp;
  char		str[20];

  tmp = usr;
  while (tmp != NULL && tmp->prev != NULL)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      if (GET_X(tmp) == GET_X(usr) && GET_Y(tmp) == GET_Y(usr))
	{
	  tp = GET_DIR(tmp);
	  GET_DIR(tmp) = GET_DIR(usr);
	  my_go(data, tmp);
	  GET_DIR(tmp) = tp;
	  bzero(str, 20);
	  sprintf(str, "deplacement: %d\n", get_direction(usr, tmp, data));
	  fill_cb(&tmp->wr, str, strlen(str));
	}
      tmp = tmp->next;
    }
  return (0);
}
