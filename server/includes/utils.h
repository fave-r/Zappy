/*
** utils.h for utils in /home/lopez_t/Zappy/includes
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 18:07:00 2015 Thibaut Lopez
** Last update Sat Jul  4 16:17:02 2015 Thibaut Lopez
*/

#ifndef	UTILS_H
#define	UTILS_H
#define ABS(nb)		(((nb) < 0) ? ((nb) * -1) : (nb))

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <sys/time.h>

typedef struct	s_com
{
  char		*com;
  int		(*ptr)();
}		t_com;

typedef struct	s_pair
{
  int		f;
  int		s;
}		t_pair;

typedef struct	timeval	t_tv;

typedef struct	s_que
{
  void		*e;
  struct s_que	*next;
}		t_que;

int		smod(int, int);
int		find_ptr(t_com *, char *);
int		my_strtol(char *);
float		my_strtof(char *);
int		my_strstr(char **, char *);
char		*my_strcat(char *, char *);
int		my_strchr(char *, char);
char		**sstrdup(char **);
void		sfree(char **);
int		sstrlen(char **);
char		**sstrcat(char **, char *);
void		putsstr(char **);
int		sstrchr(char **, char *);
char		**stwt(char *, char *, int);
int		push_q(t_que **, void *, void *(*)(void *));
void		pop_q(t_que **);
void		*front_q(t_que *);
int		q_len(t_que *);
void		*clone_tv(void *);
t_tv		*add_tv(t_tv *, int);
int		cmp_tv(t_tv *, t_tv *);

#endif
