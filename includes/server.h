/*
** server.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Tue May  5 18:45:31 2015 Thibaut Lopez
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include "cb.h"

typedef struct	s_user
{
  int		fd;
  char		*ip;
  t_cb		cb;
  t_cb		wr;
  int		tokill;
  struct s_user	*next;
  struct s_user	*prev;
}		t_user;

typedef struct	s_bf
{
  fd_set	rbf;
  fd_set	wbf;
}		t_bf;

int		clean_return(int, char *);
int		init_socket(void);
int		init_bind(int, int *);
int		init_connect(int, int, char *);
void		set_fd(int, t_bf *, t_user *);
void		new_client(int, t_user **, int *);
void		check_client(t_user **, t_bf *);
int		handle_fds(int, t_user **);
void		data_free(t_user **);

#endif
