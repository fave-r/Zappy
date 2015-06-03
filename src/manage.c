/*
** manage.c for manage in /home/lopez_t/BONUS/Zappy/src
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Mon Jun  1 11:28:59 2015 Thibaut Lopez
** Last update Wed Jun  3 10:01:01 2015 Thibaut Lopez
*/

#include "server.h"

int		check_food(t_user *usr, t_zap *data)
{
  t_tv		tv;
  t_tv		tmp;
  t_tv		time;

  gettimeofday(&tv, NULL);
  timersub(&tv, &GET_TIME(usr), &tmp);
  time.tv_usec = 0;
  time.tv_sec = 0;
  add_tv(&time, (126000000 / data->delay));
  if (cmp_tv(&tmp, &time) == 1 || cmp_tv(&tmp, &time) == 0)
    {
      GET_INV(usr).food -= 1;
      GET_TIME(usr) = tv;
      if (GET_INV(usr).food  == 0)
	{
	  usr->tokill = 1;
	  return (-1);
	}
    }
  return (0);
}

int		end_game(t_zap *data, t_user **user)
{
  char		str[256];
  t_user	*tmp;

  bzero(str, 256);
  sprintf(str, "seg %s\naeg\n", data->winner->name);
  tmp = *user;
  while (tmp != NULL)
    {
      if (tmp->type == GRAPHIC)
	fill_cb(&tmp->wr, str, strlen(str));
      if (tmp->type != UNKNOWN)
	while (cb_taken(&tmp->wr) > 0)
	  write_cb(&tmp->wr, tmp->fd, NULL);
      if (tmp->type == AI && *user == tmp)
	*user = (*user)->next;
      tmp = (tmp->type == AI) ? unit_user_free(tmp) : tmp->next;
    }
  while (data->end != NULL)
    pop_q(&data->end);
  if (count_type(*user, GRAPHIC) == 0)
    return (0);
  find_ask(&data->end_game, data->asking);
  return (0);
}

int		manage_server(t_user **user, t_zap *data)
{
  t_user	*tmp;
  t_tv		now;
  t_ask		*ask;

  tmp = *user;
  while (tmp != NULL)
    {
      if (tmp->type == AI)
	check_food(tmp, data);
      else if (tmp->type == GRAPHIC)
	{
	  ask = front_q((t_que *)tmp->info);
	  check_asking(tmp, data, ask);
	  if (ask != NULL && !IS_ASKING(ask))
	    pop_q((t_que **)&tmp->info);
	}
      if (tmp->tokill == 1)
	send_death(user, &tmp, data);
      else
	tmp = tmp->next;
    }
  gettimeofday(&now, NULL);
  if (front_q(data->end) != NULL && cmp_tv(front_q(data->end), &now) <= 0)
    return (end_game(data, user));
  return (check_asking(*user, data, &data->end_game));
}
