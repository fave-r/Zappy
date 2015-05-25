/*
** while_serv.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:38:34 2015 romaric
** Last update Mon May 25 14:48:53 2015 Thibaut Lopez
*/

#include "server.h"

static int	quit_sig = 0;

void		signal_quit(__attribute__((unused))int signo)
{
  quit_sig = -1;
  write(1, "\n", 1);
}

void		init_handle(int *bool, t_user **user
			    ,  int *nb)
{
  signal(SIGINT, signal_quit);
  *nb = 1;
  *bool = 0;
  *user = NULL;
}

int			end_game(t_zap *data, t_user **user)
{
  t_user		*tmp;
  char			str[256];

  bzero(str, 256);
  sprintf(str, "seg %s\n", data->winner);
  tmp = *user;
  while (tmp != NULL)
    {
      if (tmp->type != UNKNOWN)
	{
	  fill_cb(&tmp->wr, str, strlen(str));
	  while (cb_taken(&tmp->wr) > 0)
	    write_cb(&tmp->wr, tmp->fd, NULL);
	}
      tmp = tmp->next;
    }
  return (-1);
}

int			handle_fds(int s, t_user **user, t_zap *data)
{
  t_bf			bf;
  int			bool;
  int			nb_client;
  t_tv			tv;
  t_tv			now;

  init_handle(&bool, user, &nb_client);
  tv.tv_sec = 0;
  tv.tv_usec = 50000;
  while (bool != -1)
    {
      set_fd(s, &bf, *user);
      if ((bool = select(s + nb_client, &bf.rbf, &bf.wbf, NULL, &tv)) != -1)
	{
	  if (FD_ISSET(s, &bf.rbf))
	    new_client(s, user, &nb_client);
	  check_client(user, &bf, data);
	}
      bool = quit_sig;
      gettimeofday(&now, NULL);
      if (front_q(data->end) != NULL && cmp_tv(front_q(data->end), &now) <= 0)
	bool = end_game(data, user);
    }
  return (0);
}

void		data_free(t_user **data)
{
  t_user	*tmp;

  tmp = *data;
  while (tmp != NULL && tmp->next != NULL)
    {
      close(tmp->fd);
      free_cb(&tmp->cb);
      free_cb(&tmp->wr);
      while (tmp->queue != NULL)
	pop_q(&tmp->queue);
      if (tmp->type == AI)
	free(tmp->plr);
      tmp = tmp->next;
      free(tmp->prev);
    }
  if (tmp != NULL)
    free(tmp);
}
