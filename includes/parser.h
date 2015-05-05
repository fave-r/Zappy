/*
** parser.h for zappy in /home/fave_r/rendu/Zappy
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  5 14:56:37 2015 romaric
** Last update Tue May  5 15:00:06 2015 romaric
*/

#ifndef	ZAPPY_H
#define	ZAPPY_H

#include "my_irc.h"

typedef struct	s_user
{
  int		fd;
  char		*ip;
  t_cb		cb;
  t_cb		wr;
  struct s_user	*next;
  struct s_user	*prev;
}		t_user;


#endif
