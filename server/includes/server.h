/*
** server.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Wed Jul  1 18:38:13 2015 Thibaut Lopez
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H
#define	GET_X(u)	(((t_plr *)(u)->info)->x)
#define	GET_Y(u)	(((t_plr *)(u)->info)->y)
#define	GET_DIR(u)	(((t_plr *)(u)->info)->dir)
#define	GET_INV(u)	(((t_plr *)(u)->info)->inv)
#define	GET_TEAM(u)	(((t_plr *)(u)->info)->team)
#define	GET_LVL(u)	(((t_plr *)(u)->info)->level)
#define	GET_TIME(u)	(((t_plr *)(u)->info)->time)
#define	GET_CAST(u)	(((t_plr *)(u)->info)->cast)
#define	GET_GHOST(u)	(((t_plr *)(u)->info)->ghost)
#define	IS_CASTING(u)	(!(GET_CAST(u).tv_sec == 0 && GET_CAST(u).tv_usec == 0))
#define	IS_ASKING(a)	(!((a)->wait.tv_sec == 0 && (a)->wait.tv_usec == 0))

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include "cb.h"

typedef	enum	e_state
  {
    P = 0,
    X,
    Y,
    N,
    C,
    T,
    A,
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
    GRAPHIC = -1
  }		e_clt;

typedef enum	e_rsp
  {
    APR = 0,
    ANR = 1
  }		e_rsp;

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

typedef struct	s_egg
{
  int		nb;
  int		dad;
  int		son;
  t_pair	pos;
  t_tv		lay;
  t_tv		hatch;
}		t_egg;

typedef struct	s_team
{
  char		*name;
  int		count;
  t_que		*eggs;
  struct s_team	*next;
}		t_team;

typedef struct	s_ask
{
  t_tv		wait;
  e_rsp		res;
  char		**args;
  void		(*ok)();
  void		(*changes)();
  void		(*ko)();
}		t_ask;

typedef struct	s_zap
{
  int		port;
  t_content	**map;
  int		length;
  int		width;
  int		count;
  t_team	*teams;
  int		delay;
  t_que		*end;
  t_team	*winner;
  float		asking;
  t_ask		end_game;
}		t_zap;

typedef struct	s_plr
{
  int		x;
  int		y;
  e_dir		dir;
  t_content	inv;
  t_team	*team;
  uint16_t	level;
  t_tv		time;
  t_tv		cast;
  int		ghost;
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
  void		*info;
  int		nb;
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
void		new_client(int, t_user **);
t_user		*unit_user_free(t_user *);
void		send_death(t_user **, t_user **, t_zap *);
void		check_client(t_user **, t_bf *, t_zap *);
int		manage_server(t_user **, t_zap *);
int		handle_fds(int, t_user **, t_zap *);
int		nb_client(t_user *);
t_com		*graphic_funcs();
int		count_type(t_user *, e_clt);
t_com		*ptr_to_function(e_clt);
int		read_com(t_user *, t_zap *);
void		data_free(t_user **);
void		put_team(t_team *, int);
int		team_len(t_team *);
t_team		*team_cat(t_team *, char *);
void		team_free(t_team *);
void		*clone_egg(void *);
t_team		*base_team();
void		team_counts(t_team *, int);
t_team		*team_by_name(t_team *, char *);
void		alert_graphic(char *, t_user *);
void		find_ask(t_ask *, float);
int		check_asking(t_user **, t_zap *, t_ask *);
void		*clone_ask(void *);

int		set_port(t_zap *, char *, e_state *);
int		set_x(t_zap *, char *, e_state *);
int		set_y(t_zap *, char *, e_state *);
int		set_team(t_zap *, char *, e_state *);
int		set_count(t_zap *, char *, e_state *);
int		set_delay(t_zap *, char *, e_state *);
int		set_asking(t_zap *, char *, e_state *);
t_user		*get_by_nb(t_user *, int, e_clt);
t_egg		*get_egg_by_nb(t_team *, int);
int		parse_com(char **, t_zap *);
int		base_value(t_zap *);
void		init_val(t_zap *);
void		free_zap(t_zap *);
void		send_inc_to_graph(t_user *, t_zap *);
void		cast_loop(t_user *, t_tv *, int, t_tv *);
void		send_elev_in(t_user *);

int		count_in_team(t_team *, t_user *);
int		team_winning(t_user *, t_team *);
t_user		*in_this_cell(int, int, t_user *);
void		send_to_graphic(char *, t_user *);
int		find_nb(t_user *, e_clt);
int		find_egg_nb(t_team *);
void		fill_cell(int, int, t_content **, t_zap *);
int		my_avance(char **, t_zap *, t_user *);
int		get_direction(t_user *, t_user *, t_zap *);
int		my_broadcast(char **, t_zap *, t_user *);
int		my_connect_nbr(char **, t_zap *, t_user *);
int		my_droite(char **, t_zap *, t_user *);
int		my_expulse(char **, t_zap *, t_user *);
int		my_fork(char **, t_zap *, t_user *);
int		my_gauche(char **, t_zap *, t_user *);
int		check_this_case(t_user *, t_zap *, int);
int		check_nb_in_cell(int, t_user *);
int		level_4(t_content *, t_user *, int);
int		level_5(t_content *, t_user *, int);
int		level_6(t_content *, t_user *, int);
int		level_7(t_content *, t_user *, int);
int		my_incantation(char **, t_zap *, t_user *);
int		my_inventaire(char **, t_zap *, t_user *);
t_com		*ptrs_get();
int		send_pose(t_user *, int, t_content *);
int		my_pose(char **, t_zap *, t_user *);
int		get_sibur(t_content *, uint16_t **);
int		get_mendiane(t_content *, uint16_t **);
int		get_phiras(t_content *, uint16_t **);
int		get_thystame(t_content *, uint16_t **);
int		send_prend(t_user *, int, t_content *);
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
void		my_reset(t_user *, t_zap *);
void		my_endgame(t_user *, t_zap *);
void		my_reset_map(t_user **, t_zap *, t_ask *);
int		my_other(char **, t_zap *, t_user *);

int		my_send_msz(t_zap *, t_user *);
int		my_msz(char **, t_zap *, t_user *);
int		my_bct(char **, t_zap *, t_user *);
int		my_send_bct(t_zap *, t_user *, int, int);
int		my_send_mct(t_zap *, t_user *);
int		my_mct(char **, t_zap *, t_user *);
int		my_send_tna(t_zap *, t_user *);
int		my_tna(char **, t_zap *, t_user *);
int		my_send_ppo(t_user *, t_user *);
int		my_ppo(char **, t_zap *, t_user *);
int		my_send_plv(t_user *, t_user *);
int		my_plv(char **, t_zap *, t_user *);
int		my_send_pin(t_user *, t_user *);
int		my_pin(char **, t_zap *, t_user *);
int		my_sbp(t_user *);
int		my_send_sgt(t_zap *, t_user *);
int		my_sgt(char **, t_zap *, t_user *);
int		my_sst(char **, t_zap *, t_user *);
int		my_suc(char **, t_zap *, t_user *);
int		my_pnw(t_user *, t_user *);
int		my_stn(char **, t_zap *, t_user *);
int		my_spp(char **, t_zap *, t_user *);
int		my_spi(char **, t_zap *, t_user *);
int		my_spl(char **, t_zap *, t_user *);
int		my_spk(char **, t_zap *, t_user *);
int		my_sep(char **, t_zap *, t_user *);
int		my_sek(char **, t_zap *, t_user *);
int		my_sct(char **, t_zap *, t_user *);
int		my_sms(char **, t_zap *, t_user *);
int		my_srs(char **, t_zap *, t_user *);
int		my_agt(char **, t_zap *, t_user *);
t_ask		*get_asking(t_user *, int, int);
int		my_apr(char **, t_zap *, t_user *);
int		aeg_response(t_zap *, t_user *, e_rsp);
int		my_anr(char **, t_zap *, t_user *);

#endif
