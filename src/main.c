/*
** main.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:02:45 2015 romaric
** Last update Mon Jun  1 15:25:24 2015 Thibaut Lopez
*/

#include "server.h"

void		send_death(t_user **user, t_user **tmp, t_zap *data)
{
  char		str[25];

  if ((*tmp)->type == AI)
    {
      dprintf((*tmp)->fd, "mort\n");
      sprintf(str, "pdi #%d\n", (*tmp)->nb);
      if (GET_TEAM(*tmp)->count > data->count)
	GET_TEAM(*tmp)->count--;
      send_to_graphic(str, *tmp, NULL);
    }
  *user = (*tmp == *user) ? (*user)->next : *user;
  *tmp = unit_user_free(*tmp);
}

void		cast_result(t_zap *data, t_user **user, t_user *tmp, t_tv *now)
{
  int		check;
  t_user	*cur;
  char		str[50];

  check = check_this_case(tmp, data, 1);
  cur = *user;
  bzero(str, 50);
  sprintf(str, "pie %d %d %d\n", GET_X(tmp), GET_Y(tmp), check);
  send_to_graphic(str, (*user), NULL);
  while ((cur = in_this_cell(GET_X(tmp), GET_Y(tmp), cur)) != NULL)
    {
      cast_loop(cur, tmp, check, now);
      cur = cur->next;
    }
  send_inc_to_graph(tmp, data);
  if ((check = team_winning(tmp, GET_TEAM(tmp))) == 1)
    push_q(&data->end, now, clone_tv);
  data->winner = (check == 1) ? GET_TEAM(tmp) : NULL;
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
	  cmp_tv(&GET_TIME(tmp), &now) >= 0)
	cast_result(data, user, tmp, &now);
      if (tmp->tokill == 1)
	send_death(user, &tmp, data);
      else
	tmp = tmp->next;
    }
  tmp = *user;
  while (tmp != NULL)
    {
      if (cb_taken(&tmp->wr) > 0 && FD_ISSET(tmp->fd, &bf->wbf))
	write_cb(&tmp->wr, tmp->fd, &tmp->queue);
      tmp = tmp->next;
    }
}

int			main(int ac, char **av)
{
  int			s;
  t_user		*user;
  t_zap			data;

  srand(time(NULL));
  init_val(&data);
  if (ac == 1)
    printf("Note on usage: ./zappy [-p port] [-x length] [-y width] \
[-n team_name ...] [-c client_per_team] [-t delay] [-a asking delay]\n");
  if (parse_com(av, &data) != 0)
    return (1);
  if ((s = init_socket()) == -1)
    return (1);
  if (init_bind(s, &data.port) == -1)
    return (clean_return(s, "Couldn't bind"));
  if (listen(s, 42) == -1)
    return (clean_return(s, "Couldn't listen"));
  handle_fds(s, &user, &data);
  data_free(&user);
  close(s);
  free_zap(&data);
  return (0);
}
