/*
** while_serv.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:38:34 2015 romaric
** Last update Thu Jul  2 19:45:00 2015 Thibaut Lopez
*/

#include "server.h"

static int	quit_sig = 0;

void		signal_quit(__attribute__((unused))int signo)
{
  quit_sig = -1;
  write(1, "\n", 1);
}

void		send_death(t_user **user, t_user **tmp, t_zap *data)
{
  char		str[50];

  if ((*tmp)->type == AI)
    {
      if ((*tmp)->tokill != 2)
	dprintf((*tmp)->fd, "mort\n");
      bzero(str, 50);
      sprintf(str, "pdi %d\n", (*tmp)->nb);
      if (check_nb_in_cell(1, *tmp) == 1)
	sprintf(str + strlen(str), "pie %d %d %d\n", GET_X(*tmp), GET_Y(*tmp), 0);
      if (GET_TEAM(*tmp)->count > data->count)
	GET_TEAM(*tmp)->count--;
      send_to_graphic(str, *tmp);
    }
  *user = (*tmp == *user) ? (*user)->next : *user;
  *tmp = unit_user_free(*tmp, data);
}

void		cast_result(t_zap *data, t_user **user, t_user *tmp, t_tv *now)
{
  int		check;
  t_user	*cur;
  char		str[50];
  t_tv		time;

  check = check_this_case(tmp, data, 1);
  cur = *user;
  bzero(str, 50);
  sprintf(str, "pie %d %d %d\n", GET_X(tmp), GET_Y(tmp), check);
  send_to_graphic(str, (*user));
  time.tv_sec = GET_CAST(tmp).tv_sec;
  time.tv_usec = GET_CAST(tmp).tv_usec;
  while ((cur = in_this_cell(GET_X(tmp), GET_Y(tmp), cur)) != NULL)
    {
      cast_loop(cur, &time, check, now);
      cur = cur->next;
    }
  send_inc_to_graph(tmp, data);
  if ((check = team_winning(tmp, GET_TEAM(tmp))) == 1)
    push_q(&data->end, now, clone_tv);
  data->win = (check == 1) ? GET_TEAM(tmp) : NULL;
}

void		check_client(t_user **user, t_bf *bf, t_zap *data)
{
  t_user	*tmp;
  t_tv		now;

  tmp = *user;
  gettimeofday(&now, NULL);
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, &bf->rbf) || cb_taken(&tmp->cb) > 0)
	read_com(tmp, data);
      if (tmp->type == AI && IS_CASTING(tmp) &&
	  cmp_tv(&GET_CAST(tmp), &now) <= 0)
	cast_result(data, user, tmp, &now);
      if (tmp->tokill != 0)
	send_death(user, &tmp, data);
      else
	tmp = tmp->next;
    }
  tmp = *user;
  while (tmp != NULL)
    {
      if (cb_taken(&tmp->wr) > 0 && FD_ISSET(tmp->fd, &bf->wbf))
	write_cb(tmp, data, &tmp->queue);
      tmp = tmp->next;
    }
}

int			handle_fds(int s, t_user **user, t_zap *data)
{
  t_bf			bf;
  int			bool;
  t_tv			tv;

  signal(SIGINT, signal_quit);
  bool = 0;
  *user = NULL;
  while (bool == 0)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 100000;
      set_fd(s, &bf, *user);
      if ((bool = select(s + nb_client(*user) + 1,
			 &bf.rbf, &bf.wbf, NULL, &tv)) != -1)
	{
	  if (FD_ISSET(s, &bf.rbf))
	    new_client(s, user);
	  check_client(user, &bf, data);
	}
      bool = (quit_sig != 0) ? quit_sig : manage_server(user, data);
    }
  return (0);
}
