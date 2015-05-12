/*
** main.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 15:02:45 2015 romaric
** Last update Tue May 12 11:05:39 2015 Thibaut Lopez
*/

#include "server.h"

void		unit_user_free(t_user *user)
{
  close(user->fd);
  free_cb(&user->cb);
  free_cb(&user->wr);
  if (user->prev != NULL)
    user->prev->next = user->next;
  if (user->next != NULL)
    user->next->prev = user->prev;
  free(user);
}

void		check_client(t_user **user, t_bf *bf)
{
  t_user	*tmp;

  tmp = *user;
  while (tmp != NULL)
    {
      if (cb_taken(&tmp->wr) > 0 && FD_ISSET(tmp->fd, &bf->wbf))
	write_cb(&tmp->wr, tmp->fd);
      //if (FD_ISSET(tmp->fd, &bf->rbf))
	//read_com(tmp, chans);
      if (tmp->tokill == 1)
	{
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
  handle_fds(s, &user);
  data_free(&user);
  close(s);
  sfree(data.team);
  return (0);
}
