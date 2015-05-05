/*
** parser.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Tue May  5 17:20:06 2015 romaric
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>
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

void		*xmalloc(size_t n);
int		clean_return(int fd, char *str);
int		init_socket(void);
int		init_bind(int s, int *port);
int		init_connect(int s, int port, char *id);
void		set_fd(int s, t_bf *bf, t_user *user);
void		new_client(int fd, t_user **user, int *nbclient);
void		check_client(t_user **user, t_bf *bf);
int		handle_fds(int s, t_user **user);
void		data_free(t_user **data);

#endif
