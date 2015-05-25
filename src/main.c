/*
** main.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:02:45 2015 romaric
** Last update Mon May 25 16:35:09 2015 Thibaut Lopez
*/

#include "server.h"

int		check_food(t_user *usr, t_zap *data)
{
  t_tv		tv;
  t_tv		tmp;
  t_tv		time;

  if (usr->type == AI)
    {
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
    }
  return (0);
}

void		send_death(t_user **user, t_user **tmp)
{
  char		str[25];

  if ((*tmp)->type == AI)
    {
      dprintf((*tmp)->fd, "mort\n");
      sprintf(str, "pdi #%d\n", GET_NB(*tmp));
      send_to_graphic(str, *tmp, NULL);
    }
  *user = (*tmp == *user) ? (*user)->next : *user;
  if ((*tmp)->next == NULL)
    {
      unit_user_free(*tmp);
      *tmp = NULL;
    }
  else
    {
      *tmp = (*tmp)->next;
      unit_user_free((*tmp)->prev);
    }
}

void		cast_result(t_zap *data, t_user **user, t_user *tmp, t_tv *now)
{
  int		check;
  t_user	*cur;
  char		str[50];

  check = check_this_case(tmp, data, 1);
  cur = *user;
  while ((cur = in_this_cell(GET_X(tmp), GET_Y(tmp), cur)) != NULL)
    {
      if (cmp_tv(&GET_CAST(cur), &GET_CAST(tmp)) == 0)
	{
	  GET_CAST(cur).tv_sec = 0;
	  GET_CAST(cur).tv_usec = 0;
	  if (check == 1)
	    GET_LVL(cur)++;
	}
      bzero(str, 50);
      sprintf(str, "niveau actuel : %d\n", GET_LVL(cur));
      fill_cb(&cur->wr, str, strlen(str));
      push_q(&cur->queue, now);
      cur = cur->next;
    }
  if ((check = team_winning(tmp, GET_TEAM(tmp))) == 1)
    push_q(&data->end, now);
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
      if (check_food(tmp, data) != -1 &&
	  (FD_ISSET(tmp->fd, &bf->rbf) || cb_taken(&tmp->cb) > 0))
	read_com(tmp, data);
      if (tmp->type == AI && IS_CASTING(tmp) &&
	  cmp_tv(&GET_TIME(tmp), &now) >= 0)
	cast_result(data, user, tmp, &now);
      if (tmp->tokill == 1)
	send_death(user, &tmp);
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
  if ((s = init_socket()) == -1)
    return (1);
  if (init_bind(s, &data.port) == -1)
    return (clean_return(s, "Couldn't bind"));
  if (listen(s, 42) == -1)
    return (clean_return(s, "Couldn't listen"));
  init_val(&data);
  if (ac == 1)
    printf("Note on usage: ./zappy [-p port] [-x length] \
[-y width] [-n team_name ...] [-c client_per_team] [-t delay]\n");
  if (parse_com(av, &data) == 0)
    handle_fds(s, &user, &data);
  data_free(&user);
  close(s);
  free_zap(&data);
  return (0);
}
