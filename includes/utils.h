/*
** utils.h for utils in /home/lopez_t/Zappy/includes
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 18:07:00 2015 Thibaut Lopez
** Last update Mon May 18 11:38:54 2015 Thibaut Lopez
*/

#ifndef	UTILS_H
#define	UTILS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
  t_tv		e;
  struct s_que	*next;
}		t_que;

int		xopen(const char *, int);
ssize_t		xread(int, void *, size_t);
void		*xmalloc(size_t);
char		*xstrdup(const char *);
int		find_ptr(t_com *, char *);
int		my_strtol(char *);
int		my_strstr(char **, char *);
char		*my_strcat(char *, char *);
int		my_strchr(char *, char);
void		sfree(char **);
int		sstrlen(char **);
char		**sstrcat(char **, char *);
void		putsstr(int, char **);
char		**stwt(char *, char *, int);
void		push_q(t_que **, t_tv);
void		pop_q(t_que **);
t_tv		*front_q(t_que *);
t_tv		*add_tv(t_tv *, int);
int		cmp_tv(t_tv *, t_tv *);

#endif
