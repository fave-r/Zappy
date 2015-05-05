/*
** utils.h for utils in /home/lopez_t/Zappy/includes
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Tue May  5 18:07:00 2015 Thibaut Lopez
** Last update Tue May  5 18:46:11 2015 Thibaut Lopez
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

typedef struct	s_com
{
  char		*com;
  int		(*ptr)();
}		t_com;

int		xopen(const char *, int);
ssize_t		xread(int, void *, size_t);
void		*xmalloc(size_t);
char		*xstrdup(const char *);
int		find_ptr(t_com *, char *);
int		my_strtol(char *);
int		my_strstr(char **, char *);
char		*my_strcat(char *, char *);
char		**stwt(char *, char *);

#endif
