/*
** server.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Thu May 21 16:50:06 2015 Thibaut Lopez
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H
#define	S_MOD(a, b)	(((a) < 0) ? (a) + (b) : (a) % (b))
#define	GET_X(u)	((u)->plr->x)
#define	GET_Y(u)	((u)->plr->y)
#define	GET_DIR(u)	((u)->plr->dir)
#define	GET_INV(u)	((u)->plr->inv)
#define	GET_TEAM(u)	((u)->plr->team)
#define	GET_LVL(u)	((u)->plr->level)
#define	GET_NB(u)	((u)->plr->nb)
#define	GET_TIME(u)	((u)->plr->time)

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

typedef struct	s_plr
{
  int		x;
  int		y;
  e_dir		dir;
  t_content	inv;
  char		*team;
  uint16_t	level;
  int		nb;
  t_tv		time;
}		t_plr;

typedef struct	s_user
{
  int		fd;
  char		*ip;
  t_cb		cb;
  t_que		*queue;
  t_cb		wr;
  int		tokill;
  e_clt		type;
  t_plr		*plr;
  int		nb_ncom;
  struct s_user	*next;
  struct s_user	*prev;
}		t_user;

typedef struct	s_bf
{
  fd_set	rbf;
  fd_set	wbf;
}		t_bf;

void		(*gofo[4])(t_pair *, int);

int		clean_return(int, char *);
int		init_socket(void);
int		init_bind(int, int *);
int		init_connect(int, int, char *);
void		set_fd(int, t_bf *, t_user *);
void		new_client(int, t_user **, int *);
void		unit_user_free(t_user *);
void		check_client(t_user **, t_bf *, t_zap *);
int		handle_fds(int, t_user **, t_zap *);
void		check_com(t_com *, t_user *, int *, t_zap *);
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
void		free_zap(t_zap *);

int		count_in_team(char *, t_user *);
t_user		*in_this_cell(int, int, t_user *);
void		send_to_graphic(char *, t_user *, t_tv *);
int		find_nb(t_user *);
int		my_avance(char **, t_zap *, t_user *);
int		my_broadcast(char **, t_zap *, t_user *);
int		my_connect_nbr(char **, t_zap *, t_user *);
int		my_droite(char **, t_zap *, t_user *);
int		my_expulse(char **, t_zap *, t_user *);
int		my_fork(char **, t_zap *, t_user *);
int		my_gauche(char **, t_zap *, t_user *);
int		my_incantation(char **, t_zap *, t_user *);
int		my_inventaire(char **, t_zap *, t_user *);
t_com		*ptrs_get();
int		send_pose(t_user *, int, t_content *, t_tv *);
int		my_pose(char **, t_zap *, t_user *);
int		get_sibur(t_content *, uint16_t **);
int		get_mendiane(t_content *, uint16_t **);
int		get_phiras(t_content *, uint16_t **);
int		get_thystame(t_content *, uint16_t **);
int		send_prend(t_user *, int, t_content *, t_tv *);
int		my_prend(char **, t_zap *, t_user *);
void		north_gofo(t_pair *, int);
void		north_gole(t_pair *, int);
void		east_gofo(t_pair *, int);
void		east_gole(t_pair *, int);
void		south_gofo(t_pair *, int);
void		south_gole(t_pair *, int);
void		west_gofo(t_pair *, int);
void		west_gole(t_pair *, int);
int		my_voir(char **, t_zap *, t_user *);

int		my_graphic(char **, t_zap *, t_user *);
int		my_other(char **, t_zap *, t_user *);

int		my_msz(char **, t_zap *, t_user *);
int		my_bct(char **, t_zap *, t_user *);
int		my_send_bct(t_zap *, t_user *, int, int);
int		my_mct(char **, t_zap *, t_user *);
int		my_tna(char **, t_zap *, t_user *);
int		my_ppo(char **, t_zap *, t_user *);
int		my_plv(char **, t_zap *, t_user *);
int		my_pin(char **, t_zap *, t_user *);
int		my_send_sgt(t_zap *, t_user *);
int		my_sgt(char **, t_zap *, t_user *);
int		my_sst(char **, t_zap *, t_user *);
int		my_pnw(t_user *, t_user *);

int		get_direction(t_user *, t_user *, t_zap *);

#endif
