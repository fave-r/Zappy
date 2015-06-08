/*
** while_serv.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:38:34 2015 romaric
** Last update Mon Jun  8 13:58:34 2015 romaric
*/

#include "server.h"

static int	quit_sig = 0;

void		signal_quit(__attribute__((unused))int signo)
{
  quit_sig = -1;
  write(1, "\n", 1);
}

void		init_handle(int *bool, t_user **user, int *nb, t_tv *tv)
{
  signal(SIGINT, signal_quit);
  *nb = 1;
  *bool = 0;
  *user = NULL;
  tv->tv_sec = 0;
  tv->tv_usec = 5000;
}

int			handle_fds(int s, t_user **user, t_zap *data)
{
  t_bf			bf;
  int			bool;
  int			nb_client;
  t_tv			tv;

  init_handle(&bool, user, &nb_client, &tv);
  while (bool == 0)
    {
      set_fd(s, &bf, *user);
      if ((bool = select(s + nb_client, &bf.rbf, &bf.wbf, NULL, &tv)) != -1)
	{
	  if (FD_ISSET(s, &bf.rbf))
	    new_client(s, user, &nb_client);
	  check_client(user, &bf, data);
	}
      bool = (quit_sig != 0) ? quit_sig : manage_server(user, data);
    }
  return (0);
}
