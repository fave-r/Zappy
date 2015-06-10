/*
** while_serv.c for zappy in /home/fave_r/rendu/Zappy/src
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:38:34 2015 romaric
** Last update Wed Jun 10 11:44:28 2015 Thibaut Lopez
*/

#include "server.h"

static int	quit_sig = 0;

void		signal_quit(__attribute__((unused))int signo)
{
  quit_sig = -1;
  write(1, "\n", 1);
}

void		init_handle(int *bool, t_user **user, int *nb)
{
  signal(SIGINT, signal_quit);
  *nb = 1;
  *bool = 0;
  *user = NULL;
}

int			handle_fds(int s, t_user **user, t_zap *data)
{
  t_bf			bf;
  int			bool;
  int			nb_client;
  t_tv			tv;

  init_handle(&bool, user, &nb_client);
  FD_ZERO(&(bf.rbf));
  FD_ZERO(&(bf.wbf));
  FD_SET(s, &(bf.rbf));
  while (bool == 0)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 10000;
      set_fd(&bf, *user);
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
