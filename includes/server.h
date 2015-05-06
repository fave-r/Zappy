/*
** server.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Wed May  6 10:14:23 2015 Thibaut Lopez
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include "cb.h"

typedef	enum e_state
  {
    P = 0,
    X,
    Y,
    N,
    C,
    T,
    NONE = -1
  }	e_state;

typedef struct	s_zap
{
  int		port;
  /* type	*map */
  int		length;
  int		width;
  char		**team;
  int		count;
  int		delay;
}		t_zap;

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

int		set_port(t_zap *, char *, e_state *);
int		set_x(t_zap *, char *, e_state *);
int		set_y(t_zap *, char *, e_state *);
int		set_team(t_zap *, char *, e_state *);
int		set_count(t_zap *, char *, e_state *);
int		set_delay(t_zap *, char *, e_state *);
int		parse_com(char **, t_zap *);

#endif
