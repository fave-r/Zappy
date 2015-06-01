/*
** asking.c for asking in /home/lopez_t/BONUS/Zappy
** 
** Made by Thibaut Lopez
** Login   <lopez_t@epitech.net>
** 
** Started on  Thu May 28 13:49:58 2015 Thibaut Lopez
** Last update Mon Jun  1 18:32:41 2015 Thibaut Lopez
*/

#include "server.h"

int	set_asking(t_zap *data, char *arg, e_state *state)
{
  if (data->asking == -1)
    {
      if ((data->asking = my_strtof(arg)) == -1)
	fprintf(stderr, "Warning: '-a %s': wrong or negative value.\n", arg);
    }
  else
    {
      fprintf(stderr, "Error: '-a %s': redefinition of asking value.\n", arg);
      return (-1);
    }
  *state = NONE;
  return (0);
}

void		alert_graphic(char *com, t_user *usr)
{
  t_user	*cur;

  cur = usr;
  while (cur != NULL && cur->prev != NULL)
    cur = cur->prev;
  while (cur != NULL)
    {
      if (cur->type == GRAPHIC && cur != usr)
	fill_cb(&cur->wr, com, strlen(com));
      cur = cur->next;
    }
}

void		find_ask(t_ask *ask, float asking)
{
  time_t	sec;
  suseconds_t	usec;

  sec = floorf(asking);
  usec = (asking - sec) * 1000000;
  gettimeofday(&ask->wait, NULL);
  ask->wait.tv_sec += sec;
  ask->wait.tv_usec += usec;
}
