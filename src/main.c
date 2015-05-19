/*
** main.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:02:45 2015 romaric
** Last update Tue May 19 16:49:21 2015 Thibaut Lopez
*/

#include "server.h"

void		write_separate(t_user **user, t_bf *bf)
{
  t_user	*tmp;

  tmp = *user;
  while (tmp != NULL)
    {
      if (cb_taken(&tmp->wr) > 0 && FD_ISSET(tmp->fd, &bf->wbf))
	write_cb(&tmp->wr, tmp->fd, &tmp->queue);
      tmp = tmp->next;
    }
}

int		check_food(t_user *usr, t_zap *data)
{
  t_tv		tv;
  t_tv		tmp;
  t_tv		time;

  if (usr->type == AI)
    {
      gettimeofday(&tv, NULL);
      timersub(&tv, &usr->plr->time, &tmp);
      time.tv_usec = 0;
      time.tv_sec = 0;
      add_tv(&time, (126000000 / data->delay));
      if (cmp_tv(&tmp, &time) == 1 || cmp_tv(&tmp, &time) == 0)
	{
	  usr->plr->inv.food -= 1;
	  usr->plr->time = tv;
	  if (usr->plr->inv.food  == 0)
	    {
	      usr->tokill = 1;
	      return (-1);
	    }
	}
    }
  return (0);
}

void		send_death(t_user *usr)
{
  char		str[25];

  dprintf(usr->fd, "mort\n");
  sprintf(str, "pdi #%d\n", GET_NB(usr));
  send_to_graphic(str, usr);
}

void		check_client(t_user **user, t_bf *bf, t_zap *data)
{
  t_user	*tmp;

  tmp = *user;
  while (tmp != NULL)
    {
      if (check_food(tmp, data) != -1 && FD_ISSET(tmp->fd, &bf->rbf))
	read_com(tmp, data);
      if (tmp->tokill == 1)
	{
	  if (tmp->type == AI)
	    send_death(tmp);
	  *user = (tmp == *user) ? (*user)->next : *user;
	  if (tmp->next == NULL)
	    {
	      unit_user_free(tmp);
	      tmp = NULL;
	    }
	  else
	    unit_user_free((tmp = tmp->next)->prev);
	}
      else
	tmp = tmp->next;
    }
  write_separate(user, bf);
}

int			main(int ac, char **av)
{
  int			s;
  t_user		*user;
  t_zap			data;

  (void)ac;
  srand(time(NULL));
  init_val(&data);
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
  sfree(data.team);
  return (0);
}
