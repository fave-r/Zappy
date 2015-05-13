/*
** server.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Thu May 14 01:31:48 2015 Thibaut Lopez
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H
#define	S_MOD(a, b)	(((a) < 0) ? (a) + (b) : (a) % (b))

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include "cb.h"

typedef	enum	e_state
  {
    P = 0,
    X,
    Y,
    N,
    C,
    T,
    NONE = -1
  }		e_state;

typedef enum	e_dir
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  }		e_dir;

typedef enum	e_clt
  {
    UNKNOWN = 1,
    AI = 2,
    GRAPHIC = 3
  }		e_clt;

typedef struct	s_pair
{
  int		f;
  int		s;
}		t_pair;

typedef struct	s_content
{
  uint16_t	food;
  uint16_t	linemate;
  uint16_t	deraumere;
  uint16_t	sibur;
  uint16_t	mendiane;
  uint16_t	phiras;
  uint16_t	thystame;
}		t_content;

typedef struct	s_zap
{
  int		port;
  t_content	**map;
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
  e_clt		type;
  int		x;
  int		y;
  e_dir		dir;
  t_content	inv;
  char		*team;
  uint16_t	level;
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
void		check_client(t_user **, t_bf *, t_zap *);
int		handle_fds(int, t_user **, t_zap *);
int		read_com(t_user *, t_zap *);
void		data_free(t_user **);

int		set_port(t_zap *, char *, e_state *);
int		set_x(t_zap *, char *, e_state *);
int		set_y(t_zap *, char *, e_state *);
int		set_team(t_zap *, char *, e_state *);
int		set_count(t_zap *, char *, e_state *);
int		set_delay(t_zap *, char *, e_state *);
int		parse_com(char **, t_zap *);
int		base_value(t_zap *);
void		init_val(t_zap *);

int		count_in_team(char *, t_user *);
t_user		*in_this_cell(int, int, t_user *);
int		my_avance(char **, t_zap *, t_user *);
int		my_broadcast(char **, t_zap *, t_user *);
int		my_connect_nbr(char **, t_zap *, t_user *);
int		my_droite(char **, t_zap *, t_user *);
int		my_expulse(char **, t_zap *, t_user *);
int		my_fork(char **, t_zap *, t_user *);
int		my_gauche(char **, t_zap *, t_user *);
int		my_incantation(char **, t_zap *, t_user *);
int		my_inventaire(char **, t_zap *, t_user *);
int		my_pose(char **, t_zap *, t_user *);
int		my_prend(char **, t_zap *, t_user *);
int		my_graphic(char **, t_zap *, t_user *);
int		my_other(char **, t_zap *, t_user *);
int		my_msz(char **, t_zap *, t_user *);
int		my_bct(char **, t_zap *, t_user *);
int		my_mct(char **, t_zap *, t_user *);
int		my_tna(char **, t_zap *, t_user *);
int		my_ppo(char **, t_zap *, t_user *);
int		my_plv(char **, t_zap *, t_user *);
int		my_pin(char **, t_zap *, t_user *);
int		my_sgt(char **, t_zap *, t_user *);
int		my_sst(char **, t_zap *, t_user *);
void		north_gofo(t_pair *, int);
void		north_gole(t_pair *, int);
void		east_gofo(t_pair *, int);
void		east_gole(t_pair *, int);
void		south_gofo(t_pair *, int);
void		south_gole(t_pair *, int);
void		west_gofo(t_pair *, int);
void		west_gole(t_pair *, int);
int		my_voir(char **, t_zap *, t_user *);

#endif
